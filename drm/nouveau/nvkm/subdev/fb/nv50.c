/*
 * Copyright 2012 Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Ben Skeggs
 */
#include "nv50.h"
#include "ram.h"

#include <core/client.h>
#include <core/enum.h>
#include <engine/fifo.h>

int
nv50_fb_memtype[0x80] = {
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0,
	0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 2, 2, 2,
	1, 0, 2, 0, 1, 0, 2, 0, 1, 1, 2, 2, 1, 1, 0, 0
};

bool
nv50_fb_memtype_valid(struct nvkm_fb *fb, u32 memtype)
{
	return nv50_fb_memtype[(memtype & 0xff00) >> 8] != 0;
}

static const struct nvkm_enum vm_dispatch_subclients[] = {
	{ 0x00000000, "GRCTX" },
	{ 0x00000001, "NOTIFY" },
	{ 0x00000002, "QUERY" },
	{ 0x00000003, "COND" },
	{ 0x00000004, "M2M_IN" },
	{ 0x00000005, "M2M_OUT" },
	{ 0x00000006, "M2M_NOTIFY" },
	{}
};

static const struct nvkm_enum vm_ccache_subclients[] = {
	{ 0x00000000, "CB" },
	{ 0x00000001, "TIC" },
	{ 0x00000002, "TSC" },
	{}
};

static const struct nvkm_enum vm_prop_subclients[] = {
	{ 0x00000000, "RT0" },
	{ 0x00000001, "RT1" },
	{ 0x00000002, "RT2" },
	{ 0x00000003, "RT3" },
	{ 0x00000004, "RT4" },
	{ 0x00000005, "RT5" },
	{ 0x00000006, "RT6" },
	{ 0x00000007, "RT7" },
	{ 0x00000008, "ZETA" },
	{ 0x00000009, "LOCAL" },
	{ 0x0000000a, "GLOBAL" },
	{ 0x0000000b, "STACK" },
	{ 0x0000000c, "DST2D" },
	{}
};

static const struct nvkm_enum vm_pfifo_subclients[] = {
	{ 0x00000000, "PUSHBUF" },
	{ 0x00000001, "SEMAPHORE" },
	{}
};

static const struct nvkm_enum vm_bar_subclients[] = {
	{ 0x00000000, "FB" },
	{ 0x00000001, "IN" },
	{}
};

static const struct nvkm_enum vm_client[] = {
	{ 0x00000000, "STRMOUT" },
	{ 0x00000003, "DISPATCH", vm_dispatch_subclients },
	{ 0x00000004, "PFIFO_WRITE" },
	{ 0x00000005, "CCACHE", vm_ccache_subclients },
	{ 0x00000006, "PMSPPP" },
	{ 0x00000007, "CLIPID" },
	{ 0x00000008, "PFIFO_READ" },
	{ 0x00000009, "VFETCH" },
	{ 0x0000000a, "TEXTURE" },
	{ 0x0000000b, "PROP", vm_prop_subclients },
	{ 0x0000000c, "PVP" },
	{ 0x0000000d, "PBSP" },
	{ 0x0000000e, "PCRYPT" },
	{ 0x0000000f, "PCOUNTER" },
	{ 0x00000011, "PDAEMON" },
	{}
};

static const struct nvkm_enum vm_engine[] = {
	{ 0x00000000, "PGRAPH" },
	{ 0x00000001, "PVP" },
	{ 0x00000004, "PEEPHOLE" },
	{ 0x00000005, "PFIFO", vm_pfifo_subclients },
	{ 0x00000006, "BAR", vm_bar_subclients },
	{ 0x00000008, "PMSPPP" },
	{ 0x00000008, "PMPEG" },
	{ 0x00000009, "PBSP" },
	{ 0x0000000a, "PCRYPT" },
	{ 0x0000000b, "PCOUNTER" },
	{ 0x0000000c, "SEMAPHORE_BG" },
	{ 0x0000000d, "PCE0" },
	{ 0x0000000e, "PDAEMON" },
	{}
};

static const struct nvkm_enum vm_fault[] = {
	{ 0x00000000, "PT_NOT_PRESENT" },
	{ 0x00000001, "PT_TOO_SHORT" },
	{ 0x00000002, "PAGE_NOT_PRESENT" },
	{ 0x00000003, "PAGE_SYSTEM_ONLY" },
	{ 0x00000004, "PAGE_READ_ONLY" },
	{ 0x00000006, "NULL_DMAOBJ" },
	{ 0x00000007, "WRONG_MEMTYPE" },
	{ 0x0000000b, "VRAM_LIMIT" },
	{ 0x0000000f, "DMAOBJ_LIMIT" },
	{}
};

static void
nv50_fb_intr(struct nvkm_subdev *subdev)
{
	struct nv50_fb *fb = (void *)subdev;
	struct nvkm_device *device = fb->base.subdev.device;
	struct nvkm_fifo *fifo = device->fifo;
	struct nvkm_fifo_chan *chan;
	const struct nvkm_enum *en, *re, *cl, *sc;
	u32 trap[6], idx, inst;
	u8 st0, st1, st2, st3;
	unsigned long flags;
	int i;

	idx = nvkm_rd32(device, 0x100c90);
	if (!(idx & 0x80000000))
		return;
	idx &= 0x00ffffff;

	for (i = 0; i < 6; i++) {
		nvkm_wr32(device, 0x100c90, idx | i << 24);
		trap[i] = nvkm_rd32(device, 0x100c94);
	}
	nvkm_wr32(device, 0x100c90, idx | 0x80000000);

	/* decode status bits into something more useful */
	if (device->chipset  < 0xa3 ||
	    device->chipset == 0xaa || device->chipset == 0xac) {
		st0 = (trap[0] & 0x0000000f) >> 0;
		st1 = (trap[0] & 0x000000f0) >> 4;
		st2 = (trap[0] & 0x00000f00) >> 8;
		st3 = (trap[0] & 0x0000f000) >> 12;
	} else {
		st0 = (trap[0] & 0x000000ff) >> 0;
		st1 = (trap[0] & 0x0000ff00) >> 8;
		st2 = (trap[0] & 0x00ff0000) >> 16;
		st3 = (trap[0] & 0xff000000) >> 24;
	}
	inst = ((trap[2] << 16) | trap[1]) << 12;

	en = nvkm_enum_find(vm_engine, st0);
	re = nvkm_enum_find(vm_fault , st1);
	cl = nvkm_enum_find(vm_client, st2);
	if      (cl && cl->data) sc = nvkm_enum_find(cl->data, st3);
	else if (en && en->data) sc = nvkm_enum_find(en->data, st3);
	else                     sc = NULL;

	chan = nvkm_fifo_chan_inst(fifo, inst, &flags);
	nvkm_error(subdev, "trapped %s at %02x%04x%04x on channel "
			   "%08x [%s] engine %02x [%s] client %02x [%s] "
			   "subclient %02x [%s] reason %08x [%s]\n",
		   (trap[5] & 0x00000100) ? "read" : "write",
		   trap[5] & 0xff, trap[4] & 0xffff, trap[3] & 0xffff, inst,
		   nvkm_client_name(chan), st0, en ? en->name : "",
		   st2, cl ? cl->name : "", st3, sc ? sc->name : "",
		   st1, re ? re->name : "");
	nvkm_fifo_chan_put(fifo, flags, &chan);
}

int
nv50_fb_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
	     struct nvkm_oclass *oclass, void *data, u32 size,
	     struct nvkm_object **pobject)
{
	struct nvkm_device *device = nv_device(parent);
	struct nv50_fb *fb;
	int ret;

	ret = nvkm_fb_create(parent, engine, oclass, &fb);
	*pobject = nv_object(fb);
	if (ret)
		return ret;

	fb->r100c08_page = alloc_page(GFP_KERNEL | __GFP_ZERO);
	if (fb->r100c08_page) {
		fb->r100c08 = dma_map_page(nv_device_base(device),
					     fb->r100c08_page, 0, PAGE_SIZE,
					     DMA_BIDIRECTIONAL);
		if (dma_mapping_error(nv_device_base(device), fb->r100c08))
			return -EFAULT;
	} else {
		nvkm_warn(&fb->base.subdev, "failed 100c08 page alloc\n");
	}

	nv_subdev(fb)->intr = nv50_fb_intr;
	return 0;
}

void
nv50_fb_dtor(struct nvkm_object *object)
{
	struct nvkm_device *device = nv_device(object);
	struct nv50_fb *fb = (void *)object;

	if (fb->r100c08_page) {
		dma_unmap_page(nv_device_base(device), fb->r100c08, PAGE_SIZE,
			       DMA_BIDIRECTIONAL);
		__free_page(fb->r100c08_page);
	}

	nvkm_fb_destroy(&fb->base);
}

int
nv50_fb_init(struct nvkm_object *object)
{
	struct nv50_fb_impl *impl = (void *)object->oclass;
	struct nv50_fb *fb = (void *)object;
	struct nvkm_device *device = fb->base.subdev.device;
	int ret;

	ret = nvkm_fb_init(&fb->base);
	if (ret)
		return ret;

	/* Not a clue what this is exactly.  Without pointing it at a
	 * scratch page, VRAM->GART blits with M2MF (as in DDX DFS)
	 * cause IOMMU "read from address 0" errors (rh#561267)
	 */
	nvkm_wr32(device, 0x100c08, fb->r100c08 >> 8);

	/* This is needed to get meaningful information from 100c90
	 * on traps. No idea what these values mean exactly. */
	nvkm_wr32(device, 0x100c90, impl->trap);
	return 0;
}

struct nvkm_oclass *
nv50_fb_oclass = &(struct nv50_fb_impl) {
	.base.base.handle = NV_SUBDEV(FB, 0x50),
	.base.base.ofuncs = &(struct nvkm_ofuncs) {
		.ctor = nv50_fb_ctor,
		.dtor = nv50_fb_dtor,
		.init = nv50_fb_init,
		.fini = _nvkm_fb_fini,
	},
	.base.memtype = nv50_fb_memtype_valid,
	.base.ram_new = nv50_ram_new,
	.trap = 0x000707ff,
}.base.base;

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
#include <engine/sw.h>
#include <engine/fifo.h>

/*******************************************************************************
 * software object classes
 ******************************************************************************/

static int
nv04_sw_set_ref(struct nvkm_object *object, u32 mthd, void *data, u32 size)
{
	struct nvkm_object *channel = (void *)nv_engctx(object->parent);
	struct nvkm_fifo_chan *fifo = (void *)channel->parent;
	atomic_set(&fifo->refcnt, *(u32*)data);
	return 0;
}

static int
nv04_sw_flip(struct nvkm_object *object, u32 mthd, void *args, u32 size)
{
	struct nvkm_sw_chan *chan = (void *)nv_engctx(object->parent);
	if (chan->flip)
		return chan->flip(chan->flip_data);
	return -EINVAL;
}

static struct nvkm_omthds
nv04_sw_omthds[] = {
	{ 0x0150, 0x0150, nv04_sw_set_ref },
	{ 0x0500, 0x0500, nv04_sw_flip },
	{}
};

static struct nvkm_oclass
nv04_sw_sclass[] = {
	{ 0x006e, &nvkm_object_ofuncs, nv04_sw_omthds },
	{}
};

/*******************************************************************************
 * software context
 ******************************************************************************/

static int
nv04_sw_context_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
		     struct nvkm_oclass *oclass, void *data, u32 size,
		     struct nvkm_object **pobject)
{
	struct nvkm_sw_chan *chan;
	int ret;

	ret = nvkm_sw_context_create(parent, engine, oclass, &chan);
	*pobject = nv_object(chan);
	if (ret)
		return ret;

	return 0;
}

static struct nvkm_oclass
nv04_sw_cclass = {
	.handle = NV_ENGCTX(SW, 0x04),
	.ofuncs = &(struct nvkm_ofuncs) {
		.ctor = nv04_sw_context_ctor,
		.dtor = _nvkm_sw_context_dtor,
		.init = _nvkm_sw_context_init,
		.fini = _nvkm_sw_context_fini,
	},
};

/*******************************************************************************
 * software engine/subdev functions
 ******************************************************************************/

void
nv04_sw_intr(struct nvkm_subdev *subdev)
{
	nvkm_mask(subdev->device, 0x000100, 0x80000000, 0x00000000);
}

static int
nv04_sw_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
	     struct nvkm_oclass *oclass, void *data, u32 size,
	     struct nvkm_object **pobject)
{
	struct nvkm_sw *sw;
	int ret;

	ret = nvkm_sw_create(parent, engine, oclass, &sw);
	*pobject = nv_object(sw);
	if (ret)
		return ret;

	nv_engine(sw)->cclass = &nv04_sw_cclass;
	nv_engine(sw)->sclass = nv04_sw_sclass;
	nv_subdev(sw)->intr = nv04_sw_intr;
	return 0;
}

struct nvkm_oclass *
nv04_sw_oclass = &(struct nvkm_oclass) {
	.handle = NV_ENGINE(SW, 0x04),
	.ofuncs = &(struct nvkm_ofuncs) {
		.ctor = nv04_sw_ctor,
		.dtor = _nvkm_sw_dtor,
		.init = _nvkm_sw_init,
		.fini = _nvkm_sw_fini,
	},
};

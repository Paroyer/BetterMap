#ifndef GFX_RENDERER_H
#define GFX_RENDERER_H

#include "../IDA/types.h"
namespace cube {
	class World;
}

namespace gfx {
class Renderer {
    public:
		virtual ~Renderer();

		cube::World* world;
		__int64 field_10;
		__int64 field_18;
		__int64 field_20;
		__int64 field_28;
		__int64 field_30;
		__int64 field_38;
		__int64 field_40;
		__int64 field_48;
		__int64 field_50;
		__int64 field_58;
		__int64 field_60;
		__int64 field_68;
		__int64 field_70;
		__int64 field_78;
		__int64 field_80;
		__int64 field_88;
		__int64 field_90;
		__int64 field_98;
		__int64 field_A0;
		__int64 field_A8;
		__int64 field_B0;
		__int64 field_B8;
		__int64 field_C0;
		__int64 field_C8;
		__int64 field_D0;
		__int64 field_D8;
		__int64 field_E0;
		__int64 field_E8;
		__int64 field_F0;
		__int64 field_F8;
		__int64 field_100;
		__int64 field_108;
		__int64 field_110;
		__int64 field_118;
		__int64 field_120;
		__int64 field_128;
		__int64 field_130;
		__int64 field_138;
		__int64 field_140;
		__int64 field_148;
		__int64 field_150;
		__int64 field_158;
		__int64 field_160;
		__int64 field_168;
		__int64 field_170;
		__int64 field_178;
		__int64 field_180;
		__int64 field_188;
		__int64 field_190;
		__int64 field_198;
		__int64 field_1A0;
		__int64 field_1A8;
		__int64 field_1B0;
		__int64 field_1B8;
		__int64 field_1C0;
		__int64 field_1C8;
		__int64 field_1D0;
		__int64 field_1D8;
		__int64 field_1E0;
		__int64 field_1E8;
		__int64 field_1F0;
		__int64 field_1F8;
		__int64 field_200;
		__int64 field_208;
		__int64 field_210;
		__int64 field_218;
		__int64 field_220;
		__int64 field_228;
		__int64 field_230;
		__int64 field_238;
		__int64 field_240;
		__int64 field_248;
		__int64 field_250;
		__int64 field_258;
		__int64 field_260;
		__int64 field_268;
		__int64 field_270;
		__int64 field_278;
		__int64 field_280;
		__int64 field_288;
		__int64 field_290;
		__int64 field_298;
		__int64 field_2A0;
		__int64 field_2A8;
		__int64 field_2B0;
		__int64 field_2B8;
		__int64 field_2C0;
		__int64 field_2C8;
		__int64 field_2D0;
		__int64 field_2D8;
		__int64 field_2E0;
		__int64 field_2E8;
		__int64 field_2F0;
		__int64 field_2F8;
		__int64 field_300;
		__int64 field_308;
		__int64 field_310;
		__int64 field_318;
		__int64 field_320;
		__int64 field_328;
		__int64 field_330;
		__int64 field_338;
		__int64 field_340;
		__int64 field_348;
		__int64 field_350;
		__int64 field_358;
		__int64 field_360;
		__int64 field_368;
		__int64 field_370;
		__int64 field_378;
		__int64 field_380;
		__int64 field_388;
		__int64 field_390;
		__int64 field_398;
		__int64 field_3A0;
		__int64 field_3A8;
		__int64 field_3B0;
		__int64 field_3B8;
		__int64 field_3C0;
		__int64 field_3C8;
		__int64 field_3D0;
		__int64 field_3D8;
		__int64 field_3E0;
		__int64 field_3E8;
		__int64 field_3F0;
		__int64 field_3F8;
		__int64 field_400;
		__int64 field_408;
		__int64 field_410;
		__int64 field_418;
		__int64 field_420;
		__int64 field_428;
		__int64 field_430;
		__int64 field_438;
		__int64 field_440;
		__int64 field_448;
		__int64 field_450;
		__int64 field_458;
		__int64 field_460;
		__int64 field_468;
		__int64 field_470;
		__int64 field_478;
		__int64 field_480;
		__int64 field_488;
		__int64 field_490;
		__int64 field_498;
		__int64 field_4A0;
		__int64 field_4A8;
		__int64 field_4B0;
		__int64 field_4B8;
		__int64 field_4C0;
		__int64 field_4C8;
		__int64 field_4D0;
		__int64 field_4D8;
		__int64 field_4E0;
		__int64 field_4E8;
		__int64 field_4F0;
		__int64 field_4F8;
		__int64 field_500;
		__int64 field_508;
		__int64 field_510;
		__int64 field_518;
		__int64 field_520;
		__int64 field_528;
		__int64 field_530;
		__int32 field_538;
		__int16 field_53C;
		__int8 field_53E;
		__int8 end;
    };
}

static_assert(sizeof(gfx::Renderer) == 0x540, "gfx::Renderer is not the correct size.");

#endif // GFX_RENDERER_H

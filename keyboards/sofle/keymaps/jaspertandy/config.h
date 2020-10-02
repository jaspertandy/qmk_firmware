#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define IGNORE_MOD_TAP_INTERRUPT
#define RETRO_TAPPING
#undef PERMISSIVE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 300

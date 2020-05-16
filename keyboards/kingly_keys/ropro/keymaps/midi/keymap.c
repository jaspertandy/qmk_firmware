#include QMK_KEYBOARD_H

enum layer_number {
    _IONIAN = 0,
    _DORIAN,
    _PHRYGIAN,
    _LYDIAN,
    _MIXOLYDIAN,
    _AEOLIAN,
    _LOCRIAN,
    _CHORDS,
};

int current_layer = 0;
int max_layer = 6;

#define _______ KC_TRNS

enum custom_keys {
  RESET_LAYER = SAFE_RANGE,
  // MIDI Chord Keycodes - Major
  MI_CH_C,
  MI_CH_Cs,
  MI_CH_Db = MI_CH_Cs,
  MI_CH_D,
  MI_CH_Ds,
  MI_CH_Eb = MI_CH_Ds,
  MI_CH_E,
  MI_CH_F,
  MI_CH_Fs,
  MI_CH_Gb = MI_CH_Fs,
  MI_CH_G ,
  MI_CH_Gs,
  MI_CH_Ab = MI_CH_Gs,
  MI_CH_A,
  MI_CH_As,
  MI_CH_Bb = MI_CH_As,
  MI_CH_B,

  // MIDI Chord Keycodes Minor

  MI_CH_Cm,
  MI_CH_Csm,
  MI_CH_Dbm = MI_CH_Csm,
  MI_CH_Dm,
  MI_CH_Dsm,
  MI_CH_Ebm = MI_CH_Dsm,
  MI_CH_Em,
  MI_CH_Fm,
  MI_CH_Fsm,
  MI_CH_Gbm = MI_CH_Fsm,
  MI_CH_Gm,
  MI_CH_Gsm,
  MI_CH_Abm = MI_CH_Gsm,
  MI_CH_Am,
  MI_CH_Asm,
  MI_CH_Bbm = MI_CH_Asm,
  MI_CH_Bm,

  //MIDI Chord Keycodes Dominant Seventh

  MI_CH_CDom7,
  MI_CH_CsDom7,
  MI_CH_DbDom7 = MI_CH_CsDom7,
  MI_CH_DDom7,
  MI_CH_DsDom7,
  MI_CH_EbDom7 = MI_CH_DsDom7,
  MI_CH_EDom7,
  MI_CH_FDom7,
  MI_CH_FsDom7,
  MI_CH_GbDom7 = MI_CH_FsDom7,
  MI_CH_GDom7,
  MI_CH_GsDom7,
  MI_CH_AbDom7 = MI_CH_GsDom7,
  MI_CH_ADom7,
  MI_CH_AsDom7,
  MI_CH_BbDom7 = MI_CH_AsDom7,
  MI_CH_BDom7,

  // MIDI Chord Keycodes Diminished Seventh

  MI_CH_CDim7,
  MI_CH_CsDim7,
  MI_CH_DbDim7 = MI_CH_CsDim7,
  MI_CH_DDim7,
  MI_CH_DsDim7,
  MI_CH_EbDim7 = MI_CH_DsDim7,
  MI_CH_EDim7,
  MI_CH_FDim7,
  MI_CH_FsDim7,
  MI_CH_GbDim7 = MI_CH_FsDim7,
  MI_CH_GDim7,
  MI_CH_GsDim7,
  MI_CH_AbDim7 = MI_CH_GsDim7,
  MI_CH_ADim7,
  MI_CH_AsDim7,
  MI_CH_BbDim7 = MI_CH_AsDim7,
  MI_CH_BDim7,

};

const uint16_t ionian[]     = { MI_C , MI_D  , MI_E  , MI_F  , MI_G  , MI_A  , MI_B  , MI_C_1 , MI_D_1  , MI_E_1  , MI_F_1  , MI_G_1  , MI_A_1  , MI_B_1  , MI_C_2 , MI_D_2  , MI_E_2  , MI_F_2  , MI_G_2  , MI_A_2  , MI_B_2  , MI_C_3 , MI_D_3  , MI_E_3  , MI_F_3  , MI_G_3  , MI_A_3  , MI_B_3  , MI_C_4 , MI_D_4  , MI_E_4  , MI_F_4  , MI_G_4  , MI_A_4  , MI_B_4  , MI_C_5 , MI_D_5  , MI_E_5  };
const uint16_t dorian[]     = { MI_C , MI_D  , MI_Ds , MI_F  , MI_G  , MI_A  , MI_As , MI_C_1 , MI_D_1  , MI_Ds_1 , MI_F_1  , MI_G_1  , MI_A_1  , MI_As_1 , MI_C_2 , MI_D_2  , MI_Ds_2 , MI_F_2  , MI_G_2  , MI_A_2  , MI_As_2 , MI_C_3 , MI_D_3  , MI_Ds_3 , MI_F_3  , MI_G_3  , MI_A_3  , MI_As_3 , MI_C_4 , MI_D_4  , MI_Ds_4 , MI_F_4  , MI_G_4  , MI_A_4  , MI_As_4 , MI_C_5 , MI_D_5  , MI_Ds_5 };
const uint16_t phrygian[]   = { MI_C , MI_Cs , MI_Ds , MI_F  , MI_G  , MI_Gs , MI_As , MI_C_1 , MI_Cs_1 , MI_Ds_1 , MI_F_1  , MI_G_1  , MI_Gs_1 , MI_As_1 , MI_C_2 , MI_Cs_2 , MI_Ds_2 , MI_F_2  , MI_G_2  , MI_Gs_2 , MI_As_2 , MI_C_3 , MI_Cs_3 , MI_Ds_3 , MI_F_3  , MI_G_3  , MI_Gs_3 , MI_As_3 , MI_C_4 , MI_Cs_4 , MI_Ds_4 , MI_F_4  , MI_G_4  , MI_Gs_4 , MI_As_4 , MI_C_5 , MI_Cs_5 , MI_Ds_5 };
const uint16_t lydian[]     = { MI_C , MI_D  , MI_E  , MI_Fs , MI_G  , MI_A  , MI_B  , MI_C_1 , MI_D_1  , MI_E_1  , MI_Fs_1 , MI_G_1  , MI_A_1  , MI_B_1  , MI_C_2 , MI_D_2  , MI_E_2  , MI_Fs_2 , MI_G_2  , MI_A_2  , MI_B_2  , MI_C_3 , MI_D_3  , MI_E_3  , MI_Fs_3 , MI_G_3  , MI_A_3  , MI_B_3  , MI_C_4 , MI_D_4  , MI_E_4  , MI_Fs_4 , MI_G_4  , MI_A_4  , MI_B_4  , MI_C_5 , MI_D_5  , MI_E_5  };
const uint16_t mixolydian[] = { MI_C , MI_D  , MI_E  , MI_F  , MI_G  , MI_A  , MI_As , MI_C_1 , MI_D_1  , MI_E_1  , MI_F_1  , MI_G_1  , MI_A_1  , MI_As_1 , MI_C_2 , MI_D_2  , MI_E_2  , MI_F_2  , MI_G_2  , MI_A_2  , MI_As_2 , MI_C_3 , MI_D_3  , MI_E_3  , MI_F_3  , MI_G_3  , MI_A_3  , MI_As_3 , MI_C_4 , MI_D_4  , MI_E_4  , MI_F_4  , MI_G_4  , MI_A_4  , MI_As_4 , MI_C_5 , MI_D_5  , MI_E_5  };
const uint16_t aeolian[]    = { MI_C , MI_D  , MI_Ds , MI_F  , MI_G  , MI_Gs , MI_As , MI_C_1 , MI_D_1  , MI_Ds_1 , MI_F_1  , MI_G_1  , MI_Gs_1 , MI_As_1 , MI_C_2 , MI_D_2  , MI_Ds_2 , MI_F_2  , MI_G_2  , MI_Gs_2 , MI_As_2 , MI_C_3 , MI_D_3  , MI_Ds_3 , MI_F_3  , MI_G_3  , MI_Gs_3 , MI_As_3 , MI_C_4 , MI_D_4  , MI_Ds_4 , MI_F_4  , MI_G_4  , MI_Gs_4 , MI_As_4 , MI_C_5 , MI_D_5  , MI_Ds_5 };
const uint16_t locrian[]    = { MI_C , MI_Cs , MI_Ds , MI_F  , MI_Fs , MI_Gs , MI_As , MI_C_1 , MI_Cs_1 , MI_Ds_1 , MI_F_1  , MI_Fs_1 , MI_Gs_1 , MI_As_1 , MI_C_2 , MI_Cs_2 , MI_Ds_2 , MI_F_2  , MI_Fs_2 , MI_Gs_2 , MI_As_2 , MI_C_3 , MI_Cs_3 , MI_Ds_3 , MI_F_3  , MI_Fs_3 , MI_Gs_3 , MI_As_3 , MI_C_4 , MI_Cs_4 , MI_Ds_4 , MI_F_4  , MI_Fs_4 , MI_Gs_4 , MI_As_4 , MI_C_5 , MI_Cs_5 , MI_Ds_5 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_IONIAN] = LAYOUT(
                _______  , ionian[28] , ionian[29] , ionian[30] , ionian[31] , ionian[32] , ionian[33] , ionian[34] , ionian[35] , ionian[36] , ionian[37] , _______ ,
                _______  , ionian[21] , ionian[22] , ionian[23] , ionian[24] , ionian[25] , ionian[26] , ionian[27] , ionian[28] , ionian[29] , ionian[30] , _______ ,
  RESET_LAYER , _______  , ionian[14] , ionian[15] , ionian[16] , ionian[17] , ionian[18] , ionian[19] , ionian[20] , ionian[21] , ionian[22] , ionian[23] , _______ ,
  MI_SUS      , _______  , ionian[7]  , ionian[8]  , ionian[9]  , ionian[10] , ionian[11] , ionian[12] , ionian[13] , ionian[14] , ionian[15] , ionian[16] , _______ ,
  MI_OCTU     , MI_TRNSU , ionian[0]  , ionian[1]  , ionian[2]  , ionian[3]  , ionian[4]  , ionian[5]  , ionian[6]  , ionian[7]  , ionian[8]  , ionian[9]  , _______ ,
  MI_OCTD     , MI_TRNSD , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , TG(7)
  ),
  [_DORIAN] = LAYOUT(
            _______ , dorian[28] , dorian[29] , dorian[30] , dorian[31] , dorian[32] , dorian[33] , dorian[34] , dorian[35] , dorian[36] , dorian[37] , _______ ,
            _______ , dorian[21] , dorian[22] , dorian[23] , dorian[24] , dorian[25] , dorian[26] , dorian[27] , dorian[28] , dorian[29] , dorian[30] , _______ ,
  _______ , _______ , dorian[14] , dorian[15] , dorian[16] , dorian[17] , dorian[18] , dorian[19] , dorian[20] , dorian[21] , dorian[22] , dorian[23] , _______ ,
  _______ , _______ , dorian[7]  , dorian[8]  , dorian[9]  , dorian[10] , dorian[11] , dorian[12] , dorian[13] , dorian[14] , dorian[15] , dorian[16] , _______ ,
  _______ , _______ , dorian[0]  , dorian[1]  , dorian[2]  , dorian[3]  , dorian[4]  , dorian[5]  , dorian[6]  , dorian[7]  , dorian[8]  , dorian[9]  , _______ ,
  _______ , _______ , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______
  ),
  [_PHRYGIAN] = LAYOUT(
            _______ , phrygian[28] , phrygian[29] , phrygian[30] , phrygian[31] , phrygian[32] , phrygian[33] , phrygian[34] , phrygian[35] , phrygian[36] , phrygian[37] , _______ ,
            _______ , phrygian[21] , phrygian[22] , phrygian[23] , phrygian[24] , phrygian[25] , phrygian[26] , phrygian[27] , phrygian[28] , phrygian[29] , phrygian[30] , _______ ,
  _______ , _______ , phrygian[14] , phrygian[15] , phrygian[16] , phrygian[17] , phrygian[18] , phrygian[19] , phrygian[20] , phrygian[21] , phrygian[22] , phrygian[23] , _______ ,
  _______ , _______ , phrygian[7]  , phrygian[8]  , phrygian[9]  , phrygian[10] , phrygian[11] , phrygian[12] , phrygian[13] , phrygian[14] , phrygian[15] , phrygian[16] , _______ ,
  _______ , _______ , phrygian[0]  , phrygian[1]  , phrygian[2]  , phrygian[3]  , phrygian[4]  , phrygian[5]  , phrygian[6]  , phrygian[7]  , phrygian[8]  , phrygian[9]  , _______ ,
  _______ , _______ , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______      , _______
  ),
  [_LYDIAN] = LAYOUT(
            _______ , lydian[28] , lydian[29] , lydian[30] , lydian[31] , lydian[32] , lydian[33] , lydian[34] , lydian[35] , lydian[36] , lydian[37] , _______ ,
            _______ , lydian[21] , lydian[22] , lydian[23] , lydian[24] , lydian[25] , lydian[26] , lydian[27] , lydian[28] , lydian[29] , lydian[30] , _______ ,
  _______ , _______ , lydian[14] , lydian[15] , lydian[16] , lydian[17] , lydian[18] , lydian[19] , lydian[20] , lydian[21] , lydian[22] , lydian[23] , _______ ,
  _______ , _______ , lydian[7]  , lydian[8]  , lydian[9]  , lydian[10] , lydian[11] , lydian[12] , lydian[13] , lydian[14] , lydian[15] , lydian[16] , _______ ,
  _______ , _______ , lydian[0]  , lydian[1]  , lydian[2]  , lydian[3]  , lydian[4]  , lydian[5]  , lydian[6]  , lydian[7]  , lydian[8]  , lydian[9]  , _______ ,
  _______ , _______ , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______
  ),
  [_MIXOLYDIAN] = LAYOUT(
            _______ , mixolydian[28] , mixolydian[29] , mixolydian[30] , mixolydian[31] , mixolydian[32] , mixolydian[33] , mixolydian[34] , mixolydian[35] , mixolydian[36] , mixolydian[37] , _______ ,
            _______ , mixolydian[21] , mixolydian[22] , mixolydian[23] , mixolydian[24] , mixolydian[25] , mixolydian[26] , mixolydian[27] , mixolydian[28] , mixolydian[29] , mixolydian[30] , _______ ,
  _______ , _______ , mixolydian[14] , mixolydian[15] , mixolydian[16] , mixolydian[17] , mixolydian[18] , mixolydian[19] , mixolydian[20] , mixolydian[21] , mixolydian[22] , mixolydian[23] , _______ ,
  _______ , _______ , mixolydian[7]  , mixolydian[8]  , mixolydian[9]  , mixolydian[10] , mixolydian[11] , mixolydian[12] , mixolydian[13] , mixolydian[14] , mixolydian[15] , mixolydian[16] , _______ ,
  _______ , _______ , mixolydian[0]  , mixolydian[1]  , mixolydian[2]  , mixolydian[3]  , mixolydian[4]  , mixolydian[5]  , mixolydian[6]  , mixolydian[7]  , mixolydian[8]  , mixolydian[9]  , _______ ,
  _______ , _______ , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______        , _______
  ),
  [_AEOLIAN] = LAYOUT(
            _______ , aeolian[28] , aeolian[29] , aeolian[30] , aeolian[31] , aeolian[32] , aeolian[33] , aeolian[34] , aeolian[35] , aeolian[36] , aeolian[37] , _______ ,
            _______ , aeolian[21] , aeolian[22] , aeolian[23] , aeolian[24] , aeolian[25] , aeolian[26] , aeolian[27] , aeolian[28] , aeolian[29] , aeolian[30] , _______ ,
  _______ , _______ , aeolian[14] , aeolian[15] , aeolian[16] , aeolian[17] , aeolian[18] , aeolian[19] , aeolian[20] , aeolian[21] , aeolian[22] , aeolian[23] , _______ ,
  _______ , _______ , aeolian[7]  , aeolian[8]  , aeolian[9]  , aeolian[10] , aeolian[11] , aeolian[12] , aeolian[13] , aeolian[14] , aeolian[15] , aeolian[16] , _______ ,
  _______ , _______ , aeolian[0]  , aeolian[1]  , aeolian[2]  , aeolian[3]  , aeolian[4]  , aeolian[5]  , aeolian[6]  , aeolian[7]  , aeolian[8]  , aeolian[9]  , _______ ,
  _______ , _______ , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______
  ),
  [_LOCRIAN] = LAYOUT(
            _______ , locrian[28] , locrian[29] , locrian[30] , locrian[31] , locrian[32] , locrian[33] , locrian[34] , locrian[35] , locrian[36] , locrian[37] , _______ ,
            _______ , locrian[21] , locrian[22] , locrian[23] , locrian[24] , locrian[25] , locrian[26] , locrian[27] , locrian[28] , locrian[29] , locrian[30] , _______ ,
  _______ , _______ , locrian[14] , locrian[15] , locrian[16] , locrian[17] , locrian[18] , locrian[19] , locrian[20] , locrian[21] , locrian[22] , locrian[23] , _______ ,
  _______ , _______ , locrian[7]  , locrian[8]  , locrian[9]  , locrian[10] , locrian[11] , locrian[12] , locrian[13] , locrian[14] , locrian[15] , locrian[16] , _______ ,
  _______ , _______ , locrian[0]  , locrian[1]  , locrian[2]  , locrian[3]  , locrian[4]  , locrian[5]  , locrian[6]  , locrian[7]  , locrian[8]  , locrian[9]  , _______ ,
  _______ , _______ , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______
  ),
  [_CHORDS] = LAYOUT(
            MI_CH_CDim7 , MI_CH_CsDim7 , MI_CH_DDim7 , MI_CH_DsDim7 , MI_CH_EDim7 , MI_CH_FDim7 , MI_CH_FsDim7 , MI_CH_GDim7 , MI_CH_GsDim7 , MI_CH_ADim7 , MI_CH_AsDim7 , MI_CH_BDim7 ,
            MI_CH_CDom7 , MI_CH_CsDom7 , MI_CH_DDom7 , MI_CH_DsDom7 , MI_CH_EDom7 , MI_CH_FDom7 , MI_CH_FsDom7 , MI_CH_GDom7 , MI_CH_GsDom7 , MI_CH_ADom7 , MI_CH_AsDom7 , MI_CH_BDom7 ,
  _______ , MI_CH_Cm    , MI_CH_Csm    , MI_CH_Dm    , MI_CH_Dsm    , MI_CH_Em    , MI_CH_Fm    , MI_CH_Fsm    , MI_CH_Gm    , MI_CH_Gsm    , MI_CH_Am    , MI_CH_Asm    , MI_CH_Bm    ,
  _______ , MI_CH_C     , MI_CH_Cs     , MI_CH_D     , MI_CH_Ds     , MI_CH_E     , MI_CH_F     , MI_CH_Fs     , MI_CH_G     , MI_CH_Gs     , MI_CH_A     , MI_CH_As     , MI_CH_B     ,
  _______ , _______     , _______      , _______     , _______      , _______     , _______     , _______      , _______     , _______      , _______     , _______      , _______     ,
  _______ , _______     , _______      , _______     , _______      , _______     , _______     , _______      , _______     , _______      , _______     , _______      , _______
  ),
};

bool process_record_user (uint16_t keycode, keyrecord_t *record) {

  uint16_t root_note = MIDI_INVALID_NOTE; // Starting value for the root note of each chord

  switch(keycode) {
      case RESET_LAYER:
          current_layer = 0;
          set_single_persistent_default_layer(current_layer);
          break;
      case MI_CH_C ... MI_CH_B: // Major Chords
          root_note = keycode - MI_CH_C + MI_C;
          process_midi(root_note, record);
          process_midi(root_note + 4, record); // Major Third Note
          process_midi(root_note + 7, record); // Fifth Note
          break;

      case MI_CH_Cm ... MI_CH_Bm: // Minor Chord
          root_note = keycode - MI_CH_Cm + MI_C;
          process_midi(root_note, record);
          process_midi(root_note + 3, record); // Minor Third Note
          process_midi(root_note + 7, record); // Fifth Note
          break;

      case MI_CH_CDom7 ... MI_CH_BDom7: // Dominant 7th Chord
          root_note = keycode - MI_CH_CDom7 + MI_C;
          process_midi(root_note, record);
          process_midi(root_note + 4, record); // Major Third Note
          process_midi(root_note + 10, record); // Minor Seventh Note
          break;

      case MI_CH_CDim7 ... MI_CH_BDim7: // Diminished 7th Chord
          root_note = keycode - MI_CH_CDim7 + MI_C;
          process_midi(root_note, record);
          process_midi(root_note + 3, record); // Minor Third Note
          process_midi(root_note - 3, record); // Diminished 7th Note
          break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        current_layer++;
        if (current_layer > max_layer) {
            current_layer = 0;
        }
    } else {
        current_layer--;
        if (current_layer < 0) {
            current_layer = max_layer;
        }
    }

    set_single_persistent_default_layer(current_layer);
}


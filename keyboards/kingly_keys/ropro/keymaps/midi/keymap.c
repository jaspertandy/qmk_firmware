#include QMK_KEYBOARD_H

enum layer_number {
    _IONIAN = 0,
};

#define _______ KC_TRNS

enum custom_keys {
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

const uint16_t ionian[] = { MI_C, MI_D, MI_E, MI_F, MI_G, MI_A, MI_B, MI_C_1, MI_D_1, MI_E_1 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_IONIAN] = LAYOUT(
              MI_CH_CDim7 , MI_CH_CsDim7 , MI_CH_DDim7 , MI_CH_DsDim7 , MI_CH_EDim7 , MI_CH_FDim7 , MI_CH_FsDim7 , MI_CH_GDim7 , MI_CH_GsDim7 , MI_CH_ADim7 , MI_CH_AsDim7 , MI_CH_BDim7 ,
              MI_CH_CDom7 , MI_CH_CsDom7 , MI_CH_DDom7 , MI_CH_DsDom7 , MI_CH_EDom7 , MI_CH_FDom7 , MI_CH_FsDom7 , MI_CH_GDom7 , MI_CH_GsDom7 , MI_CH_ADom7 , MI_CH_AsDom7 , MI_CH_BDom7 ,
  _______   , MI_CH_Cm    , MI_CH_Csm    , MI_CH_Dm    , MI_CH_Dsm    , MI_CH_Em    , MI_CH_Fm    , MI_CH_Fsm    , MI_CH_Gm    , MI_CH_Gsm    , MI_CH_Am    , MI_CH_Asm    , MI_CH_Bm    ,
  MI_SUS    , MI_CH_C     , MI_CH_Cs     , MI_CH_D     , MI_CH_Ds     , MI_CH_E     , MI_CH_F     , MI_CH_Fs     , MI_CH_G     , MI_CH_Gs     , MI_CH_A     , MI_CH_As     , MI_CH_B     ,
  MI_OCTU   , MI_TRNSU    , ionian[0]    , ionian[1]   , ionian[2]    , ionian[3]   , ionian[4]   , ionian[5]    , ionian[6]   , ionian[7]    , ionian[8]   , ionian[9]    , _______     ,
  MI_OCTD   , MI_TRNSD    , _______      , _______     , _______      , _______     , _______     , _______      , _______     , _______      , _______     , _______      , _______
  )
};

bool process_record_user (uint16_t keycode, keyrecord_t *record) {

  uint16_t root_note = MIDI_INVALID_NOTE; // Starting value for the root note of each chord

  switch(keycode) {
      // MIDI Chord Keycodes

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

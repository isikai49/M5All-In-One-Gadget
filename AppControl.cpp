#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>
#include <time.h>
MdLcd mlcd;
MdWBGTMonitor mwbgt;
MdMusicPlayer mmplay;
MdMeasureDistance mmdist;
MdDateTime mdtime;
const char *g_str_orange[] = {
    COMMON_ORANGE0_IMG_PATH,
    COMMON_ORANGE1_IMG_PATH,
    COMMON_ORANGE2_IMG_PATH,
    COMMON_ORANGE3_IMG_PATH,
    COMMON_ORANGE4_IMG_PATH,
    COMMON_ORANGE5_IMG_PATH,
    COMMON_ORANGE6_IMG_PATH,
    COMMON_ORANGE7_IMG_PATH,
    COMMON_ORANGE8_IMG_PATH,
    COMMON_ORANGE9_IMG_PATH,
};
const char *g_str_blue[] = {
    COMMON_BLUE0_IMG_PATH,
    COMMON_BLUE1_IMG_PATH,
    COMMON_BLUE2_IMG_PATH,
    COMMON_BLUE3_IMG_PATH,
    COMMON_BLUE4_IMG_PATH,
    COMMON_BLUE5_IMG_PATH,
    COMMON_BLUE6_IMG_PATH,
    COMMON_BLUE7_IMG_PATH,
    COMMON_BLUE8_IMG_PATH,
    COMMON_BLUE9_IMG_PATH,
};
const char *Heart[] = {
    TRUMP_HEART1_IMG_PATH,
    TRUMP_HEART2_IMG_PATH,
    TRUMP_HEART3_IMG_PATH,
    TRUMP_HEART4_IMG_PATH,
    TRUMP_HEART5_IMG_PATH,
    TRUMP_HEART6_IMG_PATH,
    TRUMP_HEART7_IMG_PATH,
    TRUMP_HEART8_IMG_PATH,
    TRUMP_HEART9_IMG_PATH,
};
const char *Spade[] = {
    TRUMP_SPADE1_IMG_PATH,
    TRUMP_SPADE2_IMG_PATH,
    TRUMP_SPADE3_IMG_PATH,
    TRUMP_SPADE4_IMG_PATH,
    TRUMP_SPADE5_IMG_PATH,
    TRUMP_SPADE6_IMG_PATH,
    TRUMP_SPADE7_IMG_PATH,
    TRUMP_SPADE8_IMG_PATH,
    TRUMP_SPADE9_IMG_PATH,
};
void AppControl::setBtnAFlg(bool flg)
{
    m_flag_btnA_is_pressed = flg;
}
void AppControl::setBtnBFlg(bool flg)
{
    m_flag_btnB_is_pressed = flg;
}
void AppControl::setBtnCFlg(bool flg)
{
    m_flag_btnC_is_pressed = flg;
}
void AppControl::setBtnAllFlgFalse()
{
    m_flag_btnA_is_pressed = false;
    m_flag_btnB_is_pressed = false;
    m_flag_btnC_is_pressed = false;
}
State AppControl::getState()
{
    return m_state;
}
void AppControl::setState(State state)
{
    m_state = state;
}
Action AppControl::getAction()
{
    return m_action;
}
void AppControl::setAction(Action action)
{
    m_action = action;
}
void AppControl::setStateMachine(State state, Action action)
{
    setState(state);
    setAction(action);
}
FocusState AppControl::getFocusState()
{
    return m_focus_state;
}
void AppControl::setFocusState(FocusState fs)
{
    m_focus_state = fs;
}
void AppControl::displayTitleInit()
{
    mlcd.displayJpgImageCoordinate(TITLE_IMG_PATH, TITLE_X_CRD, TITLE_Y_CRD);
}
void AppControl::displayMenuInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
}
void AppControl::focusChangeImg(FocusState current_state, FocusState next_state)
{
    switch (current_state)
    {
    case MENU_WBGT:
        mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        break;

    case MENU_MUSIC:
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        break;

    case MENU_MEASURE:
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        break;

    case MENU_DATE:
        mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        break;
    }

    switch (next_state)
    {
    case MENU_WBGT:
        mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        break;

    case MENU_MUSIC:
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        break;

    case MENU_MEASURE:
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        break;

    case MENU_DATE:
        mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        break;
    }
}
void AppControl::displayWBGTInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(WBGT_TEMPERATURE_IMG_PATH, WBGT_TEMPERATURE_X_CRD, WBGT_TEMPERATURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_ORANGEDOT_IMG_PATH, WBGT_TDOT_X_CRD, WBGT_TDOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_DEGREE_IMG_PATH, WBGT_DEGREE_X_CRD, WBGT_DEGREE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_HUMIDITY_IMG_PATH, WBGT_HUMIDITY_X_CRD, WBGT_HUMIDITY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, WBGT_HDOT_X_CRD, WBGT_HDOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_PERCENT_IMG_PATH, WBGT_PERCENT_X_CRD, WBGT_PERCENT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, WBGT_BACK_X_CRD, WBGT_BACK_Y_CRD);
    displayTempHumiIndex();
}
void AppControl::displayTempHumiIndex()
{
    double t;
    double h;
    WbgtIndex index;

    mwbgt.getWBGT(&t, &h, &index);

    int temp = t * 10;
    int humi = h * 10;
    if (t >= 10)
    {
        mlcd.displayJpgImageCoordinate(g_str_orange[temp / 100], WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
    }
    else if (t < 10)
    {
        mlcd.displayJpgImageCoordinate(COMMON_ORANGEFILLWHITE_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
    }
    mlcd.displayJpgImageCoordinate(g_str_orange[(temp / 10) % 10], WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
    mlcd.displayJpgImageCoordinate(g_str_orange[temp % 10], WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);

    if (h >= 10)
    {
        mlcd.displayJpgImageCoordinate(g_str_blue[humi / 100], WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
    }
    else if (h < 10)
    {
        mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
    }
    mlcd.displayJpgImageCoordinate(g_str_blue[(humi / 10) % 10], WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
    mlcd.displayJpgImageCoordinate(g_str_blue[humi % 10], WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);

    switch (index)
    {
    case SAFE:
        mlcd.displayJpgImageCoordinate(WBGT_SAFE_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
        break;

    case ATTENTION:
        mlcd.displayJpgImageCoordinate(WBGT_ATTENTION_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
        break;
    case ALERT:
        mlcd.displayJpgImageCoordinate(WBGT_ALERT_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
        break;
    case HIGH_ALERT:
        mlcd.displayJpgImageCoordinate(WBGT_HIGH_ALERT_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
        break;
    case DANGER:
        mlcd.displayJpgImageCoordinate(WBGT_DANGER_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
        break;

    default:
        break;
    }
}
void AppControl::displayMusicInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_PLAY_X_CRD, MUSIC_PLAY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
    displayMusicTitle();
}
void AppControl::displayMusicStop()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_PLAY_X_CRD, MUSIC_PLAY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
}
void AppControl::displayMusicTitle()
{
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
}
void AppControl::displayNextMusic()
{
    mmplay.selectNextMusic();
    mlcd.displayText("                             ", MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
    displayMusicTitle();
}
void AppControl::displayMusicPlay()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWPLAYING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_STOP_IMG_PATH, MUSIC_PLAY_X_CRD, MUSIC_PLAY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_FILLWHITE_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_FILLWHITE_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
}
void AppControl::displayMeasureInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MEASURE_NOTICE_IMG_PATH, MEASURE_NOTICE_X_CRD, MEASURE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, MEASURE_DOT_X_CRD, MEASURE_DOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_CM_X_CRD, MEASURE_CM_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_BACK_X_CRD, MEASURE_BACK_Y_CRD);
    displayMeasureDistance();
}
void AppControl::displayMeasureDistance()
{
    double distance = mmdist.getDistance();
    int dis = distance * 10;

    if ((2 <= distance) && (distance <= 450))
    {
        if (distance >= 100)
        {
            mlcd.displayJpgImageCoordinate(g_str_blue[dis / 1000], MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        }
        else if (distance < 100)
        {
            mlcd.displayJpgImageCoordinate(COMMON_ORANGEFILLWHITE_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        }

        if (distance >= 10)
        {
            mlcd.displayJpgImageCoordinate(g_str_blue[(dis / 100) % 10], MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        }
        else if (distance < 10)
        {
            mlcd.displayJpgImageCoordinate(COMMON_ORANGEFILLWHITE_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        }
        mlcd.displayJpgImageCoordinate(g_str_blue[(dis / 10) % 10], MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        mlcd.displayJpgImageCoordinate(g_str_blue[dis % 10], MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
    }
}
void AppControl::displayDateInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(DATE_NOTICE_IMG_PATH, DATE_NOTICE_X_CRD, DATE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, DATE_BACK_X_CRD, DATE_BACK_Y_CRD);
}
void AppControl::displayDateUpdate()
{
    mlcd.displayDateText(mdtime.readDate(), DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD);
    mlcd.displayDateText(mdtime.readTime(), DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD);
}
HighAndLowState AppControl::getHighAndLowState()
{
    return hl_state;
}
void AppControl::setHighAndLowState(HighAndLowState state)
{
    hl_state = state;
}
void AppControl::displayHIGHANDLOWTitleInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(TRUMP_TITLE_IMG_PATH, HIGHANDLOW_TITLE_X_CRD, HIGHANDLOW_TITLE_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_START_IMG_PATH, HIGHANDLOW_START_X_CRD, HIGHANDLOW_START_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, HIGHANDLOW_BACK_X_CRD, HIGHANDLOW_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_RECORD_IMG_PATH, HIGHANDLOW_RECORD_X_CRD, HIGHANDLOW_RECORD_Y_CRD);
}
void AppControl::displayHIGHANDLOWPlayQuestion(int* trumpR)
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(Heart[*trumpR], HIGHANDLOW_L_TRUMP_X_CRD, HIGHANDLOW_L_TRUMP_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_SPADE_BACK_IMG_PATH, HIGHANDLOW_R_TRUMP_X_CRD, HIGHANDLOW_R_TRUMP_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_HIGHANDLOW_IMG_PATH, HIGHANDLOW_QUESTION_X_CRD, HIGHANDLOW_QUESTION_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_HIGH_IMG_PATH, HIGHANDLOW_START_X_CRD, HIGHANDLOW_START_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_LOW_IMG_PATH, HIGHANDLOW_RECORD_X_CRD, HIGHANDLOW_RECORD_Y_CRD);
}
void AppControl::displayHIGHANDLOWPlayRandom(int* trumpL, int* trumpR)
{
    srand((unsigned)time(NULL));

    *trumpL = rand() % 9;
    do
    {
        srand((unsigned)time(NULL));
        *trumpR = rand() % 9;
    } while ((*trumpL) == (*trumpR));
}
void AppControl::displayHIGHANDLOWPlayResult(HighAndLowState state, int* trumpL)
{
    mlcd.displayJpgImageCoordinate(Spade[*trumpL], HIGHANDLOW_R_TRUMP_X_CRD, HIGHANDLOW_R_TRUMP_Y_CRD);
    mlcd.displayDateText("                             ", HIGHANDLOW_QUESTION_X_CRD, HIGHANDLOW_QUESTION_Y_CRD);
    mlcd.displayJpgImageCoordinate(TRUMP_ONEMORE_IMG_PATH, HIGHANDLOW_START_X_CRD, HIGHANDLOW_START_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, HIGHANDLOW_BACK_X_CRD, HIGHANDLOW_BACK_Y_CRD);
    if (state==WIN)
    {
        mlcd.displayJpgImageCoordinate(TRUMP_WIN_IMG_PATH, HIGHANDLOW_WIN_X_CRD, HIGHANDLOW_WIN_Y_CRD);
    }

    else if (state==LOSE)
    {
        mlcd.displayJpgImageCoordinate(TRUMP_LOSE_IMG_PATH, HIGHANDLOW_LOSE_X_CRD, HIGHANDLOW_LOSE_Y_CRD);
    }
}
void AppControl::displayHIGHANDLOWRecord()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, HIGHANDLOW_BACK_X_CRD, HIGHANDLOW_BACK_Y_CRD);
    /*for(int i = 0; i < 10; i++)
    {

    }*/
}
void AppControl::controlApplication()
{
    static int count = 0;
    static int trumpR;
    static int trumpL;
    mmplay.init();
    while (1)
    {
        switch (getState())
        {
        case TITLE:
            switch (getAction())
            {
            case ENTRY:
                displayTitleInit();
                setStateMachine(TITLE, DO);
                break;

            case DO:
                if (m_flag_btnA_is_pressed || m_flag_btnB_is_pressed || m_flag_btnC_is_pressed)
                {
                    setStateMachine(TITLE, EXIT);
                    setBtnAllFlgFalse();
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }
            break;
        case MENU:
            switch (getAction())
            {
            case ENTRY:
                static int upcommand;
                static int downcommand;
                upcommand = 0;
                downcommand = 0;
                mlcd.clearDisplay();
                displayMenuInit();
                setFocusState(MENU_WBGT);
                setStateMachine(MENU, DO);
                break;

            case DO:

                if (m_flag_btnA_is_pressed)
                {
                    if (downcommand >= 1)
                    {
                        upcommand = 0;
                    }
                    upcommand++;
                    downcommand = 0;

                    switch (getFocusState())
                    {
                    case MENU_WBGT:
                        focusChangeImg(getFocusState(), MENU_DATE);
                        setFocusState(MENU_DATE);
                        break;

                    case MENU_MUSIC:
                        focusChangeImg(getFocusState(), MENU_WBGT);
                        setFocusState(MENU_WBGT);
                        break;

                    case MENU_MEASURE:
                        focusChangeImg(getFocusState(), MENU_MUSIC);
                        setFocusState(MENU_MUSIC);
                        break;

                    case MENU_DATE:
                        focusChangeImg(getFocusState(), MENU_MEASURE);
                        setFocusState(MENU_MEASURE);
                        break;
                    }
                    setBtnAllFlgFalse();
                }

                else if (m_flag_btnB_is_pressed)
                {
                    if ((upcommand >= 2) && (downcommand == 2))
                    {
                        setFocusState(MENU_HIGHANDLOW);
                        Serial.print("HIGHANDLOW MODE");
                    }
                    setStateMachine(MENU, EXIT);
                    setBtnAllFlgFalse();
                }

                else if (m_flag_btnC_is_pressed)
                {
                    downcommand++;
                    switch (getFocusState())
                    {
                    case MENU_WBGT:
                        focusChangeImg(getFocusState(), MENU_MUSIC);
                        setFocusState(MENU_MUSIC);
                        break;

                    case MENU_MUSIC:
                        focusChangeImg(getFocusState(), MENU_MEASURE);
                        setFocusState(MENU_MEASURE);
                        break;

                    case MENU_MEASURE:
                        focusChangeImg(getFocusState(), MENU_DATE);
                        setFocusState(MENU_DATE);
                        break;

                    case MENU_DATE:
                        focusChangeImg(getFocusState(), MENU_WBGT);
                        setFocusState(MENU_WBGT);
                        break;
                    }
                    setBtnAllFlgFalse();
                }
                break;

            case EXIT:

                switch (getFocusState())
                {
                case MENU_WBGT:
                    setStateMachine(WBGT, ENTRY);
                    break;

                case MENU_MUSIC:
                    setStateMachine(MUSIC_STOP, ENTRY);
                    break;

                case MENU_MEASURE:
                    setStateMachine(MEASURE, ENTRY);
                    break;

                case MENU_DATE:
                    setStateMachine(DATE, ENTRY);
                    break;
                case MENU_HIGHANDLOW:
                    setStateMachine(HIGHANDLOW_TITLE, ENTRY);
                    break;
                }
                break;

            default:
                break;
            }
            break;
        case WBGT:
            switch (getAction())
            {
            case ENTRY:
                mwbgt.init();
                displayWBGTInit();
                setStateMachine(WBGT, DO);
                break;

            case DO:
                displayTempHumiIndex();
                delay(100);

                if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(WBGT, EXIT);
                }

                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                setBtnAllFlgFalse();
                break;

            default:
                break;
            }
            break;
        case MUSIC_STOP:
            switch (getAction())
            {
            case ENTRY:
                displayMusicInit();
                displayMusicStop();
                setStateMachine(MUSIC_STOP, DO);
                break;

            case DO:
                if (m_flag_btnA_is_pressed || m_flag_btnB_is_pressed)
                {
                    setStateMachine(MUSIC_STOP, EXIT);
                }

                else if (m_flag_btnC_is_pressed)
                {
                    displayNextMusic();
                    setBtnAllFlgFalse();
                }
                break;

            case EXIT:
                if (m_flag_btnA_is_pressed)
                {
                    setStateMachine(MUSIC_PLAY, ENTRY);
                }

                else if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(MENU, ENTRY);
                }
                setBtnAllFlgFalse();
                break;

            default:
                break;
            }
            break;
        case MUSIC_PLAY:
            switch (getAction())
            {
            case ENTRY:
                displayMusicPlay();
                mmplay.prepareMP3();

                setStateMachine(MUSIC_PLAY, DO);
                break;

            case DO:
                if (m_flag_btnA_is_pressed || (mmplay.playMP3() == false))
                {
                    mmplay.stopMP3();
                    setStateMachine(MUSIC_PLAY, EXIT);
                }

                break;

            case EXIT:
                setBtnAllFlgFalse();
                setStateMachine(MUSIC_STOP, ENTRY);

                break;

            default:
                break;
            }
            break;
        case MEASURE:
            switch (getAction())
            {
            case ENTRY:
                displayMeasureInit();
                setStateMachine(MEASURE, DO);

                break;

            case DO:
                displayMeasureDistance();
                delay(250);
                if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(MEASURE, EXIT);
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                setBtnAllFlgFalse();
                break;

            default:
                break;
            }
            break;
        case DATE:
            switch (getAction())
            {
            case ENTRY:
                displayDateInit();
                setStateMachine(DATE, DO);
                break;

            case DO:
                if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(DATE, EXIT);
                }
                else
                {
                    displayDateUpdate();
                    delay(100);
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                setBtnAllFlgFalse();
                break;

            default:
                break;
            }
            break;
        case HIGHANDLOW_TITLE:
            switch (getAction())
            {
            case ENTRY:
                displayHIGHANDLOWTitleInit();
                setStateMachine(HIGHANDLOW_TITLE, DO);
                break;

            case DO:
                if (m_flag_btnC_is_pressed)
                {
                    setStateMachine(HIGHANDLOW_TITLE, EXIT);
                }
                else if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(HIGHANDLOW_TITLE, EXIT);
                }
                else if (m_flag_btnA_is_pressed)
                {
                    setStateMachine(HIGHANDLOW_TITLE, EXIT);
                }

                break;

            case EXIT:
                if (m_flag_btnA_is_pressed)
                {
                    setStateMachine(HIGHANDLOW_GAME, ENTRY);
                }
                else if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(MENU, ENTRY);
                }
                else if (m_flag_btnC_is_pressed)
                {
                    setStateMachine(HIGHANDLOW_RECORD, ENTRY);
                }
                setBtnAllFlgFalse();
                break;

            default:
                break;
            }
            break;
        case HIGHANDLOW_GAME:

            switch (getAction())
            {
            case ENTRY:
                setHighAndLowState(QUESTION);
                displayHIGHANDLOWPlayRandom(&trumpL, &trumpR);
                displayHIGHANDLOWPlayQuestion(&trumpR);
                setStateMachine(HIGHANDLOW_GAME, DO);
                break;

            case DO:
                switch (getHighAndLowState())
                {
                case QUESTION:
                    if (m_flag_btnA_is_pressed)
                    {
                        if (trumpR > trumpL)
                        { // 勝ち
                            setHighAndLowState(WIN);
                            setBtnAllFlgFalse();
                        }

                        if (trumpR < trumpL)
                        { // 負け
                            setHighAndLowState(LOSE);
                            setBtnAllFlgFalse();
                        }
                    }
                    else if (m_flag_btnC_is_pressed)
                    {
                        if (trumpR < trumpL)
                        { // 勝ち
                            setHighAndLowState(WIN);
                            setBtnAllFlgFalse();
                        }

                        if (trumpR > trumpL)
                        { // 負け
                            setHighAndLowState(LOSE);
                            setBtnAllFlgFalse();
                        }
                    }
                    break;

                case WIN:
                    displayHIGHANDLOWPlayResult(getHighAndLowState(), &trumpL);
                    if (m_flag_btnA_is_pressed)
                    {
                        setStateMachine(HIGHANDLOW_GAME, EXIT);
                    }
                    else if (m_flag_btnB_is_pressed)
                    {
                        setStateMachine(HIGHANDLOW_GAME, EXIT);
                    }
                    break;
                case LOSE:
                    displayHIGHANDLOWPlayResult(getHighAndLowState(), &trumpL);
                    if (m_flag_btnA_is_pressed)
                    {
                        setStateMachine(HIGHANDLOW_GAME, EXIT);
                    }
                    else if (m_flag_btnB_is_pressed)
                    {
                        setStateMachine(HIGHANDLOW_GAME, EXIT);
                    }
                    break;

                default:
                    break;
                }
                break;

            case EXIT:
                count++;
                if (m_flag_btnA_is_pressed)
                {
                    setStateMachine(HIGHANDLOW_GAME, ENTRY);
                }
                else if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(HIGHANDLOW_TITLE, ENTRY);
                }
                setBtnAllFlgFalse();
                break;

            default:
                break;
            }
            break;

        case HIGHANDLOW_RECORD:

            switch (getAction())
            {
            case ENTRY:
                displayHIGHANDLOWRecord();
                setStateMachine(HIGHANDLOW_RECORD, DO);
                break;

                if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(HIGHANDLOW_RECORD, EXIT);
                }

            case EXIT:
                if (m_flag_btnB_is_pressed)
                {
                    setStateMachine(HIGHANDLOW_TITLE, ENTRY);
                    setBtnAllFlgFalse();
                }
                break;

            default:
                break;
            }
            break;

        default:
            break;
        }
    }
}
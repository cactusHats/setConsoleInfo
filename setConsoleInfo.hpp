//----------------------------------
// 2022/09/13 �쐬�ҁF��
// �R�[���\�[���E�B���h�E�ݒ��ύX����
//----------------------------------

#include <windows.h>
#include <stdio.h>
#include <vector>

using namespace std;

enum class WIN_SIZE {
    W,
    H,
};

bool setConsolePosSize(int x_px, int y_px, int w_px, int h_px) {
    HWND hWnd = GetConsoleWindow();

    int rst = MoveWindow(hWnd, x_px, y_px, w_px, h_px, true);
    if (rst == 0) {
        printf("Configuration failed in setConsolePosSize()\n");
        return false;
    }

    return true;
}

void showScreenInfo() {
    HWND hWnd = GetDesktopWindow();

    WINDOWINFO windowInfo;
    windowInfo.cbSize = sizeof(WINDOWINFO);

    GetWindowInfo(hWnd, &windowInfo);

    printf("Screen info: w=%d, h=%d\n",
        windowInfo.rcWindow.right,
        windowInfo.rcWindow.bottom);
}

void getScreenSize(vector<int>& screenSize) {
    HWND hWnd = GetDesktopWindow();

    WINDOWINFO windowInfo;
    windowInfo.cbSize = sizeof(WINDOWINFO);

    GetWindowInfo(hWnd, &windowInfo);

    screenSize.clear();
    screenSize.push_back(windowInfo.rcWindow.right);
    screenSize.push_back(windowInfo.rcWindow.bottom);
}

bool setConsoleSixpack(int winId, int row = 2, int col = 3) {
    
    // - id���蓖�� -
    //  #0# #1# #2#
    //  #3# #4# #5#
    // -------------

    int winNum = row * col;
    bool noError = true;

    // �G���[�`�F�b�N
    if (!(0 <= winId && winId < winNum)) {
        noError = false;
    }
    if ((row < 1 || col < 1)) {
        noError = false;
    }

    // �ݒ菈��
    if (noError) {
        vector<int> scSize;
        getScreenSize(scSize);

        int itval_x = scSize[(int)WIN_SIZE::W] / col;
        int itval_y = scSize[(int)WIN_SIZE::H] / row;

        int winNo_x = winId % col;
        int winNo_y = winId / col;

        int winPos_x = itval_x * winNo_x;
        int winPos_y = itval_y * winNo_y;

        setConsolePosSize(winPos_x, winPos_y, itval_x, itval_y);
        printf("Set console info: config=(%dx%d), id=%d, (x,y)=(%d,%d), (w,h)=(%d,%d)\n", row, col, winId, winPos_x, winPos_y, itval_x, itval_y);
    }
    else {
        printf("Configuration failed in setConsoleSixpack()\n");
        return false;
    }

    return true;
}
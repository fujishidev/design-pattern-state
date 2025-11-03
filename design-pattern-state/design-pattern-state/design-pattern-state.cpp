// design-pattern-state.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "SafeFrame.h"

void sample()
{
    SafeFrame safeFrame;
    safeFrame.setClock(3);
    safeFrame.doUse();

    safeFrame.setClock(12);
    safeFrame.doUse();
    safeFrame.doAlarm();
    safeFrame.doPhone();

    safeFrame.setClock(0);
    safeFrame.doUse();
    safeFrame.doAlarm();
    safeFrame.doPhone();

}

int main()
{
    SafeFrame safeFrame;

    while (true)
    {
        std::cout << "\n=== メニュー ===\n";
        std::cout << "1: 金庫使用ボタン\n";
        std::cout << "2: 非常ベルボタン\n";
        std::cout << "3: 通常通話ボタン\n";
        std::cout << "4: サンプル実行\n";
        std::cout << "0: 終了ボタン\n";
        std::cout << "番号を入力してください: ";

        int input;
        std::cin >> input;

        // 入力エラー（数字以外）対応
        if (std::cin.fail())
        {
            std::cin.clear(); // エラー状態をクリア
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 入力バッファを破棄
            std::cout << "数値を入力してください。\n";
            continue;
        }

        if (input == 0)
        {
            std::cout << "終了します。\n";
            break;
        }

        switch (input)
        {
        case 1:
            safeFrame.doUse();
            break;
        case 2:
            safeFrame.doAlarm();
            break;
        case 3:
            safeFrame.doPhone();
            break;
        case 4:
            sample();
            break;
        default:
            std::cout << "無効な入力です。\n";
            break;
        }
    }
}

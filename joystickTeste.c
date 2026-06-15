#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

int main()
{
    JOYINFOEX joy;

    while (1)
    {
        joy.dwSize = sizeof(JOYINFOEX);
        joy.dwFlags = JOY_RETURNALL;

        if (joyGetPosEx(JOYSTICKID1, &joy) == JOYERR_NOERROR)
        {
            system("cls");

            printf("X = %lu\n", joy.dwXpos);
            printf("Y = %lu\n", joy.dwYpos);
            printf("Z = %lu\n", joy.dwZpos);
            printf("R = %lu\n", joy.dwRpos);

            printf("Buttons = %lu\n\n", joy.dwButtons);

            for (int i = 0; i < 12; i++)
            {
                if (joy.dwButtons & (1 << i))
                {
                    printf("Botao %d pressionado\n", i + 1);
                }
            }
        }

        Sleep(100);
    }

    return 0;
}

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

void initState(double* state, double v0, double angle_deg) {
    double theta_rad = angle_deg * M_PI / 180.0;  

    state[0] = 0.0;                    // x0
    state[1] = 0.0;                    // y0
    state[2] = v0 * cos(theta_rad);    // vx0
    state[3] = v0 * sin(theta_rad);    // vy0
}

void updateState(double* state, double dt, double g) {

    state[3] = state[3] - g * dt;      // vy_new = vy_old - g * dt

    state[0] = state[0] + state[2] * dt;  // x_new = x_old + vx * dt
    state[1] = state[1] + state[3] * dt;  // y_new = y_old + vy_new * dt
}

void copyState(const double* src, double* dst) {
    for (int i = 0; i < 4; ++i) {
        dst[i] = src[i];
    }
}

int main() {
    const double g = 9.81;      // 중력가속도 [m/s^2]
    const double dt = 0.01;     // 시간 간격 [s]
    const double v0 = 15.0;     // 초기 속도 [m/s]
    const double angle_deg = 75.0; // 발사 각도 [deg]

    double state[4];       // 현재 상태
    double prevState[4];   // 이전 상태 (지면 통과 시 보간용)

    initState(state, v0, angle_deg);   // 초기 조건 설정

    double time = 0.0;         // 현재 시간
    double prevTime = 0.0;     // 이전 스텝 시간
    double maxHeight = 0.0;    // 최고 높이(y의 최대값)
    double flightTime = 0.0;   // 최종 체공시간
    double rangeX = 0.0;       // 최종 수평 사거리

    maxHeight = state[1];

    while (true) {

        copyState(state, prevState);
        prevTime = time;

        updateState(state, dt, g);
        time += dt;

        if (state[1] > maxHeight) {
            maxHeight = state[1];
        }

        if (state[1] < 0.0) {

            double y1 = prevState[1];
            double y2 = state[1];
            double x1 = prevState[0];
            double x2 = state[0];
            double r = 0.0;
            if (y1 != y2) {
                r = y1 / (y1 - y2);
            }

            flightTime = prevTime + r * dt;
            rangeX = x1 + r * (x2 - x1);

            break;
        }
        if (time > 1000.0) {
            cout << "시뮬레이션 비정상 종료" << endl;
            break;
        }
    }

    cout << fixed << setprecision(4);
    cout << "체공시간 [s]           : " << flightTime << endl;
    cout << "최고 도달 높이 [m]     : " << maxHeight << endl;
    cout << "수평 사거리 [m]        : " << rangeX << endl;

    return 0;
}

#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

//#define PI 3.14159265
//#define MIN_VAL 1e-4
//#define feq(a, b) (fabs((a)-(b))<1E-2)
//
//double x[4];
//double y[4];
//
//double dist(double x1, double x2, double y1, double y2){
//    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
//}
//
////double fgcd(double a, double b){
////    if (feq(a, 0))
////        return b;
////    if (feq(b, 0))
////        return a;
////    return fgcd(b, fmod(a, b));
////}
//
//
//int main(int argc, char**args){
//
//    for(int i=1;i<=3;i++)
//        cin>>x[i]>>y[i];
//
//    double yy = (x[2]*x[2]-x[1]*x[1]+y[2]*y[2]-y[1]*y[1])*(x[3]-x[1]);
//    yy -= (x[3]*x[3]-x[1]*x[1]+y[3]*y[3]-y[1]*y[1])*(x[2]-x[1]);
//    yy /= 2*(y[2]-y[1])*(x[3]-x[1])-2*(x[2]-x[1])*(y[3]-y[1]);
//    double xx = 0.0;
//
//    if(abs(x[1]-x[2]) > MIN_VAL){
//        xx = (x[2]*x[2]-x[1]*x[1]+y[2]*y[2]-y[1]*y[1]) - 2*(y[2]-y[1])*yy;
//        xx /= 2*(x[2]-x[1]);
//    }else{
//        xx = (x[3]*x[3]-x[1]*x[1]+y[3]*y[3]-y[1]*y[1]) - 2*(y[3]-y[1])*yy;
//        xx /= 2*(x[3]-x[1]);
//    }
//
//    double r = 1.0*dist(xx, x[2], yy, y[2]);
//    double theta1 = asin(dist(x[1],x[2],y[1],y[2])/(2.0*r))*180.0/PI;
//    double theta2 = asin(dist(x[1],x[3],y[1],y[3])/(2.0*r))*180.0/PI;
//    double theta3 = asin(dist(x[2],x[3],y[2],y[3])/(2.0*r))*180.0/PI;
//
//    double t_angle = 0;
//    int n_pillars = 0;
//    for(int i=3; i<=100; i++){
//        double angle = 360.0/i;
//        if((feq(fmod(theta1,angle), 0) || feq(fmod(theta1,angle), theta1)) &&
//           (feq(fmod(theta2,angle), 0) || feq(fmod(theta2,angle), theta2)) &&
//           (feq(fmod(theta3,angle), 0) || feq(fmod(theta3,angle), theta3))){
//            n_pillars = i;
//            t_angle = angle;
//            break;
//        }
//    }
//    cout<<n_pillars * r*sin(PI*t_angle/180) * r*cos(PI*t_angle/180) / 2<<endl;
//}

using namespace std;

#define feq(a, b) (fabs((a)-(b))<1E-2)

double fgcd(double a, double b){
    if (feq(a, 0))
        return b;
    if (feq(b, 0))
        return a;
    return fgcd(b, fmod(a, b));
}

int main()
{
    double x[3], y[3], z[3], angle[3];
    for(int i = 0; i < 3; i++)
        cin>>x[i]>>y[i];
    for(int i = 0; i < 3; i++)
        z[i] = sqrt((x[i] - x[(i + 1) % 3]) * (x[i] - x[(i + 1) % 3]) + (y[i] - y[(i + 1) % 3]) * (y[i] - y[(i + 1) % 3]));
    double q = (z[0] + z[1] + z[2])/2;
    double S = sqrt(q * (q - z[0]) * (q - z[1]) * (q - z[2]));
    double r = (z[0] * z[1] * z[2])/(4 * S);

    for(int i = 0; i < 2; i++)
        angle[i] = acos(1 - z[i] * z[i]/(2 * r * r));
    angle[2] = 2 * acos(-1.0) - angle[0] - angle[1];
//	angle[0] = acos((z[1] * z[1] + z[2] * z[2] - z[0] * z[0])/(2 * z[1] * z[2]));
//	angle[1] = acos((z[0] * z[0] + z[2] * z[2] - z[1] * z[1])/(2 * z[0] * z[2]));
//	angle[2] = acos((z[1] * z[1] + z[0] * z[0] - z[2] * z[2])/(2 * z[1] * z[0]));

    double min = fgcd(angle[0], fgcd(angle[1], angle[2]));
    printf("%.6lf\n", r * r * sin(min) / 2 * (2 * acos(-1.0) / min));
}
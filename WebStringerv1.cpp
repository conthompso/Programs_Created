#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class Stringer{
public:
    friend void read_file(Stringer& s, const string file);
    friend void calculate_locations(Stringer& s);
    friend void enter_locations1(Stringer& s);
    friend void enter_locations2(Stringer& s);
    friend void enter_locations3(Stringer& s);
    friend void Zneutral_axis(Stringer& s);
    friend void Xneutral_axis(Stringer& s);
    friend void effective_areas(Stringer& s);
    friend void axial_lift(Stringer& s);
    friend void axial_drag(Stringer& s);

private:

    vector<double> area;
    vector<double> zcoord;
    vector<double> length;
    vector<double> thickness;

    vector<double> xshift;
    vector<double> zshift;
    vector<double> xloc;
    vector<double> eff_area;
    vector<int> cellconnect;
    double Lift, Drag, PitchingMoment;
    double zBar, xBar;
    int N;
};

void read_file(Stringer& s, const string file){
    ifstream in(file);
    in >> s.Lift;
    in.get();
    in >> s.Drag;
    in.get();
    in >> s.PitchingMoment;
    in.get();
    in >> s.N;


    for(int i = 0; i < s.N; i++){
        double x;
        in >> x;
        in.get();
        s.area.push_back(x);
    }
    for(int i = 0; i < s.N; i++){
        double y;
        in >> y;
        in.get();
        s.zcoord.push_back(y);
    }

//    for(int i = 0; i < s.area.size(); i++){
//        cout << s.area[i] << endl;
//        cout << s.zcoord[i] << endl << endl;
//    }

    int cellct;
    in >> cellct;
    in.get();

    for(int i = 0; i < cellct - 1; i++){
        int stringerloc1;
        in >> stringerloc1;
        s.cellconnect.push_back(stringerloc1);
        int stringerloc2;
        in >> stringerloc2;
        s.cellconnect.push_back(stringerloc2);
        in.get();
    }


//    for(int i = 0; i < cellct - 1; i++){
//        cout << cellconnectors[i][1] << " ";
//        if (cellct - 2 == i){
//            cout << endl;
//        }
//    }
//    for(int i = 0; i < cellct - 1; i++){
//        cout << cellconnectors[i][2] << " ";
//        if (cellct - 2 == i){
//            cout << endl;
//        }
//    }

    for(int i = 0; i < s.N + cellct - 1; i++){
        double z;
        in >> z;
        in.get();
        s.length.push_back(z);
    }

    for(int i = 0; i < s.N + cellct - 1; i++){
        double zz;
        in >> zz;
        in.get();
        s.thickness.push_back(zz);
    }

//    for(int i = 0; i < s.length.size(); i++){
//        cout << s.length[i] << endl;
//        cout << s.thickness[i] << endl << endl;
//    }
}

void calculate_locations(Stringer& s){
//    cout << "What stringer is the farthest horizontally on the top (this code assumes the entered stringer is on the same x coordinate as the bottom farthest) >";
//    int farthest;
//    cin >> farthest;

    int farthest = 3;

    double x = 0;
//    cout << x << endl;
    s.xloc.push_back(x);
    for(int i = 0; i < s.area.size(); i++){
        double a = sqrt(s.length[i] * s.length[i] - ((s.zcoord[i] - s.zcoord[i+1]) * (s.zcoord[i] - s.zcoord[i+1]))) + x;
        x = a;
//        cout << x << endl;
        s.xloc.push_back(x);
        if (i + 2 == farthest){
            s.xloc.push_back(x);
//            cout << x << endl;
            break;
        }
    }
    for(int i = farthest; i < s.area.size() - 1; i++){
        double b = x - sqrt(s.length[i] * s.length[i] - ((s.zcoord[i+1] - s.zcoord[i]) * (s.zcoord[i+1] - s.zcoord[i])));
        x = b;
        s.xloc.push_back(x);
//        cout << x << endl;
        if (i == s.area.size() - 3){
            x = 0;
            s.xloc.push_back(x);
//            cout << x << endl;
            break;
        }
    }
}

void enter_locations1(Stringer& s){
    double x1 = 0;
        s.xloc.push_back(x1);
    double x2 = 711.054;
        s.xloc.push_back(x2);
    double x3 = 1422.11;
        s.xloc.push_back(x3);
    double x4 = 2133.16;
        s.xloc.push_back(x4);
    double x5 = 2844.22;
        s.xloc.push_back(x5);
    double x6 = 3563.42;
        s.xloc.push_back(x6);
    double x7 = 4282.62;
        s.xloc.push_back(x7);
        s.xloc.push_back(x7);
        s.xloc.push_back(x6);
        s.xloc.push_back(x5);
        s.xloc.push_back(x4);
        s.xloc.push_back(x3);
        s.xloc.push_back(x2);
        s.xloc.push_back(x1);
//    for(int i = 0; i < s.xloc.size(); i++){
//        cout << s.xloc[i] << endl;
//    }
}


void enter_locations2(Stringer& s){
    double x1 = 0;
        s.xloc.push_back(x1);
    double x2 = 253.74;
        s.xloc.push_back(x2);
    double x3 = 507.47;
        s.xloc.push_back(x3);
    double x4 = 761.21;
        s.xloc.push_back(x4);
    double x5 = 1014.94;
        s.xloc.push_back(x5);
    double x6 = 1269.45;
        s.xloc.push_back(x6);
    double x7 = 1523.96;
        s.xloc.push_back(x7);
        s.xloc.push_back(x7);
        s.xloc.push_back(x6);
        s.xloc.push_back(x5);
        s.xloc.push_back(x4);
        s.xloc.push_back(x3);
        s.xloc.push_back(x2);
        s.xloc.push_back(x1);
//    for(int i = 0; i < s.xloc.size(); i++){
//        cout << s.xloc[i] << endl;
//    }
}

void enter_locations3(Stringer& s){
    double x1 = 0;
        s.xloc.push_back(x1);
    double x2 = 1508.76;
        s.xloc.push_back(x2);
    double x3 = 3017.52;
        s.xloc.push_back(x3);
        s.xloc.push_back(x3);
        s.xloc.push_back(x2);
        s.xloc.push_back(x1);
//    for(int i = 0; i < s.xloc.size(); i++){
//        cout << s.xloc[i] << endl;
//    }
}


void Zneutral_axis(Stringer& s){
    double totalArea = 0;
    double combinedAZ = 0;
    for(int i = 0; i < s.area.size(); i++){
        double areaZcoord = s.area[i] * s.zcoord[i];
        double x = combinedAZ + areaZcoord;
        combinedAZ = x;
    }

    for(int i = 0; i < s.area.size(); i++){
        double y = totalArea + s.area[i];
        totalArea = y;
    }
    s.zBar = combinedAZ / totalArea;
//    cout << s.zBar << endl;

    for(int i = 0; i < s.zcoord.size(); i++){
        double z = s.zcoord[i] - s.zBar;
        s.zshift.push_back(z);
        cout << z << " ";
    }
    cout << endl << endl;
}

void Xneutral_axis(Stringer& s){
    double totalArea = 0;
    double combinedAX = 0;
    for(int i = 0; i < s.area.size(); i++){
        double areaXcoord = s.area[i] * s.xloc[i];
        double x = combinedAX + areaXcoord;
        combinedAX = x;
    }

    for(int i = 0; i < s.area.size(); i++){
        double y = totalArea + s.area[i];
        totalArea = y;
    }
    s.xBar = combinedAX / totalArea;
//    cout << s.xBar << endl << endl;

    for(int i = 0; i < s.xloc.size(); i++){
        double z = s.xloc[i] - s.xBar;
        s.xshift.push_back(z);
        cout << z << " ";
    }
    cout << endl << endl;
}

//    int cellconnectors[cellct - 1][2];
//    for(int i = 0; i < cellct - 1; i++){
//        int stringer1;
//        int stringer2;
//        in >> stringer1;
//        in >> stringer2;
//        in.get();
//        cellconnectors[i][1] = stringer1;
//        cellconnectors[i][2] = stringer2;
//    }

void effective_areas(Stringer& s){
    for(int i = 0; i < s.N; i++){
        if(i == 0){
            double x;
            x = s.area[i] + (((s.length[i] * s.thickness[i])/6) * (2 + (s.zshift[i+1] / s.zshift[i]))) + (((s.length[s.N-1] * s.thickness[s.N-1])/6) * (2 + s.zshift[s.N-1] / s.zshift[i]));
            s.eff_area.push_back(x);
//            cout << s.area[i] << endl << s.length[i] << endl << s.thickness[i] << endl << s.zshift[i+1] << endl << s.zshift[i] << endl << s.length[s.N-1] << endl << s.thickness[s.N-1] << endl << s.zshift[s.N-1] << endl << s.zshift[i] << endl;
//            cout << x << endl;
        }
        else if(i == s.N-1){
            double y;
            y = s.area[s.N-1] + (((s.length[s.N-1] * s.thickness[s.N-1])/6) * (2 + (s.zshift[0] / s.zshift[s.N-1]))) + (((s.length[s.N-2] * s.thickness[s.N-2])/6) * (2 + s.zshift[s.N-2] / s.zshift[s.N-1]));
            s.eff_area.push_back(y);
//            cout << y << endl;
        }
        else {
            double z;
            z = s.area[i] + (((s.length[i] * s.thickness[i])/6) * (2 + (s.zshift[i+1] / s.zshift[i]))) + (((s.length[i-1] * s.thickness[i-1])/6) * (2 + s.zshift[i-1] / s.zshift[i]));
            s.eff_area.push_back(z);
//            cout << z << endl;
        }
    }
    for(int i = 0; i < s.cellconnect.size(); i++){
        int x1 = s.cellconnect[i];
        int x2 = s.cellconnect[i+1];
        double y1 = s.eff_area[x1-1];
        double y2 = s.eff_area[x2-1];
        s.eff_area[x1-1] = y1 + (((s.length[s.N] * s.thickness[s.N])/6) * (2 + (s.zshift[x2-1] / s.zshift[x1-1])));
        s.eff_area[x2-1] = y2 + (((s.length[s.N] * s.thickness[s.N])/6) * (2 + (s.zshift[x1-1] / s.zshift[x2-1])));
        i++;
    }
    for(int i = 0; i < s.eff_area.size(); i++){
        cout << s.eff_area[i] << " ";
    }
    cout << endl << endl;
}

void axial_lift(Stringer& s){
    double A[6][6] = {0};
    double B[6][1] = {0};

    for(int i = 0; i < s.N; i++){
        A[0][i] = abs(s.zshift[i]);
    }
    for(int i = 1; i < s.N; i++){
        A[i][i-1] = s.eff_area[i] * s.zshift[i];
        A[i][i] = s.eff_area[i-1] * -1 * s.zshift[i-1];
    }
    B[0][0] = s.Lift;


    for(int i = 0; i < s.N; i++){
        for(int j = 0; j < s.N; j++){
            cout << setw(15) << A[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < s.N; i++){
        cout << B[0][i] << "; ";
    }
}

void axial_drag(Stringer& s){
    double C[6][6] = {0};
    double D[6][1] = {0};

    for(int i = 0; i < s.N; i++){
        C[0][i] = abs(s.xshift[i]);
    }
    for(int i = 1; i < s.N; i++){
        C[i][i-1] = s.eff_area[i] * s.xshift[i];
        C[i][i] = s.eff_area[i-1] * -1 * s.xshift[i-1];
    }
    D[0][0] = s.Drag;


    for(int i = 0; i < s.N; i++){
        for(int j = 0; j < s.N; j++){
            cout << setw(15) << C[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < s.N; i++){
        cout << D[0][i] << "; ";
    }
}


int main(){
    Stringer s;

//    cout << "What file to read from? >";
    string file = "stabilizer.txt";
//    cin >> file;
//    cin.get();
    read_file(s, file);
//    calculate_locations(s);
    if(file == "wroot.txt"){
        enter_locations1(s);
    }
    if(file == "wtip.txt"){
        enter_locations2(s);
    }
    if(file == "stabilizer.txt"){
        enter_locations3(s);
    }
    Zneutral_axis(s);
    Xneutral_axis(s);
    effective_areas(s);
    axial_lift(s);
    cout << endl << endl << endl;
    axial_drag(s);

    return 0;
}

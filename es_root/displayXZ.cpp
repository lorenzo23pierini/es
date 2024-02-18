#include <TApplication.h>
#include <TArrow.h>
#include <TBox.h>
#include <TCanvas.h>
#include <TChain.h>
#include <TEllipse.h>
#include <TF1.h>
#include <TFile.h>
#include <TGeoManager.h>
#include <TGeoTrd2.h>
#include <TGeoTube.h>
#include <TGraph.h>
#include <TLine.h>
#include <TMarker.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TTree.h>
#include <TAxis.h>
#include <TGraphErrors.h>
#include <TPolyLine.h>

#include <iomanip>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>

#include "../sand-reco/include/struct.h"
#include "../sand-reco/include/utils.h"
#include "../sand-reco/include/transf.h"

using namespace std;

// https://baltig.infn.it/dune/sand-reco/-/blob/master/src/SANDEventDisplay.cpp
// Center coordinates (mm)
double sandCenter[3] = {0.0, -2384.73, 23910.0};
double sandRadius = 2000;
double sandLenghtZ = 3380;

// Base and Lenght of a barrel (mm)
double Base = 590; // Base (mm) z
double Height = 228; // Height (mm) all five layers 44*4+52
double Lenght = 4300; // Lenght (mm) x

struct centroid {
    TLorentzVector XYZ;
    TLorentzVector VarXYZ;
    vector<int> ModEntry;
};

struct barrel {
    int mBarrel; // Number of the barrel (from 0 to 23)
    vector<TLorentzVector> vBarrel;

    barrel(int mod, TLorentzVector v0, TLorentzVector v1, TLorentzVector v2, TLorentzVector v3) {
        mod = mBarrel;
        vBarrel.push_back(v0); 
        vBarrel.push_back(v1); 
        vBarrel.push_back(v2); 
        vBarrel.push_back(v3);
    }
};

// Functions

string extract_name(const string &file_name);
void createSubfolder(const string &main_folder, int i);
void SelectEntry (int &in);
void PrintInfo(cluster &it_clstr, int &n_clstr);
void FillTLVector(cluster &it_clstr, centroid &inC);
void FillModule(cluster &it_clstr, centroid &inC);
void GetModuleNumber(vector<int> &inVector, centroid &inC);
void DrawBarrel0();
void DrawSAND();

string extract_name(const string &filename) {
    size_t lastSlashPos = filename.find_last_of('/'); // Find the position of the last '/' in the path
    //size_t dotPos = filename.find_first_of(".edep.digit.Clusters.root");  // Find the position of the dot before the file extension
    size_t dotPos = filename.find_first_of('.');
    string extractedString = filename.substr(lastSlashPos + 1, dotPos - lastSlashPos - 1); // Extract the substring between the last '/' and the dot
    return extractedString;
}

void createSubfolder(const string &main_folder, int i) {
    // Create a subfolder with name "Entry_i" inside the main folder
    string subfolder_name = main_folder + "/Entry_" + to_string(i);
    mkdir(subfolder_name.c_str(), 0777);
}

void SelectEntry(int &in) {
    cout << "Select the entry number: " << endl;
    cin >> in;
}

void PrintInfo(cluster &it_clstr, int &n_clstr) {
    cout << endl << "Cluster n°" << n_clstr << endl;
    cout << " | x: " << it_clstr.x << ", y: " << it_clstr.y << ", z: " << it_clstr.z << endl;
    cout << " | sx: " << it_clstr.sx << ", sy: " << it_clstr.sy << ", sz: " << it_clstr.sz << endl;
    cout << " | varx: " << it_clstr.varx << ", vary: " << it_clstr.vary << ", varz: " << it_clstr.varz << endl;
}

void FillTLVector(cluster &it_clstr, centroid &inC) {
    inC.XYZ.SetX(it_clstr.x);
    inC.XYZ.SetY(it_clstr.y);
    inC.XYZ.SetZ(it_clstr.z);
    inC.XYZ.SetT(it_clstr.t);

    inC.VarXYZ.SetX(it_clstr.varx);
    inC.VarXYZ.SetY(it_clstr.vary);
    inC.VarXYZ.SetZ(it_clstr.varz);
    inC.VarXYZ.SetT(0.0);
}

void GetModuleNumber(vector<int> &inVector, centroid &inC) {
    cout << "\nModule numbers: " << endl;
    sort(inVector.begin(), inVector.end());
        inVector.erase(unique(inVector.begin(), inVector.end()), inVector.end());
}

void FillModule(cluster &it_clstr, centroid &inC) {
    cout << "Number of cells: " << it_clstr.cells.size() << endl;

    vector<int> ModuleVector; // For erase the repeated number of the modules

    for(auto i = 0; i < it_clstr.cells.size(); i++) {
        cout << it_clstr.cells[i].id << " ";
        ModuleVector.push_back((int)it_clstr.cells[i].id / 1e3);
    }

    GetModuleNumber(ModuleVector, inC);
    for(int input : ModuleVector) {
        inC.ModEntry.push_back(input);
        cout << input << " ";
    }

    cout << endl << endl;
}

void DrawBarrel0() {
    TLorentzVector v0(-Lenght/2, 0.0, sandCenter[2]-Base/2, 0.0); // (-2150.0, 0.0, 23615.0, 0.0) mm
    TLorentzVector v1(-Lenght/2, 0.0, sandCenter[2]+Base/2, 0.0); // (-2150.0, 0.0, 24205.0, 0.0) mm
    TLorentzVector v2(Lenght/2, 0.0, sandCenter[2]+Base/2, 0.0); // (2150.0, 0.0, 24205.0, 0.0) mm
    TLorentzVector v3(Lenght/2, 0.0, sandCenter[2]-Base/2, 0.0); // (2150.0, 0.0, 23615.0, 0.0) mm

    barrel b0(0, v0, v1, v2, v3);

    TPolyLine *polyline = new TPolyLine(5);
    polyline -> SetPoint(0, v0.X(), v0.Z());
    polyline -> SetPoint(1, v1.X(), v1.Z());
    polyline -> SetPoint(2, v2.X(), v2.Z());
    polyline -> SetPoint(3, v3.X(), v3.Z());
    polyline -> SetPoint(4, v0.X(), v0.Z());

    // Impostazione del colore della linea
    polyline->SetLineColor(kBlue);

    // Disegno della polilinea sul canvas
    polyline->Draw("AL");  // "AL" sta per "linea" e "Asse X"
}

void DrawSAND() {
    TLorentzVector v0(-Lenght/2, 0.0, sandCenter[2]-sandRadius-Height, 0.0); // al posto di Base/2 -> Height (evidentemente sandRadius è quello interno)
    TLorentzVector v1(-Lenght/2, 0.0, sandCenter[2]+sandRadius+Height, 0.0);
    TLorentzVector v2(Lenght/2, 0.0, sandCenter[2]+sandRadius+Height, 0.0);
    TLorentzVector v3(Lenght/2, 0.0, sandCenter[2]-sandRadius-Height, 0.0);

    TLorentzVector p0(-Lenght/2, 0.0, sandCenter[2]-sandRadius, 0.0);
    TLorentzVector p1(-Lenght/2, 0.0, sandCenter[2]+sandRadius, 0.0);
    TLorentzVector p2(Lenght/2, 0.0, sandCenter[2]+sandRadius, 0.0);
    TLorentzVector p3(Lenght/2, 0.0, sandCenter[2]-sandRadius, 0.0);

    TPolyLine *polyline = new TPolyLine(5);
    polyline -> SetPoint(0, v0.X(), v0.Z());
    polyline -> SetPoint(1, v1.X(), v1.Z());
    polyline -> SetPoint(2, v2.X(), v2.Z());
    polyline -> SetPoint(3, v3.X(), v3.Z());
    polyline -> SetPoint(4, v0.X(), v0.Z());

    // Impostazione del colore della linea
    polyline -> SetLineColor(kRed);

    // Disegno della polilinea sul canvas
    polyline -> Draw("AL");  // "AL" sta per "linea" e "Asse X"

    TPolyLine *polyline1 = new TPolyLine(5);
    polyline1 -> SetPoint(0, p0.X(), p0.Z());
    polyline1 -> SetPoint(1, p1.X(), p1.Z());
    polyline1 -> SetPoint(2, p2.X(), p2.Z());
    polyline1 -> SetPoint(3, p3.X(), p3.Z());
    polyline1 -> SetPoint(4, p0.X(), p0.Z());

    // Impostazione del colore della linea
    polyline1 -> SetLineColor(kRed);
    polyline1 -> SetLineStyle(2); // 2 is for dashed line

    // Disegno della polilinea sul canvas
    polyline1->Draw("AL");  // "AL" sta per "linea" e "Asse X"

    /*
    https://baltig.infn.it/dune/sand-reco/-/blob/master/src/SANDEventDisplay.cpp

    TBox *box1 = new TBox(sandCenter[2] - sandRadius, sandCenter[0] - 0.5 * sandLenghtZ, sandCenter[2] + sandRadius, sandCenter[0] + 0.5 * sandLenghtZ);
    box1->SetFillStyle(0);
    box1->SetLineColor(2);
    box1->Draw();
    */
}

TCanvas *Canvas(centroid inC, vector<int> v, string subfolder, int i) {
    TCanvas *c1 = new TCanvas(); //Così facendo ne salva uno e sovrascrive su tutti l'ultimo.
    for(auto it : v) {
        TGraphErrors *gr = new TGraphErrors();
        gr -> SetTitle(Form("Barrel module: %d", it));
        int n = (int)v.size();
        gr -> SetPoint(n, inC.XYZ.Z(), inC.XYZ.X());
        gr -> SetPointError(n, inC.VarXYZ.Z(), inC.VarXYZ.X());
        gr -> GetXaxis() -> SetTitle("Z");
        gr -> GetYaxis() -> SetTitle("X");
        gr -> Draw("*AP"); // P: print only points
    }
    c1 -> Update();
    string subfolderEntry = subfolder + "/Entry_" + to_string(i);
    TString pdfPath = TString::Format("%s/displayXY_%d.pdf", subfolderEntry.c_str(), i); 
    c1 -> SaveAs(pdfPath);
    return c1;
}

// Main

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cerr << "Usage: " << argv[0] << "<file_name>" << endl;
    }

    // Creazione della cartella
    auto file_name = argv[1];
    string folderPath = extract_name(file_name);
    mkdir(folderPath.c_str(), 0777);
    string subfolderXZ = folderPath + "/XZ";
    mkdir(subfolderXZ.c_str(), 0777);

    // Apertura del file ed estrazione del TTree
    //TFile *file = new TFile("../sand-reco/mu_pos2_1000_2.edep.digit.Clusters.root", "READ");
    TFile *file = TFile::Open(file_name, "READ");
    TTree *tree_clstr = (TTree*)file -> Get("tCluster");
    int entries_clstr = tree_clstr -> GetEntries();
    cout << entries_clstr << endl;
    vector<cluster> *clstr = nullptr; //It must be initialized, otherwise it doesn't work!
    
    centroid c;
    vector<centroid> Centroid;
    int n_clstr = 0;

    tree_clstr -> SetBranchAddress("cluster", &clstr);

    
    bool all = 0;
    if(all == 1) { // Prima parte: ALL
        TCanvas *c = new TCanvas("c", "Prova", 1000, 1000);
        TGraphErrors *gr = new TGraphErrors("gr", "All Entry");

        for(int i = 0; i < entries_clstr; i++) {
            tree_clstr -> GetEntry(i); // Fill the vector clstr too
            cout << "Entry " << i << ":" << endl;
            cout << "Cluster size: " << clstr -> size() << endl;

            for(auto &it_clstr : *clstr) { // Now we can do operation with our filled vector<cluster>
                n_clstr ++;
                PrintInfo(it_clstr, n_clstr);

                int n = gr -> GetN();
                gr -> SetPoint(n, it_clstr.x, it_clstr.z);
                gr -> SetPoint(n+1, 0.0, 23910.00);
                gr -> SetPointError(n, it_clstr.varx, it_clstr.varz);
                gr -> GetXaxis() -> SetTitle("X");
                gr -> GetYaxis() -> SetTitle("Z");
                //gr -> GetXaxis() -> SetRangeUser(-200, 200);
                //gr -> GetYaxis() -> SetRangeUser(20000, 30000);
                gr -> GetXaxis() -> SetTickLength(0.03);
                gr -> GetYaxis() -> SetTickLength(0.03);
                gr -> GetXaxis() -> SetLabelSize(0.02);
                gr -> GetYaxis() -> SetLabelSize(0.02);
            }
        }
        gr -> Draw("*AP");
    
        TGraph *pointGraph = new TGraph(); // Function maybe
        pointGraph -> SetPoint(0, 0.0, 23910.00);
        pointGraph -> SetMarkerStyle(20);  
        pointGraph -> SetMarkerSize(1.5);
        pointGraph -> SetMarkerColor(kRed);
        pointGraph -> Draw("P same");

        DrawSAND();

        DrawBarrel0();

        //c -> SetGridx();
        //c -> SetGridy();
        c -> Update(); // DrawFrame() display.cpp
        c -> Print("displayXZ.pdf");
    }

    else if(all == 0) { // Seconda parte: Select i
        int START = 0;
        while(1) {
            // Select the number of the Entry
            int i = 0;
            SelectEntry(i);
            createSubfolder(subfolderXZ, i);

            // Get the Entry i from the TTree
            tree_clstr -> GetEntry(i); // Fill the vector clstr too
            cout << "Entry " << i << ":" << endl;
            cout << "Cluster size: " << clstr -> size () << endl;

            for(auto &it_clstr : *clstr) {
                n_clstr ++;
                cout << endl << "Cluster n° " << n_clstr << endl;

                PrintInfo(it_clstr, n_clstr);

                FillTLVector(it_clstr, c);

                FillModule(it_clstr, c);

                Centroid.push_back(c);
            }

            // To identify the modules to display
            //cout << "To check: " << endl;
            for(auto it_c : Centroid) {  // We are in vector of centroid called 'Centroid'
                // Check for the correct XZ
                //cout << "XYZ: " << it_c.XYZ.X() << " " << it_c.XYZ.Y() << " " << it_c.XYZ.Z() << endl;
                //cout << "Polar: " << it_c.XYZ.P() << " " << it_c.XYZ.Theta()*180/TMath::Pi() << " " << it_c.XYZ.Phi()*180/TMath::Pi() << endl << endl; 
                //cout << it_c.VarXYZ.X() << " " << it_c.VarXYZ.Y() << " " << it_c.VarXYZ.Z() << endl; 

                //To verify if P() is the correct mag
                //double x = it_c.XYZ.X();
                //double y = it_c.XYZ.Y();
                //double z = it_c.XYZ.Z();

                //double R = sqrt(x*x + y*y + z*z);
                
                //cout << R << endl << endl;
                //if(R==it_c.XYZ.P())
                    //cout << "OK" << endl << endl;
                
                // Print the canvas
                //TCanvas *Barrel = Canvas(it_c, it_c.ModEntry, subfolderXZ, i);
            }

            //cout << Centroid.size() << endl << endl;
            Centroid.clear();

            // Command to stop or continue the 'while' loop
            cout << "Do you want print another display xz? (If you want digit 1, otherwise digit 0)" << endl;
            cin >> START;
            if(START == 0) break;
            else continue;
        }
    }
}
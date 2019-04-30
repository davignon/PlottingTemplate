// Drawing template (originally used for TRG-17-001)
// Author: O. Davignon (CERN)
#include <TCanvas.h>
#include <TF1.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TPaveText.h>
#include <TMarker.h>
#include <TLine.h>
#include <TAxis.h>
#include <TROOT.h>
#include <TStyle.h>

TCanvas* CreateCanvas(TString CanvasName = "myPlot", bool LogY = false)
{
  TCanvas* c = new TCanvas(CanvasName.Data(),CanvasName.Data(),800,800);
  c->SetLeftMargin(0.11);
  c->SetGrid();
  if(LogY)
    {
      c->SetLogy();
    }
  return c;
}

void DrawPrelimLabel(TCanvas* c)
{
  c->cd();

  TLatex tex;
  tex.SetTextSize(0.03);
  tex.DrawLatexNDC(0.11,0.91,"#scale[1.5]{CMS}");
  tex.Draw("same");

  return;
}

void DrawLumiLabel(TCanvas* c, TString Lumi = "35.9")
{
  c->cd();

  TLatex tex;
  tex.SetTextSize(0.035);
  TString toDisplay = Lumi + " fb^{-1} (13 TeV)";
  tex.DrawLatexNDC(0.69,0.91,toDisplay.Data());
  tex.Draw("same");

  return;
}

void SaveCanvas(TCanvas* c, TString PlotName = "myPlotName")
{
  c->cd();
  c->SaveAs(PlotName + ".pdf");
  c->SaveAs(PlotName + ".root");

  return;
}

/*****************************************************************************
*
* Copyright (c) 2000 - 2010, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef QVISLINESAMPLERWINDOW_H
#define QVISLINESAMPLERWINDOW_H

#include <QvisOperatorWindow.h>
#include <AttributeSubject.h>

class LineSamplerAttributes;
class QLabel;
class QCheckBox;
class QLineEdit;
class QSpinBox;
class QVBox;
class QButtonGroup;
class QvisColorTableButton;
class QvisOpacitySlider;
class QvisColorButton;
class QvisLineStyleWidget;
class QvisLineWidthWidget;
class QvisVariableButton;

// ****************************************************************************
// Class: QvisLineSamplerWindow
//
// Purpose:
//    Defines QvisLineSamplerWindow class.
//
// Notes:      Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class QvisLineSamplerWindow : public QvisOperatorWindow
{
    Q_OBJECT
  public:
    QvisLineSamplerWindow(const int type,
                         LineSamplerAttributes *subj,
                         const QString &caption = QString::null,
                         const QString &shortName = QString::null,
                         QvisNotepadArea *notepad = 0);
    virtual ~QvisLineSamplerWindow();
    virtual void CreateWindowContents();
  protected:
    void UpdateWindow(bool doAll);
    virtual void GetCurrentValues(int which_widget);
  private slots:
    void beamTypeChanged(int val);
    void beamShapeChanged(int val);
    void radiusProcessText();
    void divergenceProcessText();
    void nBeamsProcessText();
    void sampleDistanceProcessText();
    void sampleArcProcessText();
    void spacingProcessText();
    void angleProcessText();
    void originProcessText();
    void beamAxisChanged(int val);
    void poloialAngleProcessText();
    void poloialTiltProcessText();
    void toroialAngleProcessText();
    void viewDimensionChanged(int val);
  private:
    QWidget      *beamType;
    QButtonGroup *beamTypeButtonGroup;
    QWidget      *beamShape;
    QButtonGroup *beamShapeButtonGroup;
    QLineEdit *radius;
    QLineEdit *divergence;
    QLineEdit *nBeams;
    QLineEdit *sampleDistance;
    QLineEdit *sampleArc;
    QLineEdit *spacing;
    QLineEdit *angle;
    QLineEdit *origin;
    QWidget      *beamAxis;
    QButtonGroup *beamAxisButtonGroup;
    QLineEdit *poloialAngle;
    QLineEdit *poloialTilt;
    QLineEdit *toroialAngle;
    QWidget      *viewDimension;
    QButtonGroup *viewDimensionButtonGroup;
    QLabel *beamTypeLabel;
    QLabel *beamShapeLabel;
    QLabel *radiusLabel;
    QLabel *divergenceLabel;
    QLabel *nBeamsLabel;
    QLabel *sampleDistanceLabel;
    QLabel *sampleArcLabel;
    QLabel *spacingLabel;
    QLabel *angleLabel;
    QLabel *originLabel;
    QLabel *beamAxisLabel;
    QLabel *poloialAngleLabel;
    QLabel *poloialTiltLabel;
    QLabel *toroialAngleLabel;
    QLabel *viewDimensionLabel;

    LineSamplerAttributes *atts;
};



#endif

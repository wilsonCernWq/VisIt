/*****************************************************************************
*
* Copyright (c) 2000 - 2019, Lawrence Livermore National Security, LLC
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

#include "QvisAMRStitchCellWindow.h"

#include <AMRStitchCellAttributes.h>

#include <QLabel>
#include <QLayout>
#include <QButtonGroup>
#include <QRadioButton>


// ****************************************************************************
// Method: QvisAMRStitchCellWindow::QvisAMRStitchCellWindow
//
// Purpose: 
//   Constructor
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

QvisAMRStitchCellWindow::QvisAMRStitchCellWindow(const int type,
                         AMRStitchCellAttributes *subj,
                         const QString &caption,
                         const QString &shortName,
                         QvisNotepadArea *notepad)
    : QvisOperatorWindow(type,subj, caption, shortName, notepad)
{
    atts = subj;
}


// ****************************************************************************
// Method: QvisAMRStitchCellWindow::~QvisAMRStitchCellWindow
//
// Purpose: 
//   Destructor
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

QvisAMRStitchCellWindow::~QvisAMRStitchCellWindow()
{
}


// ****************************************************************************
// Method: QvisAMRStitchCellWindow::CreateWindowContents
//
// Purpose: 
//   Creates the widgets for the window.
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
QvisAMRStitchCellWindow::CreateWindowContents()
{
    QGridLayout *mainLayout = new QGridLayout(0);
    topLayout->addLayout(mainLayout);

    CreateCellsOfTypeLabel = new QLabel(tr("Create cells of type"), central);
    mainLayout->addWidget(CreateCellsOfTypeLabel,0,0);
    CreateCellsOfType = new QWidget(central);
    CreateCellsOfTypeButtonGroup= new QButtonGroup(CreateCellsOfType);
    QHBoxLayout *CreateCellsOfTypeLayout = new QHBoxLayout(CreateCellsOfType);
    CreateCellsOfTypeLayout->setMargin(0);
    CreateCellsOfTypeLayout->setSpacing(10);
    QRadioButton *CreateCellsOfTypeCreateTypeDualGridAndStitchCells = new QRadioButton(tr("DualGridAndStitchCells"), CreateCellsOfType);
    CreateCellsOfTypeButtonGroup->addButton(CreateCellsOfTypeCreateTypeDualGridAndStitchCells,0);
    CreateCellsOfTypeLayout->addWidget(CreateCellsOfTypeCreateTypeDualGridAndStitchCells);
    QRadioButton *CreateCellsOfTypeCreateTypeDualGrid = new QRadioButton(tr("DualGrid"), CreateCellsOfType);
    CreateCellsOfTypeButtonGroup->addButton(CreateCellsOfTypeCreateTypeDualGrid,1);
    CreateCellsOfTypeLayout->addWidget(CreateCellsOfTypeCreateTypeDualGrid);
    QRadioButton *CreateCellsOfTypeCreateTypeStitchCells = new QRadioButton(tr("StitchCells"), CreateCellsOfType);
    CreateCellsOfTypeButtonGroup->addButton(CreateCellsOfTypeCreateTypeStitchCells,2);
    CreateCellsOfTypeLayout->addWidget(CreateCellsOfTypeCreateTypeStitchCells);
    connect(CreateCellsOfTypeButtonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(CreateCellsOfTypeChanged(int)));
    mainLayout->addWidget(CreateCellsOfType, 0,1);

}


// ****************************************************************************
// Method: QvisAMRStitchCellWindow::UpdateWindow
//
// Purpose: 
//   Updates the widgets in the window when the subject changes.
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
QvisAMRStitchCellWindow::UpdateWindow(bool doAll)
{

    for(int i = 0; i < atts->NumAttributes(); ++i)
    {
        if(!doAll)
        {
            if(!atts->IsSelected(i))
            {
                continue;
            }
        }

        switch(i)
        {
          case AMRStitchCellAttributes::ID_CreateCellsOfType:
            CreateCellsOfTypeButtonGroup->blockSignals(true);
            if(CreateCellsOfTypeButtonGroup->button((int)atts->GetCreateCellsOfType()) != 0)
                CreateCellsOfTypeButtonGroup->button((int)atts->GetCreateCellsOfType())->setChecked(true);
            CreateCellsOfTypeButtonGroup->blockSignals(false);
            break;
        }
    }
}


// ****************************************************************************
// Method: QvisAMRStitchCellWindow::GetCurrentValues
//
// Purpose: 
//   Gets values from certain widgets and stores them in the subject.
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
QvisAMRStitchCellWindow::GetCurrentValues(int which_widget)
{
}


//
// Qt Slot functions
//


void
QvisAMRStitchCellWindow::CreateCellsOfTypeChanged(int val)
{
    if(val != atts->GetCreateCellsOfType())
    {
        atts->SetCreateCellsOfType(AMRStitchCellAttributes::CreateType(val));
        SetUpdate(false);
        Apply();
    }
}



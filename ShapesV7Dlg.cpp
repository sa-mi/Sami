
// ShapesV7Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ShapesV7.h"
#include "ShapesV7Dlg.h"
#include "afxdialogex.h"
#include "iShapes-1.h"

#include <sstream>
using namespace std; 


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapesV7Dlg dialog



CShapesV7Dlg::CShapesV7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPESV7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapesV7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapesV7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT2, &CShapesV7Dlg::OnEnChangeEdit2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CShapesV7Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &CShapesV7Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CShapesV7Dlg message handlers

BOOL CShapesV7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	pCombo->InsertString(0, _T("Square"));
	pCombo->InsertString(1, _T("Cube"));
	pCombo->InsertString(2, _T("Rectangle"));
	pCombo->InsertString(3, _T("Box"));
	pCombo->InsertString(4, _T("Triangle"));
	pCombo->InsertString(5, _T("Circle"));
	pCombo->InsertString(6, _T("Prism"));
	pCombo->InsertString(7, _T("Cylinder"));
	pCombo->SetCurSel(0); // or -1 for unselected

	CEdit* sidetxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5)); //getting the object to add functionality
	sidetxt->ShowWindow(SW_SHOW);//showing the text box

	//
	// Picture control setup
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC3));
	pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture->SetBitmap(hb);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapesV7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShapesV7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapesV7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShapesV7Dlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}




void CShapesV7Dlg::OnCbnSelchangeCombo1()
{
	//creating objjects
	CEdit* heighttxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3)); //getting the object to add functionality
	CEdit* lengthtxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1)); //getting the object to add functionality
	CEdit* widthtxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2)); //getting the object to add functionality
	CEdit* radiustxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT6)); //getting the object to add functionality
	CEdit* sidetxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5)); //getting the object to add functionality
	CEdit* resulttxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4)); //getting the object to add functionality

	//object for the picture
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC3));
	//image object for a square
	HBITMAP squaree = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	//image object for a cube
	HBITMAP cube = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	//image object for a rectangle
	HBITMAP rect = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	//image object for a box
	HBITMAP box = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	//image object for a triangle
	HBITMAP tri = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	//image object for a circle
	HBITMAP circ = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP6), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	//image object for a circle
	HBITMAP pris = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP7), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	//image object for a circle
	HBITMAP cyl = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP8), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);

	

	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	int n = pCombo->GetCurSel(); // 0 for first item...
	switch (n)
	{
	  case 0: //its a square
		  resulttxt->SetWindowTextW(_T(""));
		  heighttxt->ShowWindow(SW_HIDE);
		  lengthtxt->ShowWindow(SW_HIDE);
		  widthtxt->ShowWindow(SW_HIDE);
		  radiustxt->ShowWindow(SW_HIDE);
		  sidetxt->ShowWindow(SW_SHOW);//showing the text box
		  pPicture->SetBitmap(squaree);
		 
		  
		break;
		 case 1: //cube
			 resulttxt->SetWindowTextW(_T(""));
			 heighttxt->ShowWindow(SW_HIDE);
			 lengthtxt->ShowWindow(SW_HIDE);
			 widthtxt->ShowWindow(SW_HIDE);
			 radiustxt->ShowWindow(SW_HIDE);
			 sidetxt->ShowWindow(SW_SHOW);

			 
			 pPicture->SetBitmap(cube);
		break;
		case 2: //rectagle
			resulttxt->SetWindowTextW(_T(""));
			heighttxt->ShowWindow(SW_HIDE);
			lengthtxt->ShowWindow(SW_SHOW);
			widthtxt->ShowWindow(SW_SHOW);
			radiustxt->ShowWindow(SW_HIDE);
			sidetxt->ShowWindow(SW_HIDE);

			//setting the image
			pPicture->SetBitmap(rect);
		  break;
		case 3: //box
			resulttxt->SetWindowTextW(_T(""));
			heighttxt->ShowWindow(SW_SHOW);
			lengthtxt->ShowWindow(SW_SHOW);
			widthtxt->ShowWindow(SW_SHOW);
			radiustxt->ShowWindow(SW_HIDE);
			sidetxt->ShowWindow(SW_HIDE);

			pPicture->SetBitmap(box);
		  break;
	    case 4: //triangle
			resulttxt->SetWindowTextW(_T(""));
			heighttxt->ShowWindow(SW_HIDE);
			lengthtxt->ShowWindow(SW_HIDE);
			widthtxt->ShowWindow(SW_HIDE);
			radiustxt->ShowWindow(SW_HIDE);
			sidetxt->ShowWindow(SW_SHOW);//showing the text box

			//setting the image
			pPicture->SetBitmap(tri);

		  break;
        case 5: //circle
			resulttxt->SetWindowTextW(_T(""));
			heighttxt->ShowWindow(SW_HIDE);
			lengthtxt->ShowWindow(SW_HIDE);
			widthtxt->ShowWindow(SW_HIDE);
			radiustxt->ShowWindow(SW_SHOW);
			sidetxt->ShowWindow(SW_HIDE);

			//setting the image
			pPicture->SetBitmap(circ);
		  break;
		   case 6: //prism
			   resulttxt->SetWindowTextW(_T(""));
			   heighttxt->ShowWindow(SW_SHOW);
			   lengthtxt->ShowWindow(SW_HIDE);
			   widthtxt->ShowWindow(SW_HIDE);
			   radiustxt->ShowWindow(SW_HIDE);
			   sidetxt->ShowWindow(SW_SHOW);//showing the text box

			   //setting the image
			   pPicture->SetBitmap(pris);

		  break;
	  default: //cylinder
		  resulttxt->SetWindowTextW(_T(""));
		  heighttxt->ShowWindow(SW_SHOW);
		  lengthtxt->ShowWindow(SW_HIDE);
		  widthtxt->ShowWindow(SW_HIDE);
		  radiustxt->ShowWindow(SW_SHOW);
		  sidetxt->ShowWindow(SW_HIDE);

		  //setting the image
		  pPicture->SetBitmap(cyl);
		  break;
	 
	}
}


void CShapesV7Dlg::OnBnClickedOk()
{
	//variable for calculations
	string sSide, sLenght, sHeight, sRadius, sWidth;

	// variables for the data
	CString mSide; // a blank MFC string for use below
	CString mHeight; // a blank MFC string for use below
	CString mLength; // a blank MFC string for use below
	CString mWidth; // a blank MFC string for use below
	CString mRadius; // a blank MFC string for use below

	//creating objjects
	CEdit* heighttxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3)); //getting the object to access its content
	CEdit* lengthtxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1)); //getting the object to access its content
	CEdit* widthtxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2)); //getting the object to access its content
	CEdit* radiustxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT6)); //getting the object to access its content
	CEdit* sidetxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5)); //getting the object to access its content
	CEdit* resulttxt = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4)); //getting the object to access its content

	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	int n = pCombo->GetCurSel(); // 0 for first item...
	//variables for the different objects and a vector of tokes
	vector<string> tokenss;
	Square* aSquare;
	Cube* aCube;
	Rectanglee* aRect;
	Box* aBox;
	Triangle* aTrig;
	Circle* aCircle;
	Prism* aPrism;
	Cylinder* aCyl;
	//for output to the txtbox
	ostringstream sout;
	switch (n)
	{
	case 0: //its a square
		sidetxt->GetWindowText(mSide); // copy Edit Control's text into the MFC string
		tokenss.push_back("SQUARE");
		sSide = CStringA(mSide);
		tokenss.push_back(sSide);
		aSquare = new Square(tokenss);
		aSquare->output(sout);
		resulttxt->SetWindowTextW(CString(sout.str().c_str()));
		break;
	case 1: //cube
		sidetxt->GetWindowText(mSide); // copy Edit Control's text into the MFC string
		tokenss.push_back("CUBE");
		sSide = CStringA(mSide);
		tokenss.push_back(sSide);
		aCube = new Cube(tokenss);
		aCube->output(sout);
		resulttxt->SetWindowTextW(CString(sout.str().c_str()));
		break;
	case 2: //rectagle
		lengthtxt->GetWindowText(mLength); // copy Edit Control's text into the MFC string
		widthtxt->GetWindowText(mWidth); // copy Edit Control's text into the MFC string
		tokenss.push_back("RECTANGLE");
		sLenght = CStringA(mLength);
		sWidth = CStringA(mWidth);
		tokenss.push_back(sLenght);
		tokenss.push_back(sWidth);
		aRect = new Rectanglee(tokenss);
		aRect->output(sout);
		resulttxt->SetWindowTextW(CString(sout.str().c_str()));
		break;
	case 3: //box
		heighttxt->GetWindowText(mHeight); // copy Edit Control's text into the MFC string
		lengthtxt->GetWindowText(mLength); // copy Edit Control's text into the MFC string
		widthtxt->GetWindowText(mWidth); // copy Edit Control's text into the MFC string
		tokenss.push_back("BOX");
		sLenght = CStringA(mLength);
		sWidth = CStringA(mWidth);
		sHeight = CStringA(mHeight);
		tokenss.push_back(sLenght);
		tokenss.push_back(sWidth);
		tokenss.push_back(sHeight);
		aBox = new Box(tokenss);
		aBox->output(sout);
		resulttxt->SetWindowTextW(CString(sout.str().c_str()));
		break;
	case 4: //triangle
		sidetxt->GetWindowText(mSide); // copy Edit Control's text into the MFC string
		tokenss.push_back("TRIANGLE");
		sSide = CStringA(mSide);
		tokenss.push_back(sSide);
		aTrig = new Triangle(tokenss);
		aTrig->output(sout);
		resulttxt->SetWindowTextW(CString(sout.str().c_str()));

		break;
	case 5: //circle
		radiustxt->GetWindowText(mRadius); // copy Edit Control's text into the MFC string
		tokenss.push_back("CIRLCE");
		sRadius = CStringA(mRadius);
		tokenss.push_back(sRadius);
		aCircle = new Circle(tokenss);
		aCircle->output(sout);
		resulttxt->SetWindowTextW(CString(sout.str().c_str()));
		break;
	case 6: //prism
		heighttxt->GetWindowText(mHeight); // copy Edit Control's text into the MFC string
		sidetxt->GetWindowText(mSide); // copy Edit Control's text into the MFC string
		tokenss.push_back("PRISM");
		sSide = CStringA(mSide);
		sHeight = CStringA(mHeight);
		tokenss.push_back(sSide);
		tokenss.push_back(sHeight);
		aPrism = new Prism(tokenss);
		aPrism->output(sout);
		resulttxt->SetWindowTextW(CString(sout.str().c_str()));

		break;
	default: //cylinder
		heighttxt->GetWindowText(mHeight); // copy Edit Control's text into the MFC string
		radiustxt->GetWindowText(mRadius); // copy Edit Control's text into the MFC string
		tokenss.push_back("CYLINDER");
		sRadius = CStringA(mRadius);
		sHeight = CStringA(mHeight);
		tokenss.push_back(sRadius);
		tokenss.push_back(sHeight);
		aCyl = new Cylinder(tokenss);
		aCyl->output(sout);
		resulttxt->SetWindowTextW(CString(sout.str().c_str()));

		break;

	}


	//CDialogEx::OnOK();
}

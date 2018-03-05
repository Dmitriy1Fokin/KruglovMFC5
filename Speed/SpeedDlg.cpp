
// SpeedDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Speed.h"
#include "SpeedDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnFileCurrentspeed();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_COMMAND(ID_FILE_CURRENTSPEED, &CAboutDlg::OnFileCurrentspeed)
END_MESSAGE_MAP()


// ���������� ���� CSpeedDlg



CSpeedDlg::CSpeedDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SPEED_DIALOG, pParent)
	, m_SpeedEdit(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpeedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SPEED_EDIT, m_SpeedEdit);
}

BEGIN_MESSAGE_MAP(CSpeedDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_SPEED_EDIT, &CSpeedDlg::OnChangeSpeedEdit)
	ON_COMMAND(ID_FILE_CURRENTSPEED, &CSpeedDlg::OnFileCurrentspeed)
	ON_COMMAND(ID_FILE_EXIT, &CSpeedDlg::OnFileExit)
	ON_COMMAND(ID_HELP_ABOUT, &CSpeedDlg::OnHelpAbout)
	ON_COMMAND(ID_HELP_SAYHELLO, &CSpeedDlg::OnHelpSayhello)
END_MESSAGE_MAP()


// ����������� ��������� CSpeedDlg

BOOL CSpeedDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CSpeedDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CSpeedDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CSpeedDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSpeedDlg::OnChangeSpeedEdit()
{
	// TODO:  ���� ��� ������� ���������� RICHEDIT, �� ������� ���������� �� �����
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  �������� ��� �������� ����������

	UpdateData(TRUE);
}



void CSpeedDlg::OnFileCurrentspeed()
{
	// TODO: �������� ���� ��� ����������� ������

	char strSpeed[100];
	_itoa_s(m_SpeedEdit, strSpeed, 10);
	MessageBox((LPCTSTR)strSpeed);
}


void CSpeedDlg::OnFileExit()
{
	// TODO: �������� ���� ��� ����������� ������

	OnOK();
}


void CSpeedDlg::OnHelpAbout()
{
	// TODO: �������� ���� ��� ����������� ������

	CAboutDlg dlg;
	dlg.DoModal();
}


void CSpeedDlg::OnHelpSayhello()
{
	// TODO: �������� ���� ��� ����������� ������

	MessageBox((LPCTSTR)"Hello!!!");
}

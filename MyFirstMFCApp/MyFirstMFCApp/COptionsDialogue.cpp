// COptionsDialogue.cpp : implementation file
//

#include "pch.h"
#include "MyFirstMFCApp.h"
#include "COptionsDialogue.h"
#include "afxdialogex.h"


// COptionsDialogue dialog

IMPLEMENT_DYNAMIC(COptionsDialogue, CDialogEx)

COptionsDialogue::COptionsDialogue(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MAIN, pParent) // CONSTRUCTORS FOR INITIAL VALUES
	, m_text(_T("Enter text"))
	, m_bgColor(0)
	, m_x(0)
	, m_y(0)
{

}

COptionsDialogue::~COptionsDialogue()
{
}

void COptionsDialogue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_text);
	DDX_Radio(pDX, IDC_RADIO_RED, m_bgColor);
	DDX_Text(pDX, IDC_EDIT_POS_X, m_x);
	DDV_MinMaxInt(pDX, m_x, 0, 999999);
	DDX_Text(pDX, IDC_EDIT_POS_Y, m_y);
	DDV_MinMaxInt(pDX, m_y, 0, 999999);
}


BEGIN_MESSAGE_MAP(COptionsDialogue, CDialogEx)
END_MESSAGE_MAP()


// COptionsDialogue message handlers

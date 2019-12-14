#pragma once


// COptionsDialogue dialog

class COptionsDialogue : public CDialogEx
{
	DECLARE_DYNAMIC(COptionsDialogue)

public:
	COptionsDialogue(CWnd* pParent = nullptr);   // standard constructor
	virtual ~COptionsDialogue();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_text;
	int m_bgColor;
	int m_x;
	int m_y;
};

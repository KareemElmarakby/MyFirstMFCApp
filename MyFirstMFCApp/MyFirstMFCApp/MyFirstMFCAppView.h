
// MyFirstMFCAppView.h : interface of the CMyFirstMFCAppView class
//

#pragma once


class CMyFirstMFCAppView : public CView
{
protected: // create from serialization only
	CMyFirstMFCAppView() noexcept;
	DECLARE_DYNCREATE(CMyFirstMFCAppView)

// Attributes
public:
	CMyFirstMFCAppDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMyFirstMFCAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnToolsOptions();
private:
	CString m_text{_T("Go to Tools to customize")}; // _T is UNICODE indicator
	int m_bgColor{0};
	int m_x{100};
	int m_y{200};
};

#ifndef _DEBUG  // debug version in MyFirstMFCAppView.cpp
inline CMyFirstMFCAppDoc* CMyFirstMFCAppView::GetDocument() const
   { return reinterpret_cast<CMyFirstMFCAppDoc*>(m_pDocument); }
#endif


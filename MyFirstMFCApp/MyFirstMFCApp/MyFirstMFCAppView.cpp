
// MyFirstMFCAppView.cpp : implementation of the CMyFirstMFCAppView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MyFirstMFCApp.h"
#endif

#include "MyFirstMFCAppDoc.h"
#include "MyFirstMFCAppView.h"
#include "COptionsDialogue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyFirstMFCAppView

IMPLEMENT_DYNCREATE(CMyFirstMFCAppView, CView)

BEGIN_MESSAGE_MAP(CMyFirstMFCAppView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TOOLS_OPTIONS, &CMyFirstMFCAppView::OnToolsOptions)
END_MESSAGE_MAP()

// CMyFirstMFCAppView construction/destruction

CMyFirstMFCAppView::CMyFirstMFCAppView() noexcept
{
	// TODO: add construction code here

}

CMyFirstMFCAppView::~CMyFirstMFCAppView()
{
}

BOOL CMyFirstMFCAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMyFirstMFCAppView drawing

void CMyFirstMFCAppView::OnDraw(CDC* pDC) // Drawing context
{
	CMyFirstMFCAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect clientRect; // clientRect = target window
	GetClientRect(clientRect);

	int R, G, B;

	switch (m_bgColor) {
		case (0): // Red
			R = 255;
			G = 0;
			B = 0;
			break;
		case (1): // Blue
			R = 0;
			G = 0;
			B = 255;
			break;
		case (2): // Green
			R = 0;
			G = 255;
			B = 0;
			break;
	}

	pDC->FillSolidRect(clientRect, RGB(R,G,B)); // Fills with solid color
	pDC->TextOutW(m_x, m_y, m_text); // _T is unicode string, sets position of text
}

void CMyFirstMFCAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMyFirstMFCAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMyFirstMFCAppView diagnostics

#ifdef _DEBUG
void CMyFirstMFCAppView::AssertValid() const
{
	CView::AssertValid();
}

void CMyFirstMFCAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyFirstMFCAppDoc* CMyFirstMFCAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyFirstMFCAppDoc)));
	return (CMyFirstMFCAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyFirstMFCAppView message handlers


void CMyFirstMFCAppView::OnToolsOptions()
{
	COptionsDialogue dlgOptions;

	dlgOptions.m_text = m_text;
	dlgOptions.m_bgColor = m_bgColor;
	dlgOptions.m_x = m_x;
	dlgOptions.m_y = m_y;

	if (dlgOptions.DoModal() == IDOK) {
		m_text		= dlgOptions.m_text;
		m_bgColor	= dlgOptions.m_bgColor;
		m_x			= dlgOptions.m_x;
		m_y			= dlgOptions.m_y;
	}

	Invalidate();
	UpdateWindow(); // Automatically updates the window after changes
}

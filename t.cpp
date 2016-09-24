// 115backDlg.cpp : implementation file
//
#include <windows.h>
#include "time.h"
#include "stdafx.h"
#include "115back.h"
#include "115backDlg.h"
#include "math.h"
#include <afxinet.h>
#include <stdlib.h>
#include <direct.h>
#include <io.h>
#include <afxhtml.h>
//#include <Shlwapi.h>
//#pragma comment(lib,"Shlwapi.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
const int SSC3BOUND=11000;
const int SSC3BOUNDNEW=6500;
const int SSC3BOUNDDOWN=600;
const int SSC5BOUND=15100;
const int SSC5BOUNDDOWN=3240;

const int SSQBOUND=30;
const int SSQBOUNDDOWN=10;
const int SSQENDBOUND=80;
const int SSQENDBOUNDDOWN=30;
////////////////////////////////////////////
# define N 624
# define M 397
# define MATRIX_A 0x9908b0dfUL /* constant vector a */
# define UPPER_MASK 0x80000000UL /* most significant w-r bits */
# define LOWER_MASK 0x7fffffffUL /* least significant r bits */
static unsigned long mt[N]; /* the array for the state vector */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	
	
	
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy115backDlg dialog

CMy115backDlg::CMy115backDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy115backDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy115backDlg)	
	m_dfile = _T("");
	m_bfile = _T("");
	m_ql = 0;
	m_ssc5 = _T("");
	m_wb = 0;
	m_we = 0;
	m_tuib = 0;
	m_tuie = 0;
	m_step = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32


	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy115backDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy115backDlg)
	DDX_Text(pDX, IDC_EDIT1, m_mo);
	DDX_Text(pDX, IDC_EDIT2, m_num);
	DDX_Text(pDX, IDC_EDIT3, m_mas);
	DDX_Text(pDX, IDC_EDIT4, m_qmas);
	DDX_Text(pDX, IDC_EDIT5, m_btui);
	DDX_Text(pDX, IDC_EDIT6, m_etui);
	DDX_Text(pDX, IDC_EDIT9, m_b);
	DDX_Text(pDX, IDC_EDIT10, m_e);
	DDX_Text(pDX, IDC_EDIT11, m_su);
	DDX_Text(pDX, IDC_EDIT12, m_dfile);
	DDX_Text(pDX, IDC_EDIT13, m_bfile);
	DDX_Text(pDX, IDC_EDIT8, m_ql);
	DDX_Text(pDX, IDC_EDIT14, m_wb);
	DDX_Text(pDX, IDC_EDIT15, m_we);
	DDX_Text(pDX, IDC_EDIT16, m_tuib);
	DDX_Text(pDX, IDC_EDIT17, m_tuie);
	DDX_Text(pDX, IDC_EDIT7, m_step);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy115backDlg, CDialog)
	//{{AFX_MSG_MAP(CMy115backDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT12, OnChangeEdit12)
	ON_EN_CHANGE(IDC_EDIT13, OnChangeEdit13)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)	
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)	
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_BN_CLICKED(IDC_BUTTON16, OnButton16)
	ON_BN_CLICKED(IDC_BUTTON26, OnButton26)
	ON_BN_CLICKED(IDC_BUTTON27, OnButton27)
	ON_BN_CLICKED(IDC_BUTTON28, OnButton28)
	ON_BN_CLICKED(IDC_BUTTON29, OnButton29)
	ON_BN_CLICKED(IDC_BUTTON30, OnButton30)
	ON_BN_CLICKED(IDC_BUTTON40, OnButton40)
	ON_BN_CLICKED(IDC_BUTTON41, OnButton41)
	ON_BN_CLICKED(IDC_BUTTON42, OnButton42)
	ON_BN_CLICKED(IDC_BUTTON34, OnButton34)
	ON_BN_CLICKED(IDC_BUTTON36, OnButton36)
	ON_BN_CLICKED(IDC_BUTTON37, OnButton37)
	ON_BN_CLICKED(IDC_BUTTON43, OnButton43)
	ON_BN_CLICKED(IDC_BUTTON25, OnButton25)
	ON_BN_CLICKED(IDC_BUTTON44, OnButton44)
	ON_BN_CLICKED(IDC_BUTTON45, OnButton45)
	ON_BN_CLICKED(IDC_BUTTON31, OnButton31)
	ON_BN_CLICKED(IDC_BUTTON32, OnButton32)
	ON_BN_CLICKED(IDC_BUTTON33, OnButton33)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON46, OnButton46)
	ON_BN_CLICKED(IDC_BUTTON47, OnButton47)
	ON_BN_CLICKED(IDC_BUTTON48, OnButton48)
	ON_BN_CLICKED(IDC_BUTTON49, OnButton49)
	ON_BN_CLICKED(IDC_BUTTON50, OnButton50)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy115backDlg message handlers

BOOL CMy115backDlg::OnInitDialog()
{
	
    
	CDialog::OnInitDialog();
	srand( (unsigned)time( NULL ) );
    tuichu=0;
    ssc3paiming=5000;
    ssc3num=0;
    buypath="";
    sharpflag=false;
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	CMy115backDlg::jiemian(41);
	//GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE); 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy115backDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy115backDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy115backDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CMy115backDlg::OnOK() 
{

	//CMy115backDlg::OpenFile();
	//CDialog::OnOK();
}





void CMy115backDlg::OpenFile()
{
CFileDialog dlg(TRUE, "数据文件", "*.txt",OFN_HIDEREADONLY
|OFN_OVERWRITEPROMPT,"Text Files(*.txt)|*.txt|All Files(*.*)|*.*||");
if ( dlg.DoModal()!=IDOK ) return;
//获取文件的绝对路径
CString sFileName=dlg.GetPathName();
//打开文件
CStdioFile out;
out.Open(sFileName, CFile::modeRead);
CString sSql="",s;
//读取文件
do{
out.ReadString(s);s=delern(s);
sSql=sSql+s+(char)10;
}
while (out.GetPosition()!=out.GetLength());
out.Close();
AfxMessageBox(sSql);
}

void CMy115backDlg::OnChangeEdit1() 
{	
	UpdateData(TRUE);	
}
void CMy115backDlg::OnChangeEdit2() 
{
	UpdateData(TRUE);
}
void CMy115backDlg::OnChangeEdit3() 
{
	//if (m_num==5){
	  //if (m_mas==3){GetDlgItem(IDC_EDIT1)->SetWindowText("44-88");m_mo="44-88";}
	  //if (m_mas==4){GetDlgItem(IDC_EDIT1)->SetWindowText("50-100");m_mo="50-100";}
	  //if (m_mas==3){GetDlgItem(IDC_EDIT1)->SetWindowText("200-250");m_mo="200-250";}
    //}  

	UpdateData(TRUE);
	//UpdateData(FALSE);
}
void CMy115backDlg::OnChangeEdit4() 
{   
	UpdateData(TRUE);
}
void CMy115backDlg::OnChangeEdit5() 
{    

    UpdateData(TRUE);
    
}
void CMy115backDlg::OnChangeEdit6() 
{
	UpdateData(TRUE);
}
void CMy115backDlg::OnChangeEdit7() 
{
	UpdateData(TRUE);
}
void CMy115backDlg::OnChangeEdit8() 
{
	UpdateData(TRUE);
}
void CMy115backDlg::OnChangeEdit9() 
{
	UpdateData(TRUE);
}
void CMy115backDlg::OnChangeEdit10() 
{
	UpdateData(TRUE);
}
void CMy115backDlg::OnChangeEdit11() 
{
	UpdateData(TRUE);
}
void CMy115backDlg::OnChangeEdit12() 
{
	UpdateData(TRUE);
}
void CMy115backDlg::OnChangeEdit13() 
{
	UpdateData(TRUE);
}

void CMy115backDlg::OnButton1() 
{
   UpdateData(TRUE);  
   CFileDialog dlg(TRUE, "数据文件", "*.txt",OFN_HIDEREADONLY
|OFN_OVERWRITEPROMPT,"Text Files(*.txt)|*.txt|All Files(*.*)|*.*||");
  if ( dlg.DoModal()!=IDOK ) return;
  //获取文件的绝对路径
  CString sFileName=dlg.GetPathName();
  m_dfile=sFileName;
  UpdateData(FALSE);
}

void CMy115backDlg::OnButton2() 
{
	UpdateData(TRUE);  
	CFileDialog dlg(TRUE, "后退文件", "*.txt",OFN_HIDEREADONLY
|OFN_OVERWRITEPROMPT,"Text Files(*.txt)|*.txt|All Files(*.*)|*.*||");
  if ( dlg.DoModal()!=IDOK ) return;
  //获取文件的绝对路径
  CString sFileName=dlg.GetPathName();
  m_bfile=sFileName;
  UpdateData(FALSE);
	
}







void CMy115backDlg::Split(CString a, CString *b, int &c, CString d)
{

if (a.Find(d)<0){b[0]=a;c=0;return;}
int d_len=d.GetLength();

int j=0;
int n=0;
int m_pos;

while(1)
{
   m_pos= a.Find(d,j);
   if(m_pos==-1 && j==0)
        {
    c=-1;
    break;
   }
  
   if(m_pos==-1 && j!=0)
   {
    b[n]=a.Mid(j,a.GetLength()-j);
    c=n;
    break;
   }
  
   if(j==0)
   {
    b[n]=a.Mid(0,m_pos);
    j=m_pos+d_len;
   }
   else
   {
    b[n]=a.Mid(j,m_pos-j);
	//MessageBox(Cstr(n)+"  "+b[n]);
    j=m_pos+d_len;
   }
   n++;
}
}









CString CMy115backDlg::padstrcisu(CString tstr, int n, CString tr, int direc)
{
  CString s=tstr;
  int r=n-tstr.GetLength();
  if (r>0){
	for (int i=1;i<=r;i++){
	  if (direc==0){s=tr+s;}
      else {s=s+tr;}      
    }
  }
  return s;
}
/////////////////





CString CMy115backDlg::Cstr(int n)
{
   CString s;
   s.Format("%d",n);    
   return s;
}















void CMy115backDlg::OnButton10() 
{

  if (JieMian!=17){jiemian(17);return;}  
  setbutton(FALSE);
  UpdateData(TRUE);

  if (m_num==2){
    DWORD dwAttr = ::GetFileAttributes(m_dfile); 
    if (dwAttr == 0xffffffff){
      setbutton(TRUE);MessageBox("请指定目录"); 
      return;
    }
   
     CString urlmode="http://kaijiang.cjcp.com.cn/cqssc/index.php?topage=";
     int pos=m_dfile.ReverseFind('\\');
     CString dirpath=m_dfile.Left(pos+1);
     CString jigo=dirpath+"29.txt";
     getcjsscdata(m_qmas,jigo,urlmode);
     MessageBox("程序结束！");setbutton(TRUE);return;
  }

  CString newdata,olddata,dirpath,s,t,fname,jigo,a[50],wr,olds;
  int pos,i=0,al,n,you;
  
  newdata=m_dfile;
  olddata=m_bfile;

  CStdioFile out,datain;  
  DWORD dwAttr = ::GetFileAttributes(newdata); 
  if (dwAttr == 0xffffffff){
    setbutton(TRUE);MessageBox("请指定近期数据文件"); 
	return;
  }
  pos=m_dfile.ReverseFind('\\');
  dirpath=m_dfile.Left(pos+1);  
/////////////////////////////////////////////
  if (m_dfile.Find("29d.txt")>=0){
   
    datain.Open(newdata, CFile::modeRead);
    jigo=dirpath+"29.txt";    
    out.Open(jigo,CFile::modeCreate|CFile::modeWrite); 
    i=1;
    do{
      datain.ReadString(s);s=delern(s);

      Split(s,a,al," ");
      wr=Cstr(i)+"\t"+a[0].Mid(2)+"\t"+a[3]+"\r\n";

      out.Write(wr,wr.GetLength());
      i++;
    }
    while (datain.GetPosition()!=datain.GetLength());
    datain.Close();
    out.Close();
    m_dfile=jigo;
    newdata=m_dfile;
  }


/////////////////////////////////////////////
  

  if (m_dfile.Find("29.txt")>=0){
////////////////////////////////////////////////

////////////////////////////////////////////
  dwAttr = ::GetFileAttributes(olddata); 
  if (dwAttr == 0xffffffff){
    setbutton(TRUE);MessageBox("请指定远期数据文件"); 
	return;
  }
  
  datain.Open(olddata, CFile::modeRead);
  datain.ReadString(s);s=delern(s);
  datain.Close();
  pos=s.Find("\t");
  s=s.Mid(pos+1);
  pos=s.Find("\t");
  CString oldheadqi=s.Left(pos);

///////////////////////////////////////////////////


/////////////////////////////////////////////////

  jigo=dirpath+"tmp.txt";

  
  out.Open(jigo,CFile::modeCreate|CFile::modeWrite);  
  datain.Open(newdata, CFile::modeRead);
  i=0;
  olds="";
  you=0;
  do{
    datain.ReadString(s);s=delern(s);
        for (int j=0;j<5;j++){s.Replace("\t\t","\t");}
	Split(s, a, al,"\t");
////////////////////////////////
        n=atoi(a[0]);
        //MessageBox("n="+Cstr(n)+"  i="+Cstr(i));
        if (n<i+1){break;}
        if (a[1].GetLength()<9){break;}
        if (a[2].GetLength()<9){break;}
        if(a[1]==oldheadqi){you=1;break;}
/////////////////////////////////
	wr=Cstr(i+1)+"\t"+a[1]+"\t"+a[2];
    out.Write(wr+"\r\n",wr.GetLength()+2);
        olds=s;
	i=i+1;
  }
  while (datain.GetPosition()!=datain.GetLength());
  datain.Close();

  if (you==0){
    MessageBox("两文件脱节，无法完成！");setbutton(TRUE);
    return; 
  }  


  datain.Open(olddata, CFile::modeRead);
  do{
    datain.ReadString(s); s=delern(s);
	Split(s, a, al,"\t");
	wr=Cstr(i+1)+"\t"+a[1]+"\t"+a[2];
    out.Write(wr+"\r\n",wr.GetLength()+2);	
	//if (i>=99999){break;}
	i=i+1;
  }  while (datain.GetPosition()!=datain.GetLength());

  out.Close();
  datain.Close();
  
  DeleteFile(olddata);
  CFile::Rename(dirpath+"tmp.txt",olddata);
  if (m_mas!=0){
     datain.Open(m_bfile, CFile::modeRead);
     out.Open(m_dfile,CFile::modeCreate|CFile::modeWrite);  
     i=0;
     do{
       datain.ReadString(s);s=delern(s); 
       out.Write(s+"\r\n",s.GetLength()+2);
       i=i+1;
       if (i>9999){break;}
     }  while (datain.GetPosition()!=datain.GetLength());
     datain.Close();
     out.Close();
  

   }


  }
//MessageBox(m_dfile);
  if (m_dfile.Find("重庆时时彩B.txt")>=0) {
 
  jigo=dirpath+"29newc.txt";
//MessageBox(jigo);
  DoEvents();
  GetDlgItem(idc_jingdu)->SetWindowText("建立新文件"+jigo);
  DoEvents();


  
  out.Open(jigo,CFile::modeCreate|CFile::modeWrite); 
  

  datain.Open(newdata, CFile::modeRead);
  i=0;
  do{
    datain.ReadString(s);s=delern(s);
	Split(s, a, al,"\t");
        a[0]=a[0].Mid(2);
        //MessageBox(a[0]+"\r\n"+a[1]);
        
        a[0]=a[0].Left(6)+a[0].Right(3);
	wr=Cstr(i+1)+"\t"+a[0]+"\t"+a[1];
        //MessageBox(wr);
        out.Write(wr+"\r\n",wr.GetLength()+2);
	i=i+1;
        if (i>=m_etui){break;}
  }
  while (datain.GetPosition()!=datain.GetLength());
  datain.Close();
  
  out.Close();
  


  }//重庆时时彩B.txt

  
  MessageBox("程序结束！");setbutton(TRUE);
  return;   
}
  
















////////////////////////////////////////////////////////////////////////////////////








////////////////////////////////////////////


//////////////////////////////////////////
void CMy115backDlg::jiemian(int xuhao)
{
  setbutton(TRUE);
  int n=0;
  CString dis;
  switch (xuhao)
  {
   case 101://dlc's zu3,zu4
       JieMian=101;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("dlc组合3,4命中数"); 
       dis="类型 1:组合详情 2:命中数 3 求3位组合 4 求4位组合 5 求5位组合 6 求投注文件 7 环境建立\r\n";
     dis+="1与6的数据文件一样,是记录3个源文件名的文件,顺序为345,这些文件记录了组合,分别由345产生.\r\n";
     dis+="2只需要指定目录,但目录中要有45.txt;345要指定2产生的对应文件;7是2-6全部 \r\n";
       GetDlgItem(IDC_STATICdetail)->SetWindowText(dis); 
	   
	   GetDlgItem(IDC_STATIC14)->SetWindowText("取位下限");
	   GetDlgItem(IDC_STATIC15)->SetWindowText("取位上限");
       GetDlgItem(IDC_EDIT14)->SetWindowText("1");
       GetDlgItem(IDC_EDIT15)->SetWindowText("1");
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);

	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
       GetDlgItem(IDC_STATIC1)->SetWindowText("分段模式");
	   GetDlgItem(IDC_STATIC2)->SetWindowText("类    型");   
       GetDlgItem(IDC_STATIC3)->SetWindowText("单行长度");       
       GetDlgItem(IDC_STATIC4)->SetWindowText("文件组数");       
	   GetDlgItem(IDC_STATIC5)->SetWindowText("单组个数");
       GetDlgItem(IDC_STATIC6)->SetWindowText("显示间隔");
       GetDlgItem(IDC_STATIC7)->SetWindowText("完遗个数");
	   GetDlgItem(IDC_STATIC8)->SetWindowText("搜索起点");
	   GetDlgItem(IDC_STATIC9)->SetWindowText("后退期数");
	   GetDlgItem(IDC_STATIC10)->SetWindowText("最低完遗");
	   GetDlgItem(IDC_STATIC11)->SetWindowText("搜索数量");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
	   GetDlgItem(IDC_STATIC13)->SetWindowText("目标目录");


	   n=100+rand()%100;

	   
	   GetDlgItem(IDC_EDIT1)->SetWindowText("");
       GetDlgItem(IDC_EDIT2)->SetWindowText("1");
       GetDlgItem(IDC_EDIT3)->SetWindowText("88");
	   GetDlgItem(IDC_EDIT4)->SetWindowText("3000000");
	   GetDlgItem(IDC_EDIT5)->SetWindowText("8");
       GetDlgItem(IDC_EDIT6)->SetWindowText("10000");
       GetDlgItem(IDC_EDIT7)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT8)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT9)->SetWindowText("0");
       GetDlgItem(IDC_EDIT10)->SetWindowText("50");
       GetDlgItem(IDC_EDIT11)->SetWindowText("0");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
	   GetDlgItem(IDC_EDIT13)->SetWindowText("");
	   

       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);

   	   GetDlgItem(IDC_STATIC16)->SetWindowText("backlow");
	   GetDlgItem(IDC_STATIC17)->SetWindowText("backhigh");
     
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT16)->SetWindowText("121");
       GetDlgItem(IDC_EDIT17)->SetWindowText("600");
	   

       break;


   case 105://analysis
       JieMian=105;
	   dis="数据比对";
           GetDlgItem(IDC_STATIChead)->SetWindowText(dis); 

           dis=   "类型 1 skydrive  2 utowin \r\n";
          
 
           
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis); 
   
        GetDlgItem(IDC_STATIC1)->SetWindowText("遗漏分布");
        GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
       
        GetDlgItem(IDC_EDIT1)->SetWindowText("");
        GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC2)->SetWindowText("类   型");
        GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT2)->SetWindowText("1");
        GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC3)->SetWindowText("缓冲期数");
        GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT3)->SetWindowText("0");
        GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC4)->SetWindowText("判断期数");
        GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT4)->SetWindowText("30000");
        GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);


        GetDlgItem(IDC_STATIC5)->SetWindowText("保存门槛");
        GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT5)->SetWindowText("3");
        GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC6)->SetWindowText("出现次数");
        GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT6)->SetWindowText("1");
        GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC7)->SetWindowText("百分门槛");
        GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT7)->SetWindowText("55");
        GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC8)->SetWindowText("检查方式");
        GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT8)->SetWindowText("1");
        GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC9)->SetWindowText("第二门槛");
        GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT9)->SetWindowText("2");
        GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC10)->SetWindowText("第二次数");
        GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT10)->SetWindowText("2");
        GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC11)->SetWindowText("选出列数");
        GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT11)->SetWindowText("110");
        GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
        GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT12)->SetWindowText("");
        GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC13)->SetWindowText("预告文件");
        GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT13)->SetWindowText("");
        GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC14)->SetWindowText("双位遗漏");
        GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT14)->SetWindowText("0");
        GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC15)->SetWindowText("入选数目");
        GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT15)->SetWindowText("20000");
        GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC16)->SetWindowText("更新数量");//m_tuib
        GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);
       
        GetDlgItem(IDC_EDIT16)->SetWindowText("3000");
        GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC17)->SetWindowText("排序数量");//m_tuie
        GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);
        
        GetDlgItem(IDC_EDIT17)->SetWindowText("100");
        GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);


       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);       
	   
      

       break;
   case 104://ssqe前探
       JieMian=104;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssqend的前探后退期文件"); 
       
	   GetDlgItem(IDC_EDIT14)->SetWindowText("2");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");

	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
       GetDlgItem(IDC_STATIC1)->SetWindowText("分段模式");
	   GetDlgItem(IDC_STATIC2)->SetWindowText("最小遗漏");   
       GetDlgItem(IDC_STATIC3)->SetWindowText("极端遗漏");       
       GetDlgItem(IDC_STATIC4)->SetWindowText("前探期数");       
	   GetDlgItem(IDC_STATIC5)->SetWindowText("是否精确");
       GetDlgItem(IDC_STATIC6)->SetWindowText("显示间隔");
       GetDlgItem(IDC_STATIC7)->SetWindowText("完遗个数");
	   GetDlgItem(IDC_STATIC8)->SetWindowText("搜索起点");
	   GetDlgItem(IDC_STATIC9)->SetWindowText("最低遗漏");
	   GetDlgItem(IDC_STATIC10)->SetWindowText("最低完遗");
	   GetDlgItem(IDC_STATIC11)->SetWindowText("保    留");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
	   GetDlgItem(IDC_STATIC13)->SetWindowText("目标目录");


	   //n=100+rand()%100;

	   //GetDlgItem(IDC_EDIT1)->SetWindowText("100[0$50]-1000[0$1000]");
	   GetDlgItem(IDC_EDIT1)->SetWindowText("200");
       GetDlgItem(IDC_EDIT2)->SetWindowText("288");
       GetDlgItem(IDC_EDIT3)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT4)->SetWindowText("500");
	   GetDlgItem(IDC_EDIT5)->SetWindowText("1");
       GetDlgItem(IDC_EDIT6)->SetWindowText("10000");
       GetDlgItem(IDC_EDIT7)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT8)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT9)->SetWindowText("0");
       GetDlgItem(IDC_EDIT10)->SetWindowText("160");
       GetDlgItem(IDC_EDIT11)->SetWindowText("0");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
	   GetDlgItem(IDC_EDIT13)->SetWindowText("");
	   

       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);       
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);

       GetDlgItem(IDC_STATIC16)->SetWindowText("后退开始");
       GetDlgItem(IDC_STATIC17)->SetWindowText("后退结束");

       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT16)->SetWindowText("31");
       GetDlgItem(IDC_EDIT17)->SetWindowText("60");
	   

       break;
   case 103://
       JieMian=103;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求近期热码组合"); 
           dis="类型 1 dlc3h1all 2 sscall1 3 ssqnx1";        
	   
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);             

	   
        GetDlgItem(IDC_STATIC1)->SetWindowText("开始期号");
        GetDlgItem(IDC_EDIT1)->SetWindowText("");
        GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);


	GetDlgItem(IDC_STATIC2)->SetWindowText("类  型");  
        GetDlgItem(IDC_EDIT2)->SetWindowText("1");
        GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);

    
       GetDlgItem(IDC_STATIC3)->SetWindowText("前取期数");    
       GetDlgItem(IDC_EDIT3)->SetWindowText("10");
        GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
   
       GetDlgItem(IDC_STATIC4)->SetWindowText("次数门槛"); 
       GetDlgItem(IDC_EDIT4)->SetWindowText("2");
        GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);

      
	   GetDlgItem(IDC_STATIC5)->SetWindowText("bl");
        GetDlgItem(IDC_EDIT5)->SetWindowText("0");
        GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);



       GetDlgItem(IDC_STATIC6)->SetWindowText("bl");
        GetDlgItem(IDC_EDIT6)->SetWindowText("0");
        GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);

       GetDlgItem(IDC_STATIC7)->SetWindowText("bl");
        GetDlgItem(IDC_EDIT7)->SetWindowText("0");
        GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);

	   GetDlgItem(IDC_STATIC8)->SetWindowText("bl");
        GetDlgItem(IDC_EDIT8)->SetWindowText("0");
        GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);

	   GetDlgItem(IDC_STATIC9)->SetWindowText("bl");
        GetDlgItem(IDC_EDIT9)->SetWindowText("58");
        GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);

	   GetDlgItem(IDC_STATIC10)->SetWindowText("bl");
        GetDlgItem(IDC_EDIT10)->SetWindowText("0");
        GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE);

	   GetDlgItem(IDC_STATIC11)->SetWindowText("bl");
        GetDlgItem(IDC_EDIT11)->SetWindowText("0");
        GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);

       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
        GetDlgItem(IDC_EDIT12)->SetWindowText("");
        GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);

	   GetDlgItem(IDC_STATIC13)->SetWindowText("数据文件");
        GetDlgItem(IDC_EDIT13)->SetWindowText("");
        GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

      GetDlgItem(IDC_STATIC14)->SetWindowText("bl");
        GetDlgItem(IDC_EDIT14)->SetWindowText("58");
        GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);

       GetDlgItem(IDC_STATIC15)->SetWindowText("bl");
        GetDlgItem(IDC_EDIT15)->SetWindowText("0");
        GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);

       GetDlgItem(IDC_STATIC16)->SetWindowText("目标目录");
        GetDlgItem(IDC_EDIT16)->SetWindowText("58");
        GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);

      GetDlgItem(IDC_STATIC17)->SetWindowText("");
        GetDlgItem(IDC_EDIT17)->SetWindowText("58");
        GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);	    

       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);

       


       
	   

       break;
   case 102://ssc前探
       JieMian=102;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssc的前探后退期文件"); 
       dis="类型:1(一星) 2(二星) 3(三星) 4(前二) 5(五星) 6(ssc5) 7(sscnx1)\r\n";        
	   dis=dis+"sscnx1只提供已知组合的重算功能。";

       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC14)->SetWindowText("取位下限");
	   GetDlgItem(IDC_STATIC15)->SetWindowText("取位上限");
       GetDlgItem(IDC_EDIT14)->SetWindowText("1");
       GetDlgItem(IDC_EDIT15)->SetWindowText("5");

	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
       GetDlgItem(IDC_STATIC1)->SetWindowText("分段模式");
	   GetDlgItem(IDC_STATIC2)->SetWindowText("类    型");   
       GetDlgItem(IDC_STATIC3)->SetWindowText("保    留");       
       GetDlgItem(IDC_STATIC4)->SetWindowText("前探期数");       
	   GetDlgItem(IDC_STATIC5)->SetWindowText("是否精确");
       GetDlgItem(IDC_STATIC6)->SetWindowText("显示间隔");
       GetDlgItem(IDC_STATIC7)->SetWindowText("完遗个数");
	   GetDlgItem(IDC_STATIC8)->SetWindowText("搜索起点");
	   GetDlgItem(IDC_STATIC9)->SetWindowText("最低遗漏");
	   GetDlgItem(IDC_STATIC10)->SetWindowText("最低完遗");
	   GetDlgItem(IDC_STATIC11)->SetWindowText("搜索数量");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
	   GetDlgItem(IDC_STATIC13)->SetWindowText("目标目录");


	   n=100+rand()%100;

	   //GetDlgItem(IDC_EDIT1)->SetWindowText("100[0$50]-1000[0$1000]");
	   GetDlgItem(IDC_EDIT1)->SetWindowText("118-388^***********$60");
       GetDlgItem(IDC_EDIT2)->SetWindowText("1");
       GetDlgItem(IDC_EDIT3)->SetWindowText("0");
	   GetDlgItem(IDC_EDIT4)->SetWindowText("200");
	   GetDlgItem(IDC_EDIT5)->SetWindowText("1");
       GetDlgItem(IDC_EDIT6)->SetWindowText("20000");
       GetDlgItem(IDC_EDIT7)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT8)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT9)->SetWindowText("0");
       GetDlgItem(IDC_EDIT10)->SetWindowText("50");
       GetDlgItem(IDC_EDIT11)->SetWindowText("0");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
	   GetDlgItem(IDC_EDIT13)->SetWindowText("");
	   

       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT16)->SetWindowText("101");
       GetDlgItem(IDC_EDIT17)->SetWindowText("200");
       
	   

       break;//paixu_status
     case 1:

       JieMian=1;
       GetDlgItem(IDC_STATIChead)->SetWindowText("对文件进行从高到低的排序");  
	   dis="类    型:1(按整行排序)  2(按指定列号排序)  3(按方括号内数据排序)  4(status排序)\r\n";
       dis=dis+"删除重复:1(删除重复项，只看冒号后) 2(删除重复项，全看) 3(不删除)  \r\n顺    序:1(字典反序)    2(字典正序)";
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);

	   GetDlgItem(IDC_STATIC1)->SetWindowText("分隔符号");
       GetDlgItem(IDC_EDIT1)->SetWindowText("#");
	   GetDlgItem(IDC_STATIC2)->SetWindowText("类    型");
       GetDlgItem(IDC_EDIT2)->SetWindowText("1");
	   GetDlgItem(IDC_STATIC3)->SetWindowText("遗漏模式");
       GetDlgItem(IDC_EDIT3)->SetWindowText("0");

       GetDlgItem(IDC_STATIC5)->SetWindowText("列    号");
       GetDlgItem(IDC_EDIT5)->SetWindowText("1");
	   GetDlgItem(IDC_STATIC11)->SetWindowText("顺    序");
       GetDlgItem(IDC_EDIT11)->SetWindowText("2");
	   GetDlgItem(IDC_STATIC12)->SetWindowText("排序文件");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_STATIC13)->SetWindowText("删除重复");
       GetDlgItem(IDC_EDIT13)->SetWindowText("3");
       GetDlgItem(IDC_STATIC14)->SetWindowText("群体排序");

       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

	   
       
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE); 
       
       GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE); 
       
        
       
       
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE); 
       
       GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE); 
       
       

       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE); 
	   
       
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);

       GetDlgItem(IDC_EDIT14)->SetWindowText("0");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("118");
       
       break;

     case 2:
       JieMian=2;
       GetDlgItem(IDC_STATIChead)->SetWindowText("双色球处理:复分单"); 
           dis="类型1:复分单 2 合并两个单注文件\r\n";
           dis=dis+"选定的号码中,红色号码写在前面,用逗号隔开,蓝色号码写在后面,只写一个,与红色之间用冒号隔开\r\n";
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);
       
           GetDlgItem(IDC_STATIC1)->SetWindowText("下一期号");
           GetDlgItem(IDC_STATIC2)->SetWindowText("类    型");
           GetDlgItem(IDC_STATIC3)->SetWindowText("3组取位");
           GetDlgItem(IDC_STATIC4)->SetWindowText("1+码数");
           GetDlgItem(IDC_STATIC6)->SetWindowText("门    槛");//m_etui
           GetDlgItem(IDC_STATIC7)->SetWindowText("检视期数");//m_step
           GetDlgItem(IDC_STATIC8)->SetWindowText("最小厚度");//m_ql
           GetDlgItem(IDC_STATIC9)->SetWindowText("最小步长");//m_b
           GetDlgItem(IDC_STATIC10)->SetWindowText("最小后退");//m_e


	   GetDlgItem(IDC_STATIC11)->SetWindowText("每组注数");
	   GetDlgItem(IDC_STATIC12)->SetWindowText("数据目录");
	   GetDlgItem(IDC_STATIC13)->SetWindowText("预告文件");
           GetDlgItem(IDC_STATIC14)->SetWindowText("相邻差位");
	   GetDlgItem(IDC_STATIC15)->SetWindowText("最大厚度");//m_we
	   GetDlgItem(IDC_STATIC16)->SetWindowText("最大步长");//m_tuib
           GetDlgItem(IDC_STATIC17)->SetWindowText("最大后退");//m_tuie

           GetDlgItem(IDC_EDIT1)->SetWindowText("11");
           GetDlgItem(IDC_EDIT2)->SetWindowText("1");
           GetDlgItem(IDC_EDIT3)->SetWindowText("20"); 
           GetDlgItem(IDC_EDIT4)->SetWindowText("33");
           GetDlgItem(IDC_EDIT6)->SetWindowText("750");
           GetDlgItem(IDC_EDIT7)->SetWindowText("5");
           GetDlgItem(IDC_EDIT8)->SetWindowText("1");
           GetDlgItem(IDC_EDIT9)->SetWindowText("1");
           GetDlgItem(IDC_EDIT10)->SetWindowText("1"); 

	   GetDlgItem(IDC_EDIT11)->SetWindowText("100");
           GetDlgItem(IDC_EDIT12)->SetWindowText("");
           GetDlgItem(IDC_EDIT13)->SetWindowText("");
           GetDlgItem(IDC_EDIT14)->SetWindowText("1");

	   GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW); 

	   GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW); 

	   GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW); 
       
       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);        
	   
	   GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);        
	   GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);        

       
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
	   
       
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
 
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW); 
           GetDlgItem(IDC_STATIC5)->SetWindowText("只看历史");//m_btui
           GetDlgItem(IDC_EDIT5)->SetWindowText("0");
            GetDlgItem(IDC_EDIT15)->SetWindowText("30");
           GetDlgItem(IDC_EDIT16)->SetWindowText("30");
           GetDlgItem(IDC_EDIT17)->SetWindowText("200");
         
	   
       break;

     case 3:
	   JieMian=3;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("DLC群操作"); 
	  
	   dis="类型 6 更新abuy 7 初期准备 9 回溯历史\r\n";
 
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);   
            
	   GetDlgItem(IDC_STATIC1)->SetWindowText("回溯天数");
       GetDlgItem(IDC_EDIT1)->SetWindowText("5");
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);

           GetDlgItem(IDC_STATIC2)->SetWindowText("类  型");
	   GetDlgItem(IDC_EDIT2)->SetWindowText("6");
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);

	   GetDlgItem(IDC_STATIC3)->SetWindowText("开始目录");
	   GetDlgItem(IDC_EDIT3)->SetWindowText("1");
	   GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);

      

      GetDlgItem(IDC_STATIC4)->SetWindowText("目录个数");
	   GetDlgItem(IDC_EDIT4)->SetWindowText("99");
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);

   
       GetDlgItem(IDC_STATIC5)->SetWindowText("购买注数");
	   GetDlgItem(IDC_EDIT5)->SetWindowText("4");
	   GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);


       GetDlgItem(IDC_STATIC6)->SetWindowText("回溯个数");
	   GetDlgItem(IDC_EDIT6)->SetWindowText("9");
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC7)->SetWindowText("比  率");
	   GetDlgItem(IDC_EDIT7)->SetWindowText("65");
	   GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);

	   GetDlgItem(IDC_STATIC8)->SetWindowText("只看已出");
	   GetDlgItem(IDC_EDIT8)->SetWindowText("1");
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);

	   GetDlgItem(IDC_STATIC9)->SetWindowText("dlc 门槛");
	   GetDlgItem(IDC_EDIT9)->SetWindowText("12");
	   GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);

	   GetDlgItem(IDC_STATIC10)->SetWindowText("ssc 门槛");
	   GetDlgItem(IDC_EDIT10)->SetWindowText("35");
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC11)->SetWindowText("B");
	   GetDlgItem(IDC_EDIT11)->SetWindowText("3");
	   GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);

	   GetDlgItem(IDC_STATIC12)->SetWindowText("遗漏文件");
	   GetDlgItem(IDC_EDIT12)->SetWindowText("");
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);

	   GetDlgItem(IDC_STATIC13)->SetWindowText("出码文件");
	   GetDlgItem(IDC_EDIT13)->SetWindowText("");
	   GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);


	   GetDlgItem(IDC_STATIC14)->SetWindowText("B");
	   GetDlgItem(IDC_EDIT14)->SetWindowText("3");
	   GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
   
	   GetDlgItem(IDC_STATIC15)->SetWindowText("B");
	   GetDlgItem(IDC_EDIT15)->SetWindowText("3");
	   GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
   

	   GetDlgItem(IDC_STATIC16)->SetWindowText("后退开始");
	   GetDlgItem(IDC_EDIT16)->SetWindowText("101");
	   GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);

	   GetDlgItem(IDC_STATIC17)->SetWindowText("后退结束");
	   GetDlgItem(IDC_EDIT17)->SetWindowText("110");
	   GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       
	   
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
       
       break; 

  

	 
	 case 17:
       JieMian=17;

	   GetDlgItem(IDC_STATIChead)->SetWindowText("制作ssc数据文件"); 
           dis="类型:1(近期文件+远期文件) 2(从彩经网提取近期文件)";
           dis=dis+"通常近期文件名29.txt,远期文件名29new.txt,合成后的文件也为29new.txt";
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
       
       GetDlgItem(IDC_STATIC2)->SetWindowText("类    型");
       GetDlgItem(IDC_STATIC3)->SetWindowText("补足近期");
       GetDlgItem(IDC_STATIC4)->SetWindowText("彩经页数");
       GetDlgItem(IDC_STATIC5)->SetWindowText("彩经开始");
       GetDlgItem(IDC_EDIT5)->SetWindowText("1");
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC12)->SetWindowText("近期文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("远期文件");
       GetDlgItem(IDC_EDIT2)->SetWindowText("1");
       GetDlgItem(IDC_EDIT3)->SetWindowText("1");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       GetDlgItem(IDC_EDIT4)->SetWindowText("5");
       GetDlgItem(IDC_EDIT6)->SetWindowText("10000");
 
       
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   

       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);

	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
	   
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);

	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);
	   
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT14)->SetWindowText("2");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("118");
	   
       break;

       
	   


////////////////////
   case 20:
       JieMian=20;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求sscwall组合文件/遗漏调查"); 
           dis="类型 1组合 2调查";
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
       
       GetDlgItem(IDC_STATIC1)->SetWindowText("分段模式");
       GetDlgItem(IDC_STATIC2)->SetWindowText("远方门槛");   
       GetDlgItem(IDC_STATIC3)->SetWindowText("远方界限");    
       GetDlgItem(IDC_STATIC4)->SetWindowText("预告期数");     
       GetDlgItem(IDC_STATIC5)->SetWindowText("取码数量");
	   GetDlgItem(IDC_STATIC6)->SetWindowText("运行次数");
       GetDlgItem(IDC_STATIC7)->SetWindowText("取码周期");
	   GetDlgItem(IDC_STATIC8)->SetWindowText("是否发散");
	   GetDlgItem(IDC_STATIC9)->SetWindowText("可否停止");
	   GetDlgItem(IDC_STATIC10)->SetWindowText("本次一界");//m_e
  	   GetDlgItem(IDC_STATIC11)->SetWindowText("本次二界");//m_su
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("ssc5文件");

	   n=100+rand()%100;
       
	   
	   GetDlgItem(IDC_EDIT1)->SetWindowText("120915006");
       GetDlgItem(IDC_EDIT2)->SetWindowText("11000");
	   GetDlgItem(IDC_EDIT3)->SetWindowText("15000");
           GetDlgItem(IDC_EDIT4)->SetWindowText("20000");
       GetDlgItem(IDC_EDIT5)->SetWindowText("1200");
	   GetDlgItem(IDC_EDIT6)->SetWindowText("1500");
	   GetDlgItem(IDC_EDIT7)->SetWindowText("300");
	   GetDlgItem(IDC_EDIT8)->SetWindowText("0");
       GetDlgItem(IDC_EDIT9)->SetWindowText("0");
	   GetDlgItem(IDC_EDIT10)->SetWindowText("12000");
	   GetDlgItem(IDC_EDIT11)->SetWindowText("5000");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
	   GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
       
	   
       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);
       

       
       
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
       
       
       
	   

       
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
       
       
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
       
	   
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC14)->SetWindowText("取位下限");
	   GetDlgItem(IDC_STATIC15)->SetWindowText("取位上限");
       GetDlgItem(IDC_EDIT14)->SetWindowText("1");
       GetDlgItem(IDC_EDIT15)->SetWindowText("5");

       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("218");

       break;


   case 22:
       JieMian=22;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("qxc,数据文件qxcdata.txt"); 	   
	   dis="类型:1 求预测单码 2 由单码求合成码 3 核对合成码 4 清理重复合成 5 由合成码求合成码 6 生成文件 \r\n";
       
	  GetDlgItem(IDC_STATICdetail)->SetWindowText(dis); 
	  
       GetDlgItem(IDC_STATIC1)->SetWindowText("类    型");	   
       GetDlgItem(IDC_STATIC2)->SetWindowText("标准间隔");
       GetDlgItem(IDC_STATIC3)->SetWindowText("命中等值");
       GetDlgItem(IDC_STATIC4)->SetWindowText("合并标准");
       GetDlgItem(IDC_STATIC5)->SetWindowText("顺序个数");  
       GetDlgItem(IDC_STATIC6)->SetWindowText("反序个数");  
       GetDlgItem(IDC_STATIC7)->SetWindowText("后退期数");     
       GetDlgItem(IDC_STATIC8)->SetWindowText("同码期数");//m_ql        
       GetDlgItem(IDC_EDIT8)->SetWindowText("10");

       GetDlgItem(IDC_STATIC9)->SetWindowText("小时速度"); 
       GetDlgItem(IDC_EDIT9)->SetWindowText("1");
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);  

       GetDlgItem(IDC_STATIC10)->SetWindowText("起始期号");           
       GetDlgItem(IDC_EDIT10)->SetWindowText("350");
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
     

       GetDlgItem(IDC_STATIC11)->SetWindowText("递减步长"); 
       GetDlgItem(IDC_EDIT11)->SetWindowText("3");
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);       

       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");	   
       GetDlgItem(IDC_STATIC13)->SetWindowText("固定投注");
	
       GetDlgItem(IDC_STATIC14)->SetWindowText("预告期数");
       GetDlgItem(IDC_EDIT14)->SetWindowText("100");
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);


       GetDlgItem(IDC_EDIT1)->SetWindowText("1");  
       GetDlgItem(IDC_EDIT2)->SetWindowText("220");
       GetDlgItem(IDC_EDIT3)->SetWindowText("15");
       GetDlgItem(IDC_EDIT4)->SetWindowText("1800");
       GetDlgItem(IDC_EDIT5)->SetWindowText("70");
       GetDlgItem(IDC_EDIT6)->SetWindowText("30");
       GetDlgItem(IDC_EDIT7)->SetWindowText(Cstr(rand()%10));
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("1,9,5,6,3,2,3");
       
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
     
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
 	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
       
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);

       
	   
       GetDlgItem(IDC_STATIC15)->SetWindowText("购买注数");  
       GetDlgItem(IDC_EDIT15)->SetWindowText("500");		   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC17)->SetWindowText("一二范围");
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT17)->SetWindowText("3000");

       GetDlgItem(IDC_STATIC16)->SetWindowText("同态比例");
       GetDlgItem(IDC_EDIT16)->SetWindowText("0");
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   
       break;
   case 23:
       JieMian=23;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssc预告,数据文件29new.txt"); 
	   dis="类型:1 求预测单码 2 由单码求合成码 3 核对合成码 4 清理重复合成 5 由合成码求合成码 \r\n";
       
       
	  GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);   
       
      	   
	  
       GetDlgItem(IDC_STATIC1)->SetWindowText("类    型");	   
       GetDlgItem(IDC_STATIC2)->SetWindowText("标准间隔");
       GetDlgItem(IDC_STATIC3)->SetWindowText("命中等值");
       GetDlgItem(IDC_STATIC4)->SetWindowText("合并标准");
       GetDlgItem(IDC_STATIC5)->SetWindowText("顺序个数");  
       GetDlgItem(IDC_STATIC6)->SetWindowText("反序个数");  
       GetDlgItem(IDC_STATIC7)->SetWindowText("前期条件");     
       GetDlgItem(IDC_STATIC8)->SetWindowText("同码期数");//m_ql        
       GetDlgItem(IDC_EDIT8)->SetWindowText("10");

       GetDlgItem(IDC_STATIC9)->SetWindowText("小时速度"); 
       GetDlgItem(IDC_EDIT9)->SetWindowText("30");
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);  

       GetDlgItem(IDC_STATIC10)->SetWindowText("起始期号");           
       GetDlgItem(IDC_EDIT10)->SetWindowText("350");
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
     

       GetDlgItem(IDC_STATIC11)->SetWindowText("递减步长"); 
       GetDlgItem(IDC_EDIT11)->SetWindowText("3");
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);       

       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");	   
       GetDlgItem(IDC_STATIC13)->SetWindowText("全零期数");
	
       GetDlgItem(IDC_STATIC14)->SetWindowText("预告期数");
       GetDlgItem(IDC_EDIT14)->SetWindowText("1888");
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);


       GetDlgItem(IDC_EDIT1)->SetWindowText("1");  
       GetDlgItem(IDC_EDIT2)->SetWindowText("150");
       GetDlgItem(IDC_EDIT3)->SetWindowText("15");
       GetDlgItem(IDC_EDIT4)->SetWindowText("1100");
       GetDlgItem(IDC_EDIT5)->SetWindowText("6");
       GetDlgItem(IDC_EDIT6)->SetWindowText("4");
       GetDlgItem(IDC_EDIT7)->SetWindowText("0");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
     
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
 	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
       
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);

       
       GetDlgItem(IDC_STATIC15)->SetWindowText("购买注数");  
       GetDlgItem(IDC_EDIT15)->SetWindowText("5");		   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);


       
       GetDlgItem(IDC_STATIC17)->SetWindowText("一二范围");
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT17)->SetWindowText("3000");

       GetDlgItem(IDC_STATIC16)->SetWindowText("同态比例");
       GetDlgItem(IDC_EDIT16)->SetWindowText("0");
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   
       break;

   case 24:
       JieMian=24;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求taobao文件"); 
       dis="类型:1 短 2 长\r\n";
	   
       

	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
       GetDlgItem(IDC_STATIC1)->SetWindowText("关键词语");
	   GetDlgItem(IDC_STATIC2)->SetWindowText("文字行数");   
       GetDlgItem(IDC_STATIC3)->SetWindowText("图形行数");       
       GetDlgItem(IDC_STATIC4)->SetWindowText("类    型");       
	   GetDlgItem(IDC_STATIC5)->SetWindowText("长文行数");
       GetDlgItem(IDC_STATIC6)->SetWindowText("显示间隔");
       GetDlgItem(IDC_STATIC7)->SetWindowText("最低记录");
	   GetDlgItem(IDC_STATIC8)->SetWindowText("NX1起点");
	   GetDlgItem(IDC_STATIC9)->SetWindowText("期待遗漏");
	   GetDlgItem(IDC_STATIC10)->SetWindowText("末端检测");
	   GetDlgItem(IDC_STATIC11)->SetWindowText("最小遗漏");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
	   GetDlgItem(IDC_STATIC13)->SetWindowText("rc11文件");


	   n=100+rand()%100;

	   
	   GetDlgItem(IDC_EDIT1)->SetWindowText("1fbSs");
       GetDlgItem(IDC_EDIT2)->SetWindowText("10");
       GetDlgItem(IDC_EDIT3)->SetWindowText("100");
	   GetDlgItem(IDC_EDIT4)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT5)->SetWindowText("10000");
       GetDlgItem(IDC_EDIT6)->SetWindowText("10000");
       GetDlgItem(IDC_EDIT7)->SetWindowText("60");
	   GetDlgItem(IDC_EDIT8)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT9)->SetWindowText("70");
       GetDlgItem(IDC_EDIT10)->SetWindowText("1");
       GetDlgItem(IDC_EDIT11)->SetWindowText("70");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
	   GetDlgItem(IDC_EDIT13)->SetWindowText("");
	   

       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC14)->SetWindowText("取位下限");
	   GetDlgItem(IDC_STATIC15)->SetWindowText("取位上限");
       GetDlgItem(IDC_EDIT14)->SetWindowText("1");
       GetDlgItem(IDC_EDIT15)->SetWindowText("100");

       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT16)->SetWindowText("1000");
       GetDlgItem(IDC_EDIT17)->SetWindowText("20");
	   

       break;

   case 25:
       JieMian=25;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("处理多个目录"); 
	   dis="类型:1 更新投注文件 2 求投注文件 3 清除过期遗漏文件 4 删除abuy目录 5 复制投注文件\r\n";
           dis+="     6 更新abuy  7 初期准备  8 制作投注 9 历史回溯[35] 10 清除历史\r\n";
           dis+="     继续的回溯参数，目标天-出发天,数据文件放在data子目录中";
       GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      

       
       GetDlgItem(IDC_STATIC1)->SetWindowText("回溯天数");
	   GetDlgItem(IDC_STATIC2)->SetWindowText("类    型");
           GetDlgItem(IDC_STATIC3)->SetWindowText("开始目录");
           GetDlgItem(IDC_STATIC4)->SetWindowText("目录个数");
	   GetDlgItem(IDC_STATIC5)->SetWindowText("起    点");
           GetDlgItem(IDC_STATIC6)->SetWindowText("单纯结果");
           GetDlgItem(IDC_STATIC7)->SetWindowText("结果排序");
	   GetDlgItem(IDC_STATIC8)->SetWindowText("投注期数");
           GetDlgItem(IDC_STATIC9)->SetWindowText("调整位数");
           GetDlgItem(IDC_STATIC10)->SetWindowText("单位门槛");
       GetDlgItem(IDC_STATIC11)->SetWindowText("3H1出码");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("统码文件");
       GetDlgItem(IDC_STATIC14)->SetWindowText("3H2出码"); 
       GetDlgItem(IDC_STATIC15)->SetWindowText("购买注数");

       GetDlgItem(IDC_EDIT1)->SetWindowText("5");	   
	   GetDlgItem(IDC_EDIT2)->SetWindowText("6");	
           GetDlgItem(IDC_EDIT3)->SetWindowText("1"); 
           GetDlgItem(IDC_EDIT4)->SetWindowText("99");  
       GetDlgItem(IDC_EDIT5)->SetWindowText("1");
       GetDlgItem(IDC_EDIT6)->SetWindowText("1");
       GetDlgItem(IDC_EDIT7)->SetWindowText("1");
       GetDlgItem(IDC_EDIT8)->SetWindowText("78");         
       GetDlgItem(IDC_EDIT9)->SetWindowText("2");
       GetDlgItem(IDC_EDIT10)->SetWindowText("88");
	   GetDlgItem(IDC_EDIT11)->SetWindowText("400");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText(""); 
       GetDlgItem(IDC_EDIT14)->SetWindowText("2000");
       GetDlgItem(IDC_EDIT15)->SetWindowText("4");	

	   GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
           GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
           GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       //GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	   //GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
       //GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);	   
       //GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);	   
       //GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       
	   

       //GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	   //GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
       //GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);	   
       //GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);	   
       //GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
       
       //GetDlgItem(IDC_EDIT14)->SetWindowText("300");
       GetDlgItem(IDC_STATIC16)->SetWindowText("遍历目录");
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("1");
       GetDlgItem(IDC_EDIT17)->SetWindowText("0");

       break;

     case 26:
	   JieMian=26;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求dlc预告,数据文件45.txt"); 	   

	   dis="类型:1 更新投注文件 2 求投注文件 3 清除过期遗漏文件 4 删除abuy 5 复制投注文件\r\n";           
           dis+="参数:组数zcansu,用于1和2 复制投注为zeronum,yilou3等6个文件,用于5 \r\n";
           dis+="     如果固定投注处无参数，则复制6个,否则为1个,依顺序123456[对应345345]\r\n";

	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis); 
	  
       GetDlgItem(IDC_STATIC1)->SetWindowText("类    型");	   
       GetDlgItem(IDC_STATIC2)->SetWindowText("标准间隔");
       GetDlgItem(IDC_STATIC3)->SetWindowText("命中等值");
       GetDlgItem(IDC_STATIC4)->SetWindowText("合并标准");
       GetDlgItem(IDC_STATIC5)->SetWindowText("合成标准");  
       GetDlgItem(IDC_STATIC6)->SetWindowText("舍弃已中");  
       GetDlgItem(IDC_STATIC7)->SetWindowText("后退期数");     
       GetDlgItem(IDC_STATIC8)->SetWindowText("投注期数");//m_ql        
       GetDlgItem(IDC_EDIT8)->SetWindowText("78");

       GetDlgItem(IDC_STATIC9)->SetWindowText("小时速度"); 
       GetDlgItem(IDC_EDIT9)->SetWindowText("30");
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);  

       GetDlgItem(IDC_STATIC10)->SetWindowText("起始期号");           
       GetDlgItem(IDC_EDIT10)->SetWindowText("100");
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
     

       GetDlgItem(IDC_STATIC11)->SetWindowText("零值标准"); 
       GetDlgItem(IDC_EDIT11)->SetWindowText("1");
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);       

       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");	   
       GetDlgItem(IDC_STATIC13)->SetWindowText("固定投注");
	
       GetDlgItem(IDC_STATIC14)->SetWindowText("预告期数");
       GetDlgItem(IDC_EDIT14)->SetWindowText("2340");
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);


       GetDlgItem(IDC_EDIT1)->SetWindowText("1");  
       GetDlgItem(IDC_EDIT2)->SetWindowText("30");
       GetDlgItem(IDC_EDIT3)->SetWindowText("2");
       GetDlgItem(IDC_EDIT4)->SetWindowText("450");
       GetDlgItem(IDC_EDIT5)->SetWindowText("50");
       GetDlgItem(IDC_EDIT6)->SetWindowText("1");
       GetDlgItem(IDC_EDIT7)->SetWindowText("0");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
     
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
 	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
       
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);

       
	   
              GetDlgItem(IDC_STATIC15)->SetWindowText("购买注数");  
       GetDlgItem(IDC_EDIT15)->SetWindowText("4");		   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC17)->SetWindowText("全遗结束");
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT17)->SetWindowText("1000");

       GetDlgItem(IDC_STATIC16)->SetWindowText("全遗开始");
       GetDlgItem(IDC_EDIT16)->SetWindowText("0");
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   
       break;

     case 27:
       JieMian=27;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("制作dlc数据文件"); 
           dis="类型:1(近期文件+远期文件) 2(从彩经网提取近期文件) 3(从快彩乐提取一天数据文件)";
           dis=dis+"通常近期文件名44.txt,远期文件名45.txt,合成后的文件也为45.txt\r\n";
           dis=dis+"快彩日期格式:yyyy-mm-dd,无数据则提取当天数据";
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
       
       GetDlgItem(IDC_STATIC1)->SetWindowText("快彩日期");
       GetDlgItem(IDC_STATIC2)->SetWindowText("类    型");
       GetDlgItem(IDC_STATIC3)->SetWindowText("补足近期");
       GetDlgItem(IDC_STATIC4)->SetWindowText("彩经页数");
       GetDlgItem(IDC_STATIC5)->SetWindowText("彩经开始");
       GetDlgItem(IDC_EDIT5)->SetWindowText("1");
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	  
       GetDlgItem(IDC_STATIC12)->SetWindowText("近期文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("远期文件");

       GetDlgItem(IDC_EDIT1)->SetWindowText("");	   
       GetDlgItem(IDC_EDIT2)->SetWindowText("1");
       GetDlgItem(IDC_EDIT3)->SetWindowText("1");
       GetDlgItem(IDC_EDIT4)->SetWindowText("1");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
       
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   

       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
	   
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);
	   
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
       
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT14)->SetWindowText("2");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("118");
	   
       break;

     case 28:
       JieMian=28;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("文本文件相关操作"); 
	   dis="类型:1(行数)2(取行,行数)3(取行,百分)4(分割,文件行数)5(分割,文件数)";
	   dis=dis+"6(加行号)7(删除文件夹)\r\n";  
	   dis=dis+"类型为4时,分割数量表示分割后每文件行数;";
       dis=dis+"类型为5时,分割数量表示分割成几个文件";           
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
       
	   GetDlgItem(IDC_STATIC1)->SetWindowText("遗漏区间");
       GetDlgItem(IDC_STATIC2)->SetWindowText("类    型");
       GetDlgItem(IDC_STATIC5)->SetWindowText("起    点");
       GetDlgItem(IDC_STATIC6)->SetWindowText("取    量");
       GetDlgItem(IDC_STATIC7)->SetWindowText(" 7去方括");
       GetDlgItem(IDC_STATIC8)->SetWindowText("分割数量");
       GetDlgItem(IDC_STATIC9)->SetWindowText("分期高遗");
       GetDlgItem(IDC_STATIC10)->SetWindowText("最低高遗");
       GetDlgItem(IDC_STATIC11)->SetWindowText("7 已排序");
       GetDlgItem(IDC_STATIC12)->SetWindowText("文本文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("检查文件");

	   GetDlgItem(IDC_EDIT1)->SetWindowText("");
	   GetDlgItem(IDC_EDIT2)->SetWindowText("1");
       GetDlgItem(IDC_EDIT5)->SetWindowText("1000");//m_btui
       GetDlgItem(IDC_EDIT6)->SetWindowText("60000");
       GetDlgItem(IDC_EDIT7)->SetWindowText("1");
       GetDlgItem(IDC_EDIT8)->SetWindowText("3"); 
       GetDlgItem(IDC_EDIT9)->SetWindowText("1"); 
       GetDlgItem(IDC_EDIT10)->SetWindowText("400"); 
       GetDlgItem(IDC_EDIT11)->SetWindowText("1");      
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");

	   GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
      

       
       
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   

       
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
       
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
	   
       GetDlgItem(IDC_EDIT14)->SetWindowText("2");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("118");
	   
       break;

   case 29:
       JieMian=29;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssqend的统一后退变形码后退期文件,数据文件ssqdata.txt"); 
	   GetDlgItem(IDC_STATICdetail)->SetWindowText("");      
       
          
	   GetDlgItem(IDC_STATIC5)->SetWindowText("后退开始");
	   GetDlgItem(IDC_STATIC6)->SetWindowText("后退截止");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       
	   

      
	   GetDlgItem(IDC_EDIT5)->SetWindowText("30");
       GetDlgItem(IDC_EDIT6)->SetWindowText("800");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       
       
	   GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
	   
       
	   GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);       
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC13)->ShowWindow(SW_HIDE);
       
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);       
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT13)->ShowWindow(SW_HIDE);
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
       
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT14)->SetWindowText("2");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("118");

       break;

   case 36:
       JieMian=36;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("制作mega millions数据文件"); 
           dis="   如果提取页数大于实际页数或者小于1，则提取全部数据，否则提取设置页数\r\n";
           dis+="   起始期号为所提取的最早数据的期号，要按实际情况设置。如果提取全部，请保持为1";
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
       
       GetDlgItem(IDC_STATIC2)->SetWindowText("提取页数");
       GetDlgItem(IDC_STATIC3)->SetWindowText("起始期号");
       GetDlgItem(IDC_STATIC4)->SetWindowText("彩经页数");
       GetDlgItem(IDC_STATIC5)->SetWindowText("彩经开始");
       GetDlgItem(IDC_EDIT5)->SetWindowText("1");
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);

       GetDlgItem(IDC_STATIC12)->SetWindowText("数据目录");
       GetDlgItem(IDC_STATIC13)->SetWindowText("远期文件");
       GetDlgItem(IDC_EDIT2)->SetWindowText("100000");
       GetDlgItem(IDC_EDIT3)->SetWindowText("1");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       GetDlgItem(IDC_EDIT4)->SetWindowText("5");
       GetDlgItem(IDC_EDIT6)->SetWindowText("10000");
 
       
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_HIDE);
	   

       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_HIDE);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);

	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
	   
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);

	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);
	   
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT14)->SetWindowText("2");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("118");
	   
       break;

   case 37:
       JieMian=37;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求mega预告,数据文件mega.txt"); 	   

           dis+="1 求投注文件 2 核对投注文件   3 复制投注文件\r\n";
           dis+="参数:组数zcansu,用于1和2 复制投注为copyhao,用于3\r\n";
       
	  GetDlgItem(IDC_STATICdetail)->SetWindowText(dis); 
	  
       GetDlgItem(IDC_STATIC1)->SetWindowText("类    型");	   
       GetDlgItem(IDC_STATIC2)->SetWindowText("标准间隔");
       GetDlgItem(IDC_STATIC3)->SetWindowText("命中等值");
       GetDlgItem(IDC_STATIC4)->SetWindowText("合并标准");
       GetDlgItem(IDC_STATIC5)->SetWindowText("顺序个数");  
       GetDlgItem(IDC_STATIC6)->SetWindowText("反序个数");  
       GetDlgItem(IDC_STATIC7)->SetWindowText("后退期数");     
       GetDlgItem(IDC_STATIC8)->SetWindowText("同码期数");//m_ql        
       GetDlgItem(IDC_EDIT8)->SetWindowText("10");

       GetDlgItem(IDC_STATIC9)->SetWindowText("小时速度"); 
       GetDlgItem(IDC_EDIT9)->SetWindowText("1");
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);  

       GetDlgItem(IDC_STATIC10)->SetWindowText("起始期号");           
       GetDlgItem(IDC_EDIT10)->SetWindowText("600");
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
     

       GetDlgItem(IDC_STATIC11)->SetWindowText("零值标准"); 
       GetDlgItem(IDC_EDIT11)->SetWindowText("10");
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);       

       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");	   
       GetDlgItem(IDC_STATIC13)->SetWindowText("固定投注");
	
       GetDlgItem(IDC_STATIC14)->SetWindowText("预告期数");
       GetDlgItem(IDC_EDIT14)->SetWindowText("100");
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);


       GetDlgItem(IDC_EDIT1)->SetWindowText("1");  
       GetDlgItem(IDC_EDIT2)->SetWindowText("375");
       GetDlgItem(IDC_EDIT3)->SetWindowText("27");
       GetDlgItem(IDC_EDIT4)->SetWindowText("3900");
       GetDlgItem(IDC_EDIT5)->SetWindowText("7");
       GetDlgItem(IDC_EDIT6)->SetWindowText("3");
       GetDlgItem(IDC_EDIT7)->SetWindowText(Cstr(rand()%20));
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
     
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
 	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
       
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);

       
	   
              GetDlgItem(IDC_STATIC15)->SetWindowText("购买注数");  
       GetDlgItem(IDC_EDIT15)->SetWindowText("500");		   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC17)->SetWindowText("一二范围");
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT17)->SetWindowText("3000");

       GetDlgItem(IDC_STATIC16)->SetWindowText("同态比例");
       GetDlgItem(IDC_EDIT16)->SetWindowText("0");
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   
       break;

     case 38:
	   JieMian=38;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssqend的映射码预告,数据文件ssqend.txt"); 
	   GetDlgItem(IDC_STATICdetail)->SetWindowText("");      
       
       GetDlgItem(IDC_STATIC5)->SetWindowText("历史期数");    	  
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("统后退码");
	   
/////////////.......
       GetDlgItem(IDC_EDIT5)->SetWindowText("800");	   
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
       
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT14)->SetWindowText("2");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("118");
	   
       break; 

   case 39:

       JieMian=39;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssq映射码后退期文件,数据文件ssqdata.txt"); 
	   dis="类型:1(最长遗漏) 2(分段)\r\n";
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
       
       GetDlgItem(IDC_STATIC1)->SetWindowText("分段模式");
       GetDlgItem(IDC_STATIC2)->SetWindowText("类    型");   	  
       GetDlgItem(IDC_STATIC3)->SetWindowText("选码个数");       
       GetDlgItem(IDC_STATIC4)->SetWindowText("期待码数");       
	   GetDlgItem(IDC_STATIC5)->SetWindowText("后退开始");
       GetDlgItem(IDC_STATIC6)->SetWindowText("后退结束");
	   GetDlgItem(IDC_STATIC8)->SetWindowText("单期次数");
	   GetDlgItem(IDC_STATIC9)->SetWindowText("期待遗漏");
  	   GetDlgItem(IDC_STATIC10)->SetWindowText("末端检测");
	   GetDlgItem(IDC_STATIC11)->SetWindowText("最低遗漏");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       n=30+rand()%30;
	   
       GetDlgItem(IDC_EDIT1)->SetWindowText("100[0$100]-300[0$300]");
       GetDlgItem(IDC_EDIT2)->SetWindowText("1");
       GetDlgItem(IDC_EDIT3)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT4)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT5)->SetWindowText(Cstr(n));
       GetDlgItem(IDC_EDIT6)->SetWindowText(Cstr(n+100));
	   GetDlgItem(IDC_EDIT8)->SetWindowText("999999");
	   GetDlgItem(IDC_EDIT9)->SetWindowText("55");
       GetDlgItem(IDC_EDIT10)->SetWindowText("3");
       GetDlgItem(IDC_EDIT11)->SetWindowText("55");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");

       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);

	   
       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       
       
       
	   GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);       	          
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_HIDE);
	   
       
	   

       
	   GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);       	                
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_HIDE);
	   
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
       
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
	   
       GetDlgItem(IDC_EDIT14)->SetWindowText("2");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("118");

       break;

   case 40:
       JieMian=40;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("更新ssq映射码后退期文件,数据文件ssqdata.txt"); 
       GetDlgItem(IDC_STATICdetail)->SetWindowText("类型:1(普通)2(扩展) 当为类型1时,超出出码期数者,记入chuma文件中");      
       
	   GetDlgItem(IDC_STATIC2)->SetWindowText("最低遗漏");
           GetDlgItem(IDC_STATIC3)->SetWindowText("后退期数");
           GetDlgItem(IDC_STATIC4)->SetWindowText("删原文件");
	   GetDlgItem(IDC_STATIC5)->SetWindowText("起    点");
           GetDlgItem(IDC_STATIC6)->SetWindowText("单纯结果");
           GetDlgItem(IDC_STATIC7)->SetWindowText("结果排序");
	   GetDlgItem(IDC_STATIC8)->SetWindowText("类    型");
           GetDlgItem(IDC_STATIC9)->SetWindowText("调整位数");
           GetDlgItem(IDC_STATIC10)->SetWindowText("单位门槛");
	   GetDlgItem(IDC_STATIC11)->SetWindowText("出码期数");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("统码文件");
       GetDlgItem(IDC_STATIC14)->SetWindowText("群体更新");

	   GetDlgItem(IDC_EDIT2)->SetWindowText("1100");
	   GetDlgItem(IDC_EDIT3)->SetWindowText("600");
	   GetDlgItem(IDC_EDIT4)->SetWindowText("1");

	   GetDlgItem(IDC_EDIT5)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT6)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT7)->SetWindowText("1");

	   GetDlgItem(IDC_EDIT8)->SetWindowText("1");
           GetDlgItem(IDC_EDIT9)->SetWindowText("2");
           GetDlgItem(IDC_EDIT10)->SetWindowText("85");
       GetDlgItem(IDC_EDIT11)->SetWindowText("0");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	   //GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	   //GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
       
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
	   
       GetDlgItem(IDC_EDIT14)->SetWindowText("0");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
       	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       
       GetDlgItem(IDC_EDIT17)->SetWindowText("0");

       GetDlgItem(IDC_STATIC16)->SetWindowText("遍历目录"); 
       GetDlgItem(IDC_EDIT16)->SetWindowText("1");  
       GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);


       break;

     case 41:
	   JieMian=41;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssq1预告,数据文件ssqdata.txt"); 	   

           dis+="1 求投注文件 2 核对投注文件   3 复制投注文件\r\n";
           dis+="参数:组数zcansu,用于1和2 复制投注为copyhao,用于3\r\n";

       
	  GetDlgItem(IDC_STATICdetail)->SetWindowText(dis); 
	  
       GetDlgItem(IDC_STATIC1)->SetWindowText("类    型");	   
       GetDlgItem(IDC_STATIC2)->SetWindowText("标准间隔");
       GetDlgItem(IDC_STATIC3)->SetWindowText("命中等值");
       GetDlgItem(IDC_STATIC4)->SetWindowText("合并标准");
       GetDlgItem(IDC_STATIC5)->SetWindowText("购买组数");  
       GetDlgItem(IDC_STATIC6)->SetWindowText("每组个数");  
       GetDlgItem(IDC_STATIC7)->SetWindowText("后退期数");     
       GetDlgItem(IDC_STATIC8)->SetWindowText("同码期数");//m_ql        
       GetDlgItem(IDC_EDIT8)->SetWindowText("10");

       GetDlgItem(IDC_STATIC9)->SetWindowText("小时速度"); 
       GetDlgItem(IDC_EDIT9)->SetWindowText("1");
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);  

       GetDlgItem(IDC_STATIC10)->SetWindowText("起始期号");           
       GetDlgItem(IDC_EDIT10)->SetWindowText("200");
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
     

       GetDlgItem(IDC_STATIC11)->SetWindowText("零值标准"); 
       GetDlgItem(IDC_EDIT11)->SetWindowText("10");
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);       

       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");	   
       GetDlgItem(IDC_STATIC13)->SetWindowText("固定投注");
	
       GetDlgItem(IDC_STATIC14)->SetWindowText("预告期数");
       GetDlgItem(IDC_EDIT14)->SetWindowText("100");
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);


       GetDlgItem(IDC_EDIT1)->SetWindowText("1");  
       GetDlgItem(IDC_EDIT2)->SetWindowText("90");
       GetDlgItem(IDC_EDIT3)->SetWindowText("10");
       GetDlgItem(IDC_EDIT4)->SetWindowText("1200");
       GetDlgItem(IDC_EDIT5)->SetWindowText("12000");
       GetDlgItem(IDC_EDIT6)->SetWindowText("10");
       GetDlgItem(IDC_EDIT7)->SetWindowText(Cstr(rand()%10));
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("03,06,08,10,22,23:03");
       
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
     
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
 	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
       
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);

       
	   
              GetDlgItem(IDC_STATIC15)->SetWindowText("购买注数");  
       GetDlgItem(IDC_EDIT15)->SetWindowText("500");		   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC17)->SetWindowText("一二范围");
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT17)->SetWindowText("3000");

       GetDlgItem(IDC_STATIC16)->SetWindowText("同态比例");
       GetDlgItem(IDC_EDIT16)->SetWindowText("0");
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   
       break;
     case 42:
	   JieMian=42;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求dlc的映射码群码预告,数据文件45new.txt，另外需要用于预告的映射码文件"); 
           
           dis=    "建议参数:1(30)  2(150) 3(1388)\r\n";
           dis=dis+"建议白数:1(120) 2(600) 3(5500)\r\n";
           dis=dis+"建议大数:1(55)  2(275) 3(2500)";

	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
           
           GetDlgItem(IDC_STATIC1)->SetWindowText("特别组合");
   	   GetDlgItem(IDC_STATIC2)->SetWindowText("组合数量");
           GetDlgItem(IDC_STATIC3)->SetWindowText("是否排序");
           GetDlgItem(IDC_STATIC4)->SetWindowText("查看特别");
       GetDlgItem(IDC_STATIC5)->SetWindowText("历史期数");   
       GetDlgItem(IDC_STATIC6)->SetWindowText("计算范围");
       GetDlgItem(IDC_STATIC7)->SetWindowText("遍历文件");
	   GetDlgItem(IDC_STATIC8)->SetWindowText("起始期号");  
           GetDlgItem(IDC_STATIC9)->SetWindowText("预告期数");  
           GetDlgItem(IDC_STATIC10)->SetWindowText("输出白数");  
	   GetDlgItem(IDC_STATIC11)->SetWindowText("类    型");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("映码文件");


       GetDlgItem(IDC_EDIT1)->SetWindowText("1");   
       GetDlgItem(IDC_EDIT2)->SetWindowText("1003");
       GetDlgItem(IDC_EDIT3)->SetWindowText("1");
       GetDlgItem(IDC_EDIT4)->SetWindowText("0");
       GetDlgItem(IDC_EDIT5)->SetWindowText("120");
       GetDlgItem(IDC_EDIT6)->SetWindowText("1"); 
       GetDlgItem(IDC_EDIT7)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT8)->SetWindowText("0");
           GetDlgItem(IDC_EDIT9)->SetWindowText("2000");
           GetDlgItem(IDC_EDIT10)->SetWindowText("120");
	   GetDlgItem(IDC_EDIT11)->SetWindowText("30");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
           GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
       
	   GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);	   
       
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);	   
       
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT14)->SetWindowText("30");
       GetDlgItem(IDC_EDIT15)->SetWindowText("20000");
       GetDlgItem(IDC_STATIC14)->SetWindowText("删除过期"); //m_wb
       GetDlgItem(IDC_STATIC15)->SetWindowText("入选数目"); //m_we
	
       GetDlgItem(IDC_STATIC16)->SetWindowText("排序低限");
       GetDlgItem(IDC_STATIC17)->SetWindowText("排序高限");   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT16)->SetWindowText("1");
       GetDlgItem(IDC_EDIT17)->SetWindowText("11");
       
	   
       break; 

     case 43:
	   JieMian=43;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssc的固定码不定位预告,数据文件29.txt"); 
           dis="类型:1(前) 2(后)\r\n";
           dis=dis+"记录:1(15) 2(78) 3(688)\r\n";
           dis=dis+"6为统计,此时历史期数设为1000000;每段长度与共分段数之积应为600,不满足则取缺省值";
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis) ;      
       
        GetDlgItem(IDC_STATIC1)->SetWindowText("遗漏分布");
        GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT1)->SetWindowText("20,6,6,1");
        GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);

        GetDlgItem(IDC_STATIC2)->SetWindowText("位或统计");
        GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT2)->SetWindowText("1");
        GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC3)->SetWindowText("第一期数");
        GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT3)->SetWindowText("1000000");
        GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC4)->SetWindowText("历史记录");
        GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT4)->SetWindowText("0");
        GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);


        GetDlgItem(IDC_STATIC5)->SetWindowText("重位期数");
        GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT5)->SetWindowText("10");
        GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC6)->SetWindowText("共分段数");//m_etui
        GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT6)->SetWindowText("600");
        GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC7)->SetWindowText("每段长度");//m_step
        GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT7)->SetWindowText("1");
        GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC8)->SetWindowText("第二期数");//m_ql
        GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT8)->SetWindowText("1000");
        GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC9)->SetWindowText("第二门槛");
        GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT9)->SetWindowText("2");
        GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);

        GetDlgItem(IDC_STATIC10)->SetWindowText("第二次数");
        GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT10)->SetWindowText("2");
        GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE);

        GetDlgItem(IDC_STATIC11)->SetWindowText("选出列数");
        GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT11)->SetWindowText("252");
        GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);

        GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
        GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT12)->SetWindowText("");
        GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC13)->SetWindowText("预告文件");
        GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT13)->SetWindowText("");
        GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

        GetDlgItem(IDC_STATIC14)->SetWindowText("双位遗漏");
        GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT14)->SetWindowText("0");
        GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);

        GetDlgItem(IDC_STATIC15)->SetWindowText("入选数目");
        GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT15)->SetWindowText("20000");
        GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);

        GetDlgItem(IDC_STATIC16)->SetWindowText("");
        GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT16)->SetWindowText("0");
        GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);

        GetDlgItem(IDC_STATIC17)->SetWindowText("");
        GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT17)->SetWindowText("0");
        GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);


       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);       
	   
       break; 


     case 44:
       JieMian=44;
       GetDlgItem(IDC_STATIChead)->SetWindowText("去掉映射码中的遗漏次数或删除过时文件");  
       dis="类型:1(去刺)2(留刺)3(删除过时)4(删除重复文件[前10行相同])\r\n";
       dis=dis+"去刺用作以后去掉大遗漏码中的重复项；留刺用作手机文件";
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);
       GetDlgItem(IDC_STATIC11)->SetWindowText("类  型");
       GetDlgItem(IDC_EDIT11)->SetWindowText("3");
	   GetDlgItem(IDC_STATIC12)->SetWindowText("映码文件");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_STATIC13)->SetWindowText("删除重复");
       GetDlgItem(IDC_EDIT13)->SetWindowText("1");

       GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_HIDE);

	   GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW); 
        
       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW); 
       GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE); 
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW); 

       GetDlgItem(IDC_STATIC2)->SetWindowText("s 标准");
       GetDlgItem(IDC_STATIC3)->SetWindowText("t 标准");
       GetDlgItem(IDC_STATIC4)->SetWindowText("y 标准");
       GetDlgItem(IDC_STATIC5)->SetWindowText("z 标准");
       
       GetDlgItem(IDC_EDIT2)->SetWindowText("0");//m_num
       GetDlgItem(IDC_EDIT3)->SetWindowText("0");//m_mas
       GetDlgItem(IDC_EDIT4)->SetWindowText("0");//m_qmas
       GetDlgItem(IDC_EDIT5)->SetWindowText("0");//m_btui


       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE); 
	   
       
	   
	   
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT14)->SetWindowText("2");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("118");
       
       
       break;
     case 45:
	   JieMian=45;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssq的映射码群码预告,数据文件ssqdata.txt，另外需要用于预告的映射码文件"); 
           dis="建议参数:1(62) 2(468) 3(ubound-330 or 3100)";
     
	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      

	   
       GetDlgItem(IDC_STATIC1)->SetWindowText("指定蓝球");
	   GetDlgItem(IDC_STATIC2)->SetWindowText("组合数量");
       
       GetDlgItem(IDC_STATIC5)->SetWindowText("历史期数"); 
       GetDlgItem(IDC_STATIC6)->SetWindowText("计算范围");     
           GetDlgItem(IDC_STATIC9)->SetWindowText("输出白数"); //m_b
           GetDlgItem(IDC_STATIC10)->SetWindowText("删除过期"); //m_e
	   
       GetDlgItem(IDC_STATIC11)->SetWindowText("类    型"); 

       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("映码文件");
	   
       GetDlgItem(IDC_EDIT1)->SetWindowText("1");
       GetDlgItem(IDC_EDIT2)->SetWindowText("1005");
       
       GetDlgItem(IDC_EDIT5)->SetWindowText("10000");
       GetDlgItem(IDC_EDIT6)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT8)->SetWindowText("120");
           GetDlgItem(IDC_EDIT9)->SetWindowText("0");
           GetDlgItem(IDC_EDIT10)->SetWindowText("90");
           
       GetDlgItem(IDC_EDIT11)->SetWindowText("90");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
	   GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
       
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       
	   
       

	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
	   
       
	   

       
       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
	   
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
       
       GetDlgItem(IDC_STATIC3)->SetWindowText("是否排序"); 
       GetDlgItem(IDC_EDIT3)->SetWindowText("1");
       
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
      GetDlgItem(IDC_STATIC8)->SetWindowText("起始期号"); 



       GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);       
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);       
       GetDlgItem(IDC_EDIT4)->SetWindowText("0");        
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);	
       GetDlgItem(IDC_EDIT7)->SetWindowText("1");
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC4)->SetWindowText("查看特别");        
        GetDlgItem(IDC_STATIC7)->SetWindowText("遍历文件");
       GetDlgItem(IDC_STATIC16)->SetWindowText("排序低限");
       GetDlgItem(IDC_STATIC17)->SetWindowText("排序高限"); 	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT16)->SetWindowText("1");
       GetDlgItem(IDC_EDIT17)->SetWindowText("33");
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT14)->SetWindowText("5000");
       GetDlgItem(IDC_EDIT15)->SetWindowText("0");
       GetDlgItem(IDC_STATIC14)->SetWindowText("遗漏限制"); //m_wb
       GetDlgItem(IDC_STATIC15)->SetWindowText("最低次数"); //m_we
	   
       break; 

     case 46:
	   JieMian=46;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssqend的映射码群码预告,数据文件ssqdata.txt，另外需要用于预告的映射码文件"); 
           dis="建议参数:180";

	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis); 
       
GetDlgItem(IDC_STATIC1)->SetWindowText("特别组合");
GetDlgItem(IDC_EDIT1)->SetWindowText("1"); 	   
       
	   GetDlgItem(IDC_STATIC2)->SetWindowText("组合数量");
          GetDlgItem(IDC_STATIC3)->SetWindowText("是否排序");
       GetDlgItem(IDC_STATIC5)->SetWindowText("历史期数");   
	   GetDlgItem(IDC_STATIC8)->SetWindowText("起始期号");  
           GetDlgItem(IDC_STATIC9)->SetWindowText("输出白数");
           GetDlgItem(IDC_STATIC10)->SetWindowText("删除过期"); 
	   GetDlgItem(IDC_STATIC11)->SetWindowText("类    型");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("映码文件");
	   
       GetDlgItem(IDC_EDIT2)->SetWindowText("1005");
       GetDlgItem(IDC_EDIT3)->SetWindowText("1");
       GetDlgItem(IDC_EDIT5)->SetWindowText("10000");
	   GetDlgItem(IDC_EDIT8)->SetWindowText("300");
           GetDlgItem(IDC_EDIT9)->SetWindowText("0");
           GetDlgItem(IDC_EDIT10)->SetWindowText("280");
	   GetDlgItem(IDC_EDIT11)->SetWindowText("280");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);

       
       
       GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);       
       GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);       
       GetDlgItem(IDC_EDIT4)->SetWindowText("0");        
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);	
       GetDlgItem(IDC_EDIT7)->SetWindowText("1");
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC4)->SetWindowText("查看特别");        
        GetDlgItem(IDC_STATIC7)->SetWindowText("遍历文件");
       GetDlgItem(IDC_STATIC16)->SetWindowText("排序低限");
       GetDlgItem(IDC_STATIC17)->SetWindowText("排序高限"); 	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT16)->SetWindowText("1");
       GetDlgItem(IDC_EDIT17)->SetWindowText("16");	
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT14)->SetWindowText("3000");
       GetDlgItem(IDC_EDIT15)->SetWindowText("0");
       GetDlgItem(IDC_STATIC14)->SetWindowText("遗漏限制"); //m_wb
       GetDlgItem(IDC_STATIC15)->SetWindowText("最低次数"); //m_we
   
	   
       break; 

     case 47:
	   JieMian=47;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("根据两个码dlc的预告,数据文件45new.txt"); 
	   GetDlgItem(IDC_STATICdetail)->SetWindowText("类型:1(任选) 2(直选) 3(组选) 两个码以#分开");      
       
       GetDlgItem(IDC_STATIC5)->SetWindowText("历史期数");    
	   
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("统后退码");
	   

       GetDlgItem(IDC_EDIT5)->SetWindowText("500");
	  
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
       
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
       
       GetDlgItem(IDC_EDIT14)->SetWindowText("2");
       GetDlgItem(IDC_EDIT15)->SetWindowText("2");	   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
       GetDlgItem(IDC_EDIT16)->SetWindowText("118");
       GetDlgItem(IDC_EDIT17)->SetWindowText("118");
	   
       break; 
     case 48:
	   JieMian=48;
	   GetDlgItem(IDC_STATIChead)->SetWindowText("求ssczx的映射码群码预告,数据文件29new.txt，另外需要用于预告的映射码文件"); 
           dis="建议参数:1(105)  2(1050)  3(10500)  5(5250)  31(38)  41(28)\r\n";
       dis=dis+"建议白数:1(1050) 2(10500) 3(105000) 5(52500) 31(380) 41(100)\r\n";
       dis=dis+"建议大数:1(180)  2(18000) 3(18000)  5(9000)  31(55)  41(35)";


	   GetDlgItem(IDC_STATICdetail)->SetWindowText(dis);      
           
           GetDlgItem(IDC_STATIC1)->SetWindowText("特别组合");
   	   GetDlgItem(IDC_STATIC2)->SetWindowText("取码周期");
           GetDlgItem(IDC_STATIC3)->SetWindowText("是否排序");
           GetDlgItem(IDC_STATIC4)->SetWindowText("是否发散");
       GetDlgItem(IDC_STATIC5)->SetWindowText("历史期数");   
       GetDlgItem(IDC_STATIC6)->SetWindowText("计算范围");
        GetDlgItem(IDC_STATIC7)->SetWindowText("遍历文件");
	   GetDlgItem(IDC_STATIC8)->SetWindowText("起始期号");  
           GetDlgItem(IDC_STATIC9)->SetWindowText("预告期数");  
           
	   GetDlgItem(IDC_STATIC11)->SetWindowText("类    型");
       GetDlgItem(IDC_STATIC12)->SetWindowText("数据文件");
       GetDlgItem(IDC_STATIC13)->SetWindowText("映码文件");
       GetDlgItem(IDC_EDIT1)->SetWindowText("1");   
       GetDlgItem(IDC_EDIT2)->SetWindowText("300");
       GetDlgItem(IDC_EDIT3)->SetWindowText("1");
       GetDlgItem(IDC_EDIT4)->SetWindowText("0");
       GetDlgItem(IDC_EDIT5)->SetWindowText("50000");
       GetDlgItem(IDC_EDIT6)->SetWindowText("3");
       GetDlgItem(IDC_EDIT7)->SetWindowText("1");
	   GetDlgItem(IDC_EDIT8)->SetWindowText("11000");
           GetDlgItem(IDC_EDIT9)->SetWindowText("35000");
       GetDlgItem(IDC_EDIT10)->SetWindowText("3000");  
         
	   GetDlgItem(IDC_EDIT11)->SetWindowText("11000");
       GetDlgItem(IDC_EDIT12)->SetWindowText("");
       GetDlgItem(IDC_EDIT13)->SetWindowText("");
        GetDlgItem(IDC_EDIT14)->SetWindowText("11000");
       GetDlgItem(IDC_EDIT15)->SetWindowText("20000");
          GetDlgItem(IDC_EDIT16)->SetWindowText("1");
       GetDlgItem(IDC_EDIT17)->SetWindowText("10");  
   
	   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
           GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
           GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
	   
	   GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
       
	   GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);

       
       GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	   
       GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);	   
       
	   
       
	   

       GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);       
	   GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);	   
       
	  
       
       
       GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);

       GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC14)->SetWindowText("删除过期"); //m_wb
       GetDlgItem(IDC_STATIC15)->SetWindowText("入选数目"); //m_we
	
       GetDlgItem(IDC_STATIC16)->SetWindowText("排序低限");
       GetDlgItem(IDC_STATIC17)->SetWindowText("排序高限");   
       GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);	   
       GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);	   
	   GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	   GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC10)->SetWindowText("输出白数"); 
        GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
       GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
       break; 





  }
}

void CMy115backDlg::DoEvents()
{

MSG msg;
while (PeekMessage(&msg, (HWND)NULL, 0, 0, PM_REMOVE) )//判断是否有消息
{
   TranslateMessage(&msg);
   DispatchMessage(&msg);
}
}












CString CMy115backDlg::delern(CString s)
{
   int l=s.GetLength();
   CString t,c;
   for (int i=0;i<l;i++){
     c=s.Mid(i,1);
	 if (c!="\r" && c!="\n"){t=t+c;}
   }
   return t;
}

















   






void CMy115backDlg::OnButton34() 
{
   if (JieMian!=39){jiemian(39);return;}
   setbutton(FALSE);
   UpdateData(TRUE); 
   MessageBox("程序结束!");setbutton(TRUE);
	
}







void CMy115backDlg::OnButton43() 
{
  
  if (JieMian!=42){jiemian(42);return;} 
   setbutton(FALSE);
   UpdateData(TRUE); 
  MessageBox("程序结束!");setbutton(TRUE);


}




void CMy115backDlg::OnButton44() 
{
  if (JieMian!=44){jiemian(44);return;}  
  UpdateData(TRUE); 	
}

void CMy115backDlg::tui(CStdioFile &file1,CStdioFile &file2)
{
	if (tuichu==1){file1.Close();file2.Close();}
	//if (tuichu==1){file1.Close();file2.Close();PostQuitMessage(0);}
}

void CMy115backDlg::OnButton45() 
{
   tuichu=1;  
	
}

void CMy115backDlg::tui(CStdioFile &file)
{
  if (tuichu==1){file.Close();}
  //if (tuichu==1){file.Close();PostQuitMessage(0); }
}

void CMy115backDlg::OnCancel()

{
  tuichu=1;
  CDialog::OnCancel(); 

}






void CMy115backDlg::OnButton33() 
{

  if (JieMian!=48){jiemian(48);return;} 
   setbutton(FALSE);
   UpdateData(TRUE); 
   MessageBox("程序结束!");setbutton(TRUE);

}

void CMy115backDlg::getjiangstate(CString fang, CString data[], long ubound,int djiang,CStdioFile &out)
{

   CString s,method[100],wr,li,fangs;
   int zusu,cisu,xflag,ci,ml,i,j,r,k,pos,zuidi,zuigao,buchang=0,onetou=0,yilou,azusu[100],acisu[100];
   long tou,jiang,ljiang;
   float fjiang;
   if  (fang.Find("+")<0){ml=1;method[0]=fang;}
   else {Split(fang,method,ml,"+");ml=ml+1;}
   
   //MessageBox(Cstr(djiang)+"  "+Cstr(ml));   
   for (i=0;i<ml;i++){
     s=method[i];	 
	 pos=s.Find("*");
	 zusu=atoi(s.Left(pos));
	 cisu=atoi(s.Mid(pos+1));
	 acisu[i]=cisu;
	 azusu[i]=zusu;
	 onetou=onetou+zusu*2*cisu;
     buchang=buchang+cisu;
   }
   pos=data[0].Find(":");
   zuidi=atoi(data[0].Left(pos));
   pos=data[ubound].Find(":");
   zuigao=atoi(data[ubound].Left(pos))-buchang;
   //long oldtou,oldj;
  
   for (i=zuidi;i<=zuigao;i++){
	 tou=0;
	 jiang=0;
	 ci=0;
     for (j=0;j<=ubound;j++){
       s=data[j];
	   //MessageBox(s);
	   pos=s.Find(":");
       yilou=atoi(s.Left(pos));
       //MessageBox(Cstr(yilou));
       r=yilou-i;
	   //MessageBox(Cstr(r));
	   if (r<=0){continue;}
	   xflag=0;
	   //oldtou=tou;oldj=jiang;
       for(k=0;k<ml;k++){
         //MessageBox(Cstr(r)+"  "+Cstr(acisu[k]));
		 if (r<=acisu[k]){tou=tou+r*2*azusu[k];jiang=jiang+djiang*azusu[k];xflag=1;break;}
		 else{tou=tou+acisu[k]*2*azusu[k];r=r-acisu[k];}
       }
       //MessageBox(Cstr(yilou)+"  "+Cstr(i)+"  "+Cstr(oldtou)+"  "+Cstr(oldj)+"  "+Cstr(tou)+"  "+Cstr(jiang));
	   if (xflag==1){ci=ci+1;}
     }//for (i=0;i<=ubound;i++){
	 //MessageBox(Cstr(tou)+"  "+Cstr(jiang));
     fjiang=jiang/1.0;
	 fjiang=fjiang/tou;
	 fjiang=fjiang*100;
     ljiang=long(fjiang);	 
     li=Cstr(ljiang);
     li=padstrcisu(li,8," ",0);
     fangs=Cstr(i)+"-"+fang;
	 fangs=padstrcisu(fangs,30," ",0);
	 wr=li+fangs+padstrcisu(Cstr(ci),5," ",0)+padstrcisu(Cstr(tou),8," ",0)+padstrcisu(Cstr(jiang),8," ",0);
     out.Write(wr+"\r\n",wr.GetLength()+2);


   }//for (i=zuidi;i<=zuigao;i++)
 

}











void CMy115backDlg::setbutton(bool x)
{
  CButton *pBtn1 = (CButton *)GetDlgItem(IDC_BUTTON1);
  if(pBtn1 != NULL){pBtn1->EnableWindow(x);}

  CButton *pBtn2 = (CButton *)GetDlgItem(IDC_BUTTON2);
  if(pBtn2 != NULL){pBtn2->EnableWindow(x);}

  CButton *pBtn3 = (CButton *)GetDlgItem(IDC_BUTTON3);
  if(pBtn3 != NULL){pBtn3->EnableWindow(x);}

  CButton *pBtn4 = (CButton *)GetDlgItem(IDC_BUTTON4);
  if(pBtn4 != NULL){pBtn4->EnableWindow(x);}

  CButton *pBtn5 = (CButton *)GetDlgItem(IDC_BUTTON5);
  if(pBtn5 != NULL){pBtn5->EnableWindow(x);}

  CButton *pBtn6 = (CButton *)GetDlgItem(IDC_BUTTON6);
  if(pBtn6 != NULL){pBtn6->EnableWindow(x);}

  CButton *pBtn7 = (CButton *)GetDlgItem(IDC_BUTTON7);
  if(pBtn7 != NULL){pBtn7->EnableWindow(x);}

  CButton *pBtn8 = (CButton *)GetDlgItem(IDC_BUTTON8);
  if(pBtn8 != NULL){pBtn8->EnableWindow(x);}

  CButton *pBtn9 = (CButton *)GetDlgItem(IDC_BUTTON9);
  if(pBtn9 != NULL){pBtn9->EnableWindow(x);}

  CButton *pBtn10 = (CButton *)GetDlgItem(IDC_BUTTON10);
  if(pBtn10 != NULL){pBtn10->EnableWindow(x);}

  CButton *pBtn11 = (CButton *)GetDlgItem(IDC_BUTTON11);
  if(pBtn11 != NULL){pBtn11->EnableWindow(x);}

  CButton *pBtn12 = (CButton *)GetDlgItem(IDC_BUTTON12);
  if(pBtn12 != NULL){pBtn12->EnableWindow(x);}

  CButton *pBtn13 = (CButton *)GetDlgItem(IDC_BUTTON13);
  if(pBtn13 != NULL){pBtn13->EnableWindow(x);}

  CButton *pBtn14 = (CButton *)GetDlgItem(IDC_BUTTON14);
  if(pBtn14 != NULL){pBtn14->EnableWindow(x);}

  CButton *pBtn15 = (CButton *)GetDlgItem(IDC_BUTTON15);
  if(pBtn15 != NULL){pBtn15->EnableWindow(x);}

  CButton *pBtn16 = (CButton *)GetDlgItem(IDC_BUTTON16);
  if(pBtn16 != NULL){pBtn16->EnableWindow(x);}

  CButton *pBtn17 = (CButton *)GetDlgItem(IDC_BUTTON17);
  if(pBtn17 != NULL){pBtn17->EnableWindow(x);}

  CButton *pBtn18 = (CButton *)GetDlgItem(IDC_BUTTON18);
  if(pBtn18 != NULL){pBtn18->EnableWindow(x);}

  CButton *pBtn19 = (CButton *)GetDlgItem(IDC_BUTTON19);
  if(pBtn19 != NULL){pBtn19->EnableWindow(x);}

  CButton *pBtn20 = (CButton *)GetDlgItem(IDC_BUTTON20);
  if(pBtn20 != NULL){pBtn20->EnableWindow(x);}

  CButton *pBtn21 = (CButton *)GetDlgItem(IDC_BUTTON21);
  if(pBtn21 != NULL){pBtn21->EnableWindow(x);}

  CButton *pBtn22 = (CButton *)GetDlgItem(IDC_BUTTON22);
  if(pBtn22 != NULL){pBtn22->EnableWindow(x);}

  CButton *pBtn23 = (CButton *)GetDlgItem(IDC_BUTTON23);
  if(pBtn23 != NULL){pBtn23->EnableWindow(x);}

  CButton *pBtn24 = (CButton *)GetDlgItem(IDC_BUTTON24);
  if(pBtn24 != NULL){pBtn24->EnableWindow(x);}

  CButton *pBtn25 = (CButton *)GetDlgItem(IDC_BUTTON25);
  if(pBtn25 != NULL){pBtn25->EnableWindow(x);}

  CButton *pBtn26 = (CButton *)GetDlgItem(IDC_BUTTON26);
  if(pBtn26 != NULL){pBtn26->EnableWindow(x);}

  CButton *pBtn27 = (CButton *)GetDlgItem(IDC_BUTTON27);
  if(pBtn27 != NULL){pBtn27->EnableWindow(x);}

  CButton *pBtn28 = (CButton *)GetDlgItem(IDC_BUTTON28);
  if(pBtn28 != NULL){pBtn28->EnableWindow(x);}

  CButton *pBtn29 = (CButton *)GetDlgItem(IDC_BUTTON29);
  if(pBtn29 != NULL){pBtn29->EnableWindow(x);}

  CButton *pBtn30 = (CButton *)GetDlgItem(IDC_BUTTON30);
  if(pBtn30 != NULL){pBtn30->EnableWindow(x);}

  CButton *pBtn31 = (CButton *)GetDlgItem(IDC_BUTTON31);
  if(pBtn31 != NULL){pBtn31->EnableWindow(x);}

  CButton *pBtn32 = (CButton *)GetDlgItem(IDC_BUTTON32);
  if(pBtn32 != NULL){pBtn32->EnableWindow(x);}

  CButton *pBtn33 = (CButton *)GetDlgItem(IDC_BUTTON33);
  if(pBtn33 != NULL){pBtn33->EnableWindow(x);}

  CButton *pBtn34 = (CButton *)GetDlgItem(IDC_BUTTON34);
  if(pBtn34 != NULL){pBtn34->EnableWindow(x);}

  CButton *pBtn35 = (CButton *)GetDlgItem(IDC_BUTTON35);
  if(pBtn35 != NULL){pBtn35->EnableWindow(x);}

  CButton *pBtn36 = (CButton *)GetDlgItem(IDC_BUTTON36);
  if(pBtn36 != NULL){pBtn36->EnableWindow(x);}

  CButton *pBtn37 = (CButton *)GetDlgItem(IDC_BUTTON37);
  if(pBtn37 != NULL){pBtn37->EnableWindow(x);}

  CButton *pBtn38 = (CButton *)GetDlgItem(IDC_BUTTON38);
  if(pBtn38 != NULL){pBtn38->EnableWindow(x);}

  CButton *pBtn39 = (CButton *)GetDlgItem(IDC_BUTTON39);
  if(pBtn39 != NULL){pBtn39->EnableWindow(x);}

  CButton *pBtn40 = (CButton *)GetDlgItem(IDC_BUTTON40);
  if(pBtn40 != NULL){pBtn40->EnableWindow(x);}

  CButton *pBtn41 = (CButton *)GetDlgItem(IDC_BUTTON41);
  if(pBtn41 != NULL){pBtn41->EnableWindow(x);}

  CButton *pBtn42 = (CButton *)GetDlgItem(IDC_BUTTON42);
  if(pBtn42 != NULL){pBtn42->EnableWindow(x);}

  CButton *pBtn43 = (CButton *)GetDlgItem(IDC_BUTTON43);
  if(pBtn43 != NULL){pBtn43->EnableWindow(x);}

  CButton *pBtn44 = (CButton *)GetDlgItem(IDC_BUTTON44);
  if(pBtn44 != NULL){pBtn44->EnableWindow(x);}

  CButton *pBtn46 = (CButton *)GetDlgItem(IDC_BUTTON46);
  if(pBtn46 != NULL){pBtn46->EnableWindow(x);}

  CButton *pBtn47 = (CButton *)GetDlgItem(IDC_BUTTON47);
  if(pBtn47 != NULL){pBtn47->EnableWindow(x);}

  CButton *pBtn48 = (CButton *)GetDlgItem(IDC_BUTTON48);
  if(pBtn48 != NULL){pBtn48->EnableWindow(x);}

  CButton *pBtn49 = (CButton *)GetDlgItem(IDC_BUTTON49);
  if(pBtn49 != NULL){pBtn49->EnableWindow(x);}

  CButton *pBtn50 = (CButton *)GetDlgItem(IDC_BUTTON50);
  if(pBtn50 != NULL){pBtn50->EnableWindow(x);}

  CButton *pBtn45 = (CButton *)GetDlgItem(IDC_BUTTON45);
  if(pBtn45 != NULL){pBtn45->EnableWindow(! x);}


}











void CMy115backDlg::OnButton47() 
{
   
}




void CMy115backDlg::OnButton49() 
{
  if (JieMian!=104){jiemian(104);return;} 
  setbutton(FALSE);
   UpdateData(TRUE); 
  MessageBox("程序结束!");setbutton(TRUE);
}



















void CMy115backDlg::sortafile(CString filename) 
{



  DWORD dwAttr = ::GetFileAttributes(filename); 
  if (dwAttr == 0xffffffff){return;} 

  
  long n,i,ubound;
  CString s,old,fname,wr;
  i=0;  
  CStdioFile out;
  out.Open(filename, CFile::modeRead);
  do{
    out.ReadString(s);s=delern(s);
    if (s.GetLength()>0){i=i+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();
  ubound=i-1;
  if (ubound<=0){
    if (ubound<0){DeleteFile(filename);}
    return;
  }
  CString *data=new CString[ubound+1];
  

  

  n=0;  
  out.Open(filename, CFile::modeRead);
  //MessageBox(fname);
  do{
    out.ReadString(s);s=delern(s);  
    if (s.GetLength()>0){data[n]=s;n=n+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();


  
  paixuztoa(data,n);
  
  fname=filename+"_sort.txt";
    //MessageBox(fname);
  out.Open(fname,CFile::modeCreate|CFile::modeWrite);   
  old="^^^^^^^^^^^^^^^^";
  for (i=0;i<n;i++){
    wr=data[i];
    
    if (wr!=old){out.Write(wr+"\r\n",wr.GetLength()+2);old=wr;}
	
  }
  out.Close();
  
  DeleteFile(filename);
  CFile::Rename(fname,filename);
   
  delete[] data;
  
}




////////////////////////////////////////yyyyyyyyyyyyyyyyyyyyyyyyyyy
////////////////////////////////////////yyyyyyyyyyyyyyyyyyyyyyyy







/////////////////////////////////////////////////
///////////////////////.........................







///onbutton43()
//////////////////////////////////////////ggggggggggggggggggggg
////////////////////////////////////////////


////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////==========================





/////////////////////////////////////////////ddddddddddddddddddddddddddd
/////////////////////////////////ddddddddddddddddd








/////////////////////////////rrrrrrrrrrrrrrrrrrrrrrrrrrr





///////////////////////////rrrrrrrrrrrrrr







/////////////////////////////////////gggggggggggggggggggggggggggggggggg
/////////////////////////////////////gggggggggggggggggggggggggggggggggg
void CMy115backDlg::OnButton36() 
{


  if (JieMian!=40){jiemian(40);return;}  
  setbutton(FALSE);
  tuichu=0;
  UpdateData(TRUE); 
  MessageBox("程序结束!");setbutton(TRUE);
}


/////////////////////////////////xxxxxxxxxxxxxxxxxxxxxxxx



/////////////////////////////////xxxxxxxxxxxxxxxxxxxxxxxx


//////////////////////////////////////yyyyyyyyyyyyyyyyyyyyyyyyyyy




///////////////////////////////pppppppppppppppppppppppppppp
void CMy115backDlg::OnButton8() 
{

  if (JieMian!=1){jiemian(1);return;}  
  setbutton(FALSE);UpdateData(TRUE);
  int n=0,i=0,pos,bl;//,pos;
  long ubound;
  CString s,fname,wr,wr1,old=" ",b[100],t;
  CStdioFile out;

  //paixu_status


  if (m_num==4){
     DWORD dwAttr = ::GetFileAttributes(m_dfile); 
     pos=m_dfile.ReverseFind('\\');
     CString nake="";
     nake=m_dfile.Mid(pos+1);
     if (nake.Find("status")>=0 || dwAttr != 0xffffffff){paixu_status(m_dfile);}    
     MessageBox("程序结束！");setbutton(TRUE);
     return;
  }

  if (m_mas==1){
    yiloupaixu_zu(m_dfile,m_num);
    //MessageBox("a");
//////////////////////////////////////////
/////////////////////////////////////
  //MessageBox("0");
  CString nakefile;
  pos=m_dfile.ReverseFind('\\');
  nakefile=m_dfile.Mid(pos+1);
  //MessageBox(nakefile);
  if (nakefile.Find("#allcase")>=0 && m_num==1 && nakefile.Find("ssq000(3)")>=0 ){
    CString filename;
    CString xu,wenjian="文件号码=",yilou="遗漏=",shen="  生存周期:",head,head0,headj;
    int m,j,wenl=wenjian.GetLength(),yl=yilou.GetLength(),sl=shen.GetLength();
    i=0;  
    out.Open(m_dfile, CFile::modeRead);
    do{
      out.ReadString(s);
      i=i+1;
    }
    while (out.GetPosition()!=out.GetLength());
    out.Close();
    ubound=i;
    //MessageBox(Cstr(ubound));


    n=0;
    CString *data1=new CString[ubound];
    out.Open(m_dfile, CFile::modeRead);
  
    do{
      out.ReadString(s);s=delern(s);   
      data1[n]=s;
      n=n+1;
    }
    while (out.GetPosition()!=out.GetLength());
    out.Close();
    out.Open(m_dfile,CFile::modeCreate|CFile::modeWrite);
    for (i=0;i<ubound;i++){
      s=data1[i];
      if (s.Left(3)=="chu"){continue;}
////////////////////////////////////////////////
      filename="";
      pos=s.Find(" file=");
      if (pos>=0){filename=s.Mid(pos);}
/////////////////////////////////////////////////
      pos=s.Find(':');
      head=s.Left(pos);
      if (i==0){head0=head;}
      if (head!=head0){break;}
      pos=s.Find(shen);
      if (pos<0){n=1;t=s;}
      else {
        t=s.Left(pos);
        s=s.Mid(pos+sl);
        //MessageBox("1="+s);
        s.TrimLeft();s.TrimRight();
        pos=s.Find(' ');
        if (pos>=0){s=s.Left(pos);}
        //MessageBox("2="+s);
        n=atoi(s);
        //MessageBox("n="+Cstr(n));
        
      }
      pos=t.Find(yilou);
      s=t.Mid(pos+yl);
      s.TrimLeft();s.TrimRight();
      pos=s.Find(' ');
      s=s.Mid(pos+1);


      pos=s.Find("中奖数:");
      s=s.Left(pos);
      s.TrimLeft();s.TrimRight();
      xu=s;
     
       
      for (j=i+1;j<ubound;j++){
         s=data1[j];
         if (s.Left(3)=="chu" || s.Find(xu)<0){continue;}
         pos=s.Find(':');
         headj=s.Left(pos);

          //MessageBox("s="+s+"\r\nxu="+xu);
         
         data1[j]="chu"+s;
         if (head!=headj){
           pos=s.Find(shen);
           if (pos<0){m=1;}
           else {
             s=s.Mid(pos+sl);
             s.TrimLeft();s.TrimRight();
             pos=s.Find(' ');
             if (pos>=0){s=s.Left(pos);}
             m=atoi(s);           
           }
            
           n=n+m;
         }//if (head!=headj){  
       }//for (j=i+1;j<ubound;j++){
       t=t+"  生存周期:"+padstrcisu(Cstr(n),3," ",0)+filename+"\r\n";

        //MessageBox(t);
        out.Write(t,t.GetLength());    }//for (i=0;i<ubound;i++){
    delete[] data1;
    out.Close();

  }

//////////////////////////////////////////

    MessageBox("程序结束！");
    setbutton(TRUE);
    return;
  }

  
  fname=m_dfile;
  
  DWORD dwAttr = ::GetFileAttributes(fname); 
  if (dwAttr == 0xffffffff){
     setbutton(TRUE);MessageBox("请指定要排序的文件"); 
     return;
  }
  

  i=0;  
  out.Open(fname, CFile::modeRead);
  do{
    out.ReadString(s);
    i=i+1;
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();
  ubound=i-1;
  
  CString *data=new CString[ubound+1];
  

  

  
  out.Open(fname, CFile::modeRead);
  //MessageBox(fname);
  do{
    out.ReadString(s);s=delern(s);  
    if (m_num==2){
      Split(s,b,bl,m_mo);
      s=b[m_btui-1]+m_mo+s;
    }
    if (m_num==3){
      pos=s.Find("[");
      if (pos>=0){
        t=s.Mid(pos+1);
        pos=t.Find("]");
        if(pos>=0){
          t=t.Left(pos);
          t=padstrcisu(t,10," ",0);
          s=t+"!"+s;
        }
      }//if (m_num==3){
    }


	data[n]=s;
    n=n+1;
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();


  
  if (m_su==1){paixuztoa(data,n);}
  else {paixuatoz(data,n);}  
  fname=fname+"_sort.txt";
    //MessageBox(fname);
  out.Open(fname,CFile::modeCreate|CFile::modeWrite);   
  old="^^^^^^^^^^^^^^^^";
  for (i=0;i<n;i++){
    wr=data[i];
    if (m_num==2){
      pos=wr.Find(m_mo);
	  wr=wr.Mid(pos+1);
    }
    if (m_num==3){
      pos=wr.Find("!");
	  wr=wr.Mid(pos+1);
    }

    if (m_bfile=="1"){
      pos=wr.Find(":");
      wr1=wr;
      if (pos>=0){wr1=wr.Mid(pos+1);}
      if (wr1!=old){
         out.Write(wr+"\r\n",wr.GetLength()+2);
         old=wr1;
      }
    }
    if (m_bfile=="2"){
      if (wr!=old){
         out.Write(wr+"\r\n",wr.GetLength()+2);        
         old=wr;
      }
    }
    if (m_bfile=="3"){out.Write(wr+"\r\n",wr.GetLength()+2);}
  }
  out.Close();
  
  if (m_num!=3){
    DeleteFile(m_dfile);
    CFile::Rename(fname,m_dfile);
  }


  if (m_num==3){
    pos=m_dfile.ReverseFind('\\');
    CString dirpath=m_dfile.Left(pos+1);  
    CString newfname=m_dfile.Mid(pos+1);
    if (m_su==1){newfname=dirpath+"fangdown-"+newfname;}
    else {newfname=dirpath+"fangup-"+newfname;}
    dwAttr = ::GetFileAttributes(newfname); 
    if (dwAttr != 0xffffffff){DeleteFile(newfname);}
    CFile::Rename(fname,newfname);
  }


  delete[] data;

   
  
  MessageBox("程序结束！");setbutton(TRUE);
}

















////////////////////////////////////////////////jjjjjjjjjjjjjjjjjjj

/////////////////////////mmmmmmmmmmmmmmmmmmmm

















///////////////////////////////////////////////////
////////////////////ppppppppppppppppppppppppppp
void CMy115backDlg::paixuatoz(CString str[], int n)
{
runatoz(str,0,n-1);
return;
for (int i=0; i<n; i++)
 {
  for (int j=1; j<n-i; j++)
  {
   if ( str[j-1]>str[j] )
   {
    CString tmp = str[j-1];
    str[j-1] = str[j];
    str[j] = tmp;
   }
  }
 }
}


void CMy115backDlg::paixuztoa(CString str[], int n)
{
runztoa(str,0,n-1);
return;
for (int i=0; i<n; i++)
 {
  for (int j=1; j<n-i; j++)
  {
   if ( str[j-1]<str[j] )
   {
    CString tmp = str[j-1];
    str[j-1] = str[j];
    str[j] = tmp;
   }
  }
 }
}



void CMy115backDlg::runatoz(CString pData[],int left,int right)
{ 
  //MessageBox("in");
  int i,j,r;
  CString middle,iTemp;
  i=left;
  j=right;
  //middle=pData[left];
  r=left+rand()%(right-left+1);
  middle=pData[r];

  ////////////////////////////////////////
  /*
  while((pData[i]==middle) && (i<right))//检查是否全同
  i++;
  if (i==right){return;}
  */
  //////////////////////////////////////////////
  i=left;
  do {
    while((pData[i]<middle) && (i<right))//从左扫描大于中值的数 
    i++;
    while((pData[j]>middle) && (j>left))//从右扫描大于中值的数 　
    j--;
    if(i<=j){//找到了一对值交换
      iTemp = pData[i];
      pData[i] = pData[j];
      pData[j] = iTemp;
      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) runatoz(pData,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) runatoz(pData,i,right);
}


void CMy115backDlg::runztoa(CString pData[],int left,int right)
{ 
  //MessageBox("in");
  int i,j,r;
  CString middle,iTemp;
  i=left;
  j=right;
  r=left+rand()%(right-left+1);
  middle=pData[r];

  ////////////////////////////////////////
  /*
  while((pData[i]==middle) && (i<right))//检查是否全同
  i++;
  if (i==right){return;}
  */
  //////////////////////////////////////////////
  i=left;
  do {
    while((pData[i]>middle) && (i<right))//从左扫描大于中值的数 
    i++;
    while((pData[j]<middle) && (j>left))//从右扫描大于中值的数 　
    j--;
    if(i<=j){//找到了一对值交换
      iTemp = pData[i];
      pData[i] = pData[j];
      pData[j] = iTemp;
      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) runztoa(pData,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) runztoa(pData,i,right);
}






void CMy115backDlg::runztoa_2(int **pData,CString *chuan,int left,int right)
{ 
  int i,j,r,k;
  int middle_y,middle_f,iTemp;
  CString middle_bstr,iTempstr;
  i=left;
  j=right;
  r=left+rand()%(right-left+1);
  middle_y=pData[r][0];
  middle_f=pData[r][1];
  middle_bstr=chuan[r];
  ////////////////////////////////////////
  /*
  while((chuan[i]==middle_bstr && pData[i][0]==middle_y && pData[i][1]==middle_f) && (i<right))//检查是否全同
  i++;
  if (i==right){return;}
  */
  //////////////////////////////////////////////
  i=left;
  do {
    while((pData[i][1]>middle_f || pData[i][1]==middle_f && pData[i][0]>middle_y || pData[i][0]==middle_y && pData[i][1]==middle_f && chuan[i]>middle_bstr) && (i<right))//从左扫描大于中值的数 
    i++;
    while((pData[j][1]<middle_f || pData[j][1]==middle_f && pData[j][0]<middle_y || pData[j][0]==middle_y && pData[j][1]==middle_f && chuan[j]<middle_bstr) && (j>left))//从右扫描大于中值的数 　
    j--;
    if(i<=j){//找到了一对值交换
      for(k=0;k<2;k++){
        iTemp = pData[i][k];
        pData[i][k] = pData[j][k];
        pData[j][k] = iTemp;
      }
      iTempstr = chuan[i];
      chuan[i] = chuan[j];
      chuan[j] = iTempstr;

      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) runztoa_2(pData,chuan,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) runztoa_2(pData,chuan,i,right);
}




void CMy115backDlg::runztoa_1(int **pData,CString *chuan,int left,int right)
{ 
  
  int i,j,r,k;
  int middle_y,middle_f,iTemp;
  CString middle_bstr,iTempstr;
  i=left;
  j=right;
  r=left+rand()%(right-left+1);
  middle_y=pData[r][0];
  middle_f=pData[r][1];
  middle_bstr=chuan[r];
  ////////////////////////////////////////
  /*
  while((chuan[i]==middle_bstr && pData[i][0]==middle_y && pData[i][1]==middle_f) && (i<right))//检查是否全同
  i++;
  if (i==right){return;}
  */
  //////////////////////////////////////////////
  i=left;
  do {
    while((pData[i][0]>middle_y || pData[i][0]==middle_y && pData[i][1]>middle_f || pData[i][0]==middle_y && pData[i][1]==middle_f && chuan[i]>middle_bstr) && (i<right))//从左扫描大于中值的数 
    i++;
    while((pData[j][0]<middle_y || pData[j][0]==middle_y && pData[j][1]<middle_f || pData[j][0]==middle_y && pData[j][1]==middle_f && chuan[j]<middle_bstr) && (j>left))//从右扫描大于中值的数 　
    j--;
    if(i<=j){//找到了一对值交换
      for(k=0;k<2;k++){
        iTemp = pData[i][k];
        pData[i][k] = pData[j][k];
        pData[j][k] = iTemp;
      }
      iTempstr = chuan[i];
      chuan[i] = chuan[j];
      chuan[j] = iTempstr;

      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) runztoa_1(pData,chuan,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) runztoa_1(pData,chuan,i,right);
}




////////////////////////////////////////////h
///////////////////////////////pppppppppppppppppppppppppppp
///////////////////////////////pppppppppppppppppppppppppppp
void CMy115backDlg::yiloupaixu(CString fname,int mnum) 
{
  CString yfname=fname;
 
  int pos,n,i=0;
  CString s1,s2,dirpath,newfname,s,wr,wr1,t;
  
  //fname=m_dfile;
  
  DWORD dwAttr = ::GetFileAttributes(fname); 
  if (dwAttr == 0xffffffff){
     setbutton(TRUE);MessageBox("请指定要排序的文件"); 
     return;
  }
  

  i=0;  
  CStdioFile out;
  out.Open(fname, CFile::modeRead);
  do{
    out.ReadString(s);
    pos=s.Find(":");
    if (pos>0){i=i+1;}
    
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();
  long ubound=i;
  if (i==0){return;}
  CString *chuan=new CString[ubound];
  
  int  **xdata=new int*[ubound];
  for (i=0;i<ubound;i++){
    *(xdata+i)=new int[2];
  }
 


  n=0;
  out.Open(fname, CFile::modeRead);
 
  do{
    out.ReadString(s);s=delern(s);  
    //MessageBox("1="+s);
    pos=s.Find(":");
    if (pos>0){/////////////
      chuan[n]=s.Mid(pos+1);
      s=s.Left(pos);
      //MessageBox("2="+s);
      pos=s.Find("[");
      if (pos>=0){
        t=s.Mid(pos+1);
        s=s.Left(pos);      
        //MessageBox("a "+t);
        pos=t.Find("]");
        t=t.Left(pos);
        //MessageBox("b "+t);
      }
      else {t="0";}
      xdata[n][0]=atoi(s);
      xdata[n][1]=atoi(t);   
      n=n+1;
    }/////if (pos>0){/////////////
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();

  pos=m_dfile.ReverseFind('\\');
  dirpath=m_dfile.Left(pos+1);  
  newfname=m_dfile.Mid(pos+1);

////////////////////////////////////////////////
  if (mnum!=3){  
    runztoa_1(xdata,chuan,0,ubound-1);
    //////////////////

    ////////////////////////////////////

   }
   else {
    newfname=dirpath+"fangdown-"+newfname;
    runztoa_2(xdata,chuan,0,ubound-1);
    ////////////////////////////////////

    ///////////////////////////////////////

   }
////////////////////////////////////////////////////

/////////////////////////////////////////  

  fname=fname+"_sort.txt";
  CString old="^";
  out.Open(fname,CFile::modeCreate|CFile::modeWrite);   
  for (i=0;i<ubound;i++){ 
    if (chuan[i]==old){continue;}
    if (xdata[i][1]>0){wr=padstrcisu(Cstr(xdata[i][0]),5," ",0)+"["+Cstr(xdata[i][1])+"]:"+chuan[i];}
    else {wr=padstrcisu(Cstr(xdata[i][0]),5," ",0)+":"+chuan[i];}
    out.Write(wr+"\r\n",wr.GetLength()+2);
    old=chuan[i];
  }
  out.Close();
  
  if (mnum!=3){
    DeleteFile(yfname);
    CFile::Rename(fname,yfname);
  }


  if (mnum==3){
    dwAttr = ::GetFileAttributes(newfname); 
    if (dwAttr != 0xffffffff){DeleteFile(newfname);}
    CFile::Rename(fname,newfname);
  }

  for (i=0;i<ubound;i++){delete[] xdata[i];}
   
  delete[] xdata;delete[] chuan;
  return;
}






















//////////////////33333333333333333
void CMy115backDlg::OnButton30() 
{
 
  if (JieMian!=28){jiemian(28);return;} 

  setbutton(FALSE);
  UpdateData(TRUE); 
  CStdioFile fin,fout;

  
  CString s,fnamehead,fname=m_dfile,fu;
  
  long n=0,i;
  fnamehead=fname.Left(fname.GetLength()-4);

  if (m_num==7){  
    int pos=m_dfile.ReverseFind('\\');
    CString dirpath=m_dfile.Left(pos+1);
    if(IDOK==MessageBox(_T("是否删除目录"+dirpath+"及其里面的全部内容?"),_T("确定删除"),MB_OKCANCEL));{
      deletedir(dirpath);
    }    
    MessageBox("程序结束!");setbutton(TRUE);
    return;
  }
  
  DWORD dwAttr = ::GetFileAttributes(fname); 
  if (dwAttr == 0xffffffff){
     setbutton(TRUE);MessageBox("请指定文本文件或文件夹"); 
     return;
  }
 





  


  fin.Open(fname, CFile::modeRead);


  if (m_num==1){  
	do{fin.ReadString(s);n=n+1;} while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
	GetDlgItem(idc_jingdu)->SetWindowText(fname+"共有"+Cstr(n)+"行");    
  }


  if (m_num==2){  
    i=0;
	fout.Open(fnamehead+"-sub"+Cstr(m_btui)+"-"+Cstr(m_etui)+".txt",CFile::modeCreate|CFile::modeWrite);  
	do{
	  fin.ReadString(s);s=delern(s);
	  if (i>=m_btui-1){
	    fout.Write(s+"\r\n",s.GetLength()+2);		
      }	
	  if (i>=m_btui+m_etui-2){break;}
	  i=i+1;
	} 
	while (fin.GetPosition()!=fin.GetLength());
    fin.Close();fout.Close();
	GetDlgItem(idc_jingdu)->SetWindowText(fnamehead+"-sub"+Cstr(m_btui)+"-"+Cstr(m_etui)+".txt");    
  }//if (m_num==2){  


  if (m_num==3){  
    n=0;
    do{fin.ReadString(s);n=n+1;} while (fin.GetPosition()!=fin.GetLength());
	fin.Close();
	int b=m_btui*n/100;
    int e=m_etui*n/100;
	if (b<1){b=1;}
    if (e>n-b){e=n-b;}
    i=0;
	fout.Open(fnamehead+"-sub"+Cstr(b)+"-"+Cstr(e)+".txt",CFile::modeCreate|CFile::modeWrite);  
	fin.Open(fname, CFile::modeRead);
	do{
	  fin.ReadString(s);s=delern(s);
	  if (i>=b-1){
	    fout.Write(s+"\r\n",s.GetLength()+2);		
      }	
	  if (i>=b+e-2){break;}
	  i=i+1;
	} 
	while (fin.GetPosition()!=fin.GetLength());
    fin.Close();fout.Close();
	GetDlgItem(idc_jingdu)->SetWindowText(fnamehead+"-sub"+Cstr(b)+"-"+Cstr(e)+".txt");    
  }


  if (m_num==4){  
    n=1;    
	int k=m_btui,wflag=0;
	do{
	  fin.ReadString(s);s=delern(s);
	  if (n%m_ql==1){fout.Open(fnamehead+"-cut"+Cstr(k)+".txt",CFile::modeCreate|CFile::modeWrite);wflag=0;k=k+1;}
      fout.Write(s+"\r\n",s.GetLength()+2);		
      if (n%m_ql==0){wflag=1;fout.Close();}
      n=n+1;
	} 
	while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
	if (wflag==0){fout.Close();}
	GetDlgItem(idc_jingdu)->SetWindowText(fnamehead+"-cut"+Cstr(k-1)+".txt");    
  }

  if (m_num==5){  
    n=0;
    do{fin.ReadString(s);n=n+1;} while (fin.GetPosition()!=fin.GetLength());
	fin.Close();
    int ql=n/m_ql;  
	if (n%m_ql!=0){ql=ql+1;}
    

    fin.Open(fname, CFile::modeRead);
    n=1;    
	int k=m_btui,wflag=0;
	do{
	  fin.ReadString(s);s=delern(s);
	  if (n%ql==1){fout.Open(fnamehead+"-cut"+Cstr(k)+".txt",CFile::modeCreate|CFile::modeWrite);wflag=0;k=k+1;}
      fout.Write(s+"\r\n",s.GetLength()+2);		
      if (n%ql==0){wflag=1;fout.Close();}
      n=n+1;
	} 
	while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
	if (wflag==0){fout.Close();}
	GetDlgItem(idc_jingdu)->SetWindowText(fnamehead+"-cut"+Cstr(k-1)+".txt");    
  }

  if (m_num==6){  
    i=1;
	fout.Open(fnamehead+"-hao.txt",CFile::modeCreate|CFile::modeWrite);  
	do{
	  fin.ReadString(s);s=delern(s);
	  s=Cstr(i)+"\t"+s+"\r\n";
	  fout.Write(s,s.GetLength());		
      
	  
	  i=i+1;
	} 
	while (fin.GetPosition()!=fin.GetLength());
    fin.Close();fout.Close();
	GetDlgItem(idc_jingdu)->SetWindowText(fnamehead+"-hao.txt");    
  }//if (m_num==6){  
  
  MessageBox("程序结束!");setbutton(TRUE);
  return;
}



/////////////////////////////////////////////////
////////////////////////////////////////////////




/////////////////////////////////////////////
////////////////////////////////////////////
/////////////////////////rrrrrrrrrrrrrrrrrrrrrrr
////////////////////////////////////////>>>>>>>>>>>>>>>>>>>>>>>>>>>>
////////////////////////////////////ggggggggggggggggg









/////////////////////////////






///////////////////////////////







/////////////////////////////
/////////////////////////////










////////////////////////////////////////////

/////////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////




///////////////////////////////////////////////
///////////////////////////////////////////////









////////////////////////////////////////
/////////////////////////////////////////
void CMy115backDlg::OnButton32() 
{
   if (JieMian!=46){jiemian(46);return;} 
   setbutton(FALSE);
   UpdateData(TRUE);   
   MessageBox("程序结束!");setbutton(TRUE);

   

}






////////////////////////////

void CMy115backDlg::yiloupaixu_zu(CString fname,int mnum) /////////ppppppppppppppppppppppppppppppppp
{
  LPCTSTR p;
  char c;
  DWORD dwAttr;
  CString srcfile,dirpath,yifilemode,chufilemode,yifile,chufile,s;
  int pos,i,k; 
  pos=fname.ReverseFind('\\');
  dirpath=fname.Left(pos+1);
  srcfile=fname.Mid(pos+1);
  if (m_wb==0){yiloupaixu(fname,mnum);return;}  
  p=srcfile;  
  if(srcfile.Left(1)!="p"){return;}
  i=1;  
  while(true){    
    c=p[i];
    if (c>=48 && c<=57){i++;}
    else {break;}
  }
  
  if (i==1){return;}
  yifilemode=srcfile.Mid(i);
  //MessageBox(yifilemode);

  //yifilemode=srcfile.Mid(2);
  pos=yifilemode.ReverseFind('-');
  s=yifilemode.Left(pos+1);
  chufilemode=s+"chuma.txt";

  i=1;k=0;
  while (true){
    yifile=dirpath+"p"+Cstr(i)+yifilemode;   
    //MessageBox(yifile);
    dwAttr = ::GetFileAttributes(yifile); 
    if (dwAttr != 0xffffffff){yiloupaixu(yifile,mnum);k=0; }
    else {k=k+1;}
    //MessageBox("uoi="+yifile); 
    

    chufile=dirpath+"p"+Cstr(i)+chufilemode;  
    //MessageBox("uoi="+chufile);  
    dwAttr = ::GetFileAttributes(chufile); 
    if (dwAttr != 0xffffffff){yiloupaixu(chufile,mnum);k=0;}
    else {k=k+1;}
    i=i+1;
    if (k>1000){break;}
    else {continue;}
  } 

}




/////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




/////////////////////////






////////////////////////////////
///////////////////////////////////////////
void CMy115backDlg::OnButton42() 
{
   if (JieMian!=38){jiemian(38);return;}  
   setbutton(FALSE);
   UpdateData(TRUE); 
   MessageBox("程序结束!");setbutton(TRUE);
}



//////////////////////////////////
////////////////////////////////////////////////
void CMy115backDlg::OnButton41() 
{
  
  if (JieMian!=37){jiemian(37);return;} 
  setbutton(FALSE);
  tuichu=0;
  UpdateData(TRUE); 
////////////////////////////////////////////////////////////
   if (m_dfile.GetLength()==0){setbutton(TRUE);return;} 
   int ai,bl,pos,i,ubound;
   CString s,t,dirpath,datafile,ba[8];
   CStdioFile out;



   pos=m_dfile.ReverseFind('\\');
   dirpath=m_dfile.Left(pos+1);
   datafile=dirpath+"mega.txt";
   //dis="类型:1 求预测单码 2 由单码求合成码 3 核对合成码 4 清理重复合成 5 由合成码求合成码 6 生成文件 \r\n";
   if (m_mo=="2"){
     getmegabuycode(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }

   if (m_mo=="4"){
     deletehe(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }

   if (m_mo=="5"){
     getmegahe(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }

   if (m_mo=="6"){
     getmegabuyfile(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }


   if (m_mo=="8"){
     copybuyfile(dirpath,4); 
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }


   if (m_mo=="1" || m_mo=="3" || m_mo=="7"){////////////////////////////////

   DWORD dwAttr = ::GetFileAttributes(datafile); 
   if (dwAttr == 0xffffffff){MessageBox("没有数据文件");setbutton(TRUE);return;}

   out.Open(datafile, CFile::modeRead);

   if (m_mo=="1" && m_dfile.Find("ssqdata.txt")>=0){for (i=0;i<m_step;i++){out.ReadString(s);}}
   i=0;   
   do{
     out.ReadString(s);
     i=i+1;    
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
   ubound=i;


   CString *datas=new CString[ubound];
   CString *qihao=new CString[ubound];
   small  **data=new small *[ubound];
   for (i=0;i<ubound;i++){
     *(data+i)=new small[7];
   } 

   out.Open(datafile, CFile::modeRead);
   if (m_mo=="1" && m_dfile.Find("mega.txt")>=0){for (i=0;i<m_step;i++){out.ReadString(s);}}
   i=0;   
   do{
     out.ReadString(s);s=delern(s); 

     pos=s.ReverseFind('\t');
     if (s.Left(pos).GetLength()>10){
       s=s.Left(pos);
       pos=s.Find('\t');       
     }
     qihao[i]=s.Left(pos);
     s=s.Mid(pos+1);
     Split(s,ba,bl,",");
     datas[i]=ba[0]+","+ba[1]+","+ba[2]+","+ba[3]+","+ba[4]+","+ba[5];    	 
     data[i][0]=atoi(ba[0]);
     data[i][1]=atoi(ba[1]);
     data[i][2]=atoi(ba[2]);
     data[i][3]=atoi(ba[3]);
     data[i][4]=atoi(ba[4]);
     data[i][5]=atoi(ba[5]);   
     

     i=i+1;
     
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
//////////////////////////////////////////////////////////
   if (m_mo=="7"){  
      CStdioFile fin;
      const int ZUSU=20;
      int ZSU=getcansu(dirpath,3);
      CString tjsrc=dirpath+"tjsrc\\",srcfile;
      if(_access(tjsrc, 0) == -1){_mkdir(tjsrc);} 
      CString tjfile,oldstr,wr;
 
      tjfile=dirpath+"tongji.txt";
      oldstr="";
      dwAttr = ::GetFileAttributes(tjfile);
      if (dwAttr != 0xffffffff){
        fin.Open(tjfile,CFile::modeRead);
        fin.ReadString(s);fin.ReadString(s);
        pos=s.Find(";");
        if (s.Left(pos)<qihao[0]){
          s=delern(s);
          oldstr+=s+"\r\n";
        }
        else {
          delete[] datas;delete[] qihao;
          for (ai=0;ai<ubound;ai++){delete[] data[ai];}
          delete[] data; 
          MessageBox("程序结束！");setbutton(TRUE);return;
        }
          
        while(fin.ReadString(s)){
          s=delern(s);
          oldstr+=s+"\r\n";
        }
        fin.Close();                  
      }
     
    
      //CString records[ZUSU][2];
      CString **records=new CString *[ZUSU];
      for (i=0;i<ZUSU;i++){
        records[i]=new CString [2];
      }

      
      for (i=0;i<ZUSU;i++){
        records[i][0]="0";
      }
   

      CString zerofile=dirpath+"zero.txt";
      CStdioFile outz;
      outz.Open(zerofile,CFile::modeCreate|CFile::modeWrite);    
    

     
      checkmegabuyfile(dirpath+"buy\\",qihao,datas,ubound,tjsrc);

      for (i=0;i<ZSU;i++){
        srcfile=tjsrc+padstrcisu(Cstr(i),4,"0",0)+".txt";
        ssqmegarecords(srcfile,records,outz);   
      }
      outz.Close();
      CString head="   qi";
      for (i=0;i<ZUSU;i++){
         head+=";"+padstrcisu(Cstr(i+1),9," ",0);
      }


      out.Open(tjfile,CFile::modeCreate|CFile::modeWrite);  

      wr=head+"\r\n";

      out.Write(wr,wr.GetLength());

      wr=" "+qihao[0];
      for (i=0;i<ZUSU;i++){
        if (records[i][0]!="0"){
          wr+=";"+padstrcisu(records[i][0]+"["+records[i][1]+"]",9," ",0);
        }
        else {wr+=";         ";}
      }

      wr=wr+"\r\n";
      out.Write(wr,wr.GetLength());

      wr=oldstr;

      out.Write(wr,wr.GetLength());
      out.Close();     
      for(i=0;i<ZUSU;i++){delete[] records[i];}
      delete[] records;
////////////////////////////////////////
      int re=sortafileatoz(zerofile);
      if (re==-1){
        delete[] datas;delete[] qihao;
        for (ai=0;ai<ubound;ai++){delete[] data[ai];}
        delete[] data; 
        MessageBox("程序结束！");setbutton(TRUE);	return;
      }
      CString b[10];
      int bl;
      i=0;
      fin.Open(zerofile,CFile::modeRead);
      while(fin.ReadString(s)){
        i++;
      }
      fin.Close(); 


      if (i>0){


        ubound=i;
        i=0;
        CString *zu=new CString [ubound];
        CString *zuwr=new CString [ubound];
        fin.Open(zerofile,CFile::modeRead);
        while(fin.ReadString(s)){
          s=delern(s);
          zu[i]=s;i++;
        }
        fin.Close();  
        for (i=0;i<ubound;i++){
          Split(zu[i],b,bl,"\t");
          zuwr[i]=b[1]+"#"+zu[i];
        } 
      
        paixuatoz(zuwr,ubound);

        out.Open(dirpath+"zerozu.txt",CFile::modeCreate|CFile::modeWrite);

        for (i=0;i<ubound;i++){
          wr=zuwr[i];
          pos=wr.Find("#");
          wr=wr.Mid(pos+1)+"\r\n";      
    
          out.Write(wr,wr.GetLength());
        }
        out.Close();
 
        for (i=0;i<ubound;i++){
          Split(zu[i],b,bl,"\t");
          zuwr[i]=b[2]+"#"+zu[i];
        }       
        paixuztoa(zuwr,ubound);
        out.Open(dirpath+"zeronum.txt",CFile::modeCreate|CFile::modeWrite);

        for (i=0;i<ubound;i++){
          wr=zuwr[i];
          pos=wr.Find("#");
          wr=wr.Mid(pos+1)+"\r\n";          
          out.Write(wr,wr.GetLength());
        }
        out.Close();
        delete[] zu;delete[] zuwr;


      }
////////////////////////////////////////

      
   }




/////////////////////////////////////////////////////
   if (m_mo=="1"){   
     if (m_dfile.Find("mega.txt")>=0){
       m_wb=m_wb+m_e;
       megafindtong(qihao,datas,data,dirpath,ubound); 
       m_wb=m_wb-m_e;     
     }
     else {
       megaallrefresh(dirpath,qihao,datas,ubound);
     }
   }

   if (m_mo=="3"){
//////////////////////////////////////////////////////////

     CString strDir=dirpath;
     CString szDir = strDir,buyfile,nake; 
     CFileFind ff; 
     szDir += "*.*"; 
     CStdioFile fin;   
     bool res = ff.FindFile(szDir);   
    
     while( res ) 
     { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 

       if(!ff.IsDirectory() && !ff.IsDots()){
         pos=buyfile.ReverseFind('\\'); 
         nake=buyfile.Mid(pos+1);          
         if (nake.Find("he")<0){continue;}      

         checkmegahccode(dirpath,qihao,datas,ubound,buyfile);
       }        
       
     }
     ff.Close(); 
     //MessageBox("程序结束！");setbutton(TRUE);	return;
   }




///////////////////////////////////////////////////////
   delete[] datas;delete[] qihao;
   for (ai=0;ai<ubound;ai++){delete[] data[ai];}
   delete[] data; 
   }//   if (m_mo=="1" || m_mo=="3"){////////////////////////////////






//////////////////////////////////////////////////////////////
  MessageBox("程序结束!");setbutton(TRUE);
}


/////////////////
////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////



/////////////



////////////////////////////
////////////////////////////5555555555555555555555
void CMy115backDlg::OnButton31()
{
   if (JieMian!=45){jiemian(45);return;} 
   setbutton(FALSE);
   UpdateData(TRUE); 
  MessageBox("程序结束!");setbutton(TRUE);

	
}



/////////////////
//////////////////////////////
/////////////////





void CMy115backDlg::BrowseDir(CString strDir) //此函数用于遍历文件夹下的文件，strDir是一个目录路径 
{ 
  if(strDir == "") {MessageBox("error!");return;} 
  CFileFind ff; 
  CString szDir = strDir,strPath; 
  if(szDir.Right(1) != "\\") //保证目录是以\结尾的 
  szDir += "\\"; 
  szDir += "*.*"; 
  BOOL res = ff.FindFile(szDir); 
  while( res ) 
  { 
    res = ff.FindNextFile(); 
    strPath = ff.GetFilePath(); 
    if(ff.IsDirectory() && !ff.IsDots()){BrowseDir(strPath);} //如果目标是个文件夹，则利用嵌套来遍历 
    else if(!ff.IsDirectory() && !ff.IsDots()) 
    MessageBox(strPath); //如果目标是个文件，则对它进行处理 
  } 
  ff.Close(); 
}
///////////////////////////////////////// 









//////////////




void CMy115backDlg::addfilename(CString jigo){

   int pos;
   CStdioFile fin,out;
   CString newjigo=jigo+"_addfile.txt",qi,rname,fname,t,s;
   out.Open(newjigo,CFile::modeCreate|CFile::modeWrite);  
  
 
   fin.Open(jigo, CFile::modeRead);
   do{
     fin.ReadString(s); s=delern(s); 
     t=s;
     pos=s.Find('[');
     s=s.Left(pos);
     pos=s.ReverseFind(' ');
     s=s.Mid(pos+1); 
     pos=s.Find('#');
     qi=s.Left(pos);rname=s.Mid(pos+1);
     fname=m_mo+"#"+rname+"-"+qi+".txt"+"\r\n";
     t=t+" file="+fname;
     out.Write(t,t.GetLength());

   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();out.Close();
   



}






////////////////////////////////////

////////////////////////////
void CMy115backDlg::paimasu(int **pData,int left,int right)
{ 
  int i,j,r;
  int middle,iTemp;
  i=left;
  j=right;
  r=(left+right)/2;//left+rand()%(right-left+1);
  middle=pData[r][1];


  //i=left;
  do {
    while((pData[i][1]>middle) && (i<right))//从左扫描大于中值的数 
    i++;
    while((pData[j][1]<middle) && (j>left))//从右扫描大于中值的数 　
    j--;
    if(i<=j){//找到了一对值交换
      iTemp = pData[i][0];
      pData[i][0] = pData[j][0];
      pData[j][0] = iTemp;

      iTemp = pData[i][1];
      pData[i][1] = pData[j][1];
      pData[j][1] = iTemp;

      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) paimasu(pData,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) paimasu(pData,i,right);
}





////////////////////////////
void CMy115backDlg::paimasu2(int **pData,int left,int right)
{ 
  int i,j,r;
  int middle,iTemp;
  i=left;
  j=right;
  r=(left+right)/2;//left+rand()%(right-left+1);
  middle=pData[r][1];


  //i=left;
  do {
    while((pData[i][2]>middle) && (i<right))//从左扫描大于中值的数 
    i++;
    while((pData[j][2]<middle) && (j>left))//从右扫描大于中值的数 　
    j--;
    if(i<=j){//找到了一对值交换
      iTemp = pData[i][0];
      pData[i][0] = pData[j][0];
      pData[j][0] = iTemp;

      iTemp = pData[i][1];
      pData[i][1] = pData[j][1];
      pData[j][1] = iTemp;

      iTemp = pData[i][2];
      pData[i][2] = pData[j][2];
      pData[j][2] = iTemp;

      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) paimasu(pData,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) paimasu(pData,i,right);
}

////////////////////////////
void CMy115backDlg::paimasu3(int **pData,int left,int right)
{ 
  int i,j,r;
  int middle,iTemp;
  i=left;
  j=right;
  r=(left+right)/2;//left+rand()%(right-left+1);
  middle=pData[r][1];


  //i=left;
  do {
    while((pData[i][1]>middle) && (i<right))//从左扫描大于中值的数 
    i++;
    while((pData[j][1]<middle) && (j>left))//从右扫描大于中值的数 　
    j--;
    if(i<=j){//找到了一对值交换
      iTemp = pData[i][0];
      pData[i][0] = pData[j][0];
      pData[j][0] = iTemp;

      iTemp = pData[i][1];
      pData[i][1] = pData[j][1];
      pData[j][1] = iTemp;

      iTemp = pData[i][2];
      pData[i][2] = pData[j][2];
      pData[j][2] = iTemp;

      iTemp = pData[i][3];
      pData[i][3] = pData[j][3];
      pData[j][3] = iTemp;

      iTemp = pData[i][4];
      pData[i][4] = pData[j][4];
      pData[j][4] = iTemp;

      iTemp = pData[i][5];
      pData[i][5] = pData[j][5];
      pData[j][5] = iTemp;

      iTemp = pData[i][6];
      pData[i][6] = pData[j][6];
      pData[j][6] = iTemp;

      iTemp = pData[i][7];
      pData[i][7] = pData[j][7];
      pData[j][7] = iTemp;

      iTemp = pData[i][8];
      pData[i][8] = pData[j][8];
      pData[j][8] = iTemp;

      iTemp = pData[i][9];
      pData[i][9] = pData[j][9];
      pData[j][9] = iTemp;

      iTemp = pData[i][10];
      pData[i][10] = pData[j][10];
      pData[j][10] = iTemp;

      iTemp = pData[i][11];
      pData[i][11] = pData[j][11];
      pData[j][11] = iTemp;

      iTemp = pData[i][12];
      pData[i][12] = pData[j][12];
      pData[j][12] = iTemp;

      iTemp = pData[i][13];
      pData[i][13] = pData[j][13];
      pData[j][13] = iTemp;

      iTemp = pData[i][14];
      pData[i][14] = pData[j][14];
      pData[j][14] = iTemp;

      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) paimasu3(pData,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) paimasu3(pData,i,right);
}


////////////////////////////
void CMy115backDlg::paimasu3_hot(int **pData,int left,int right)
{ 
  int i,j,r;
  int middle,iTemp;
  i=left;
  j=right;
  r=(left+right)/2;//left+rand()%(right-left+1);
  middle=pData[r][3];


  //i=left;
  do {
    while((pData[i][3]>middle) && (i<right))//从左扫描大于中值的数 
    i++;
    while((pData[j][3]<middle) && (j>left))//从右扫描大于中值的数 　
    j--;
    if(i<=j){//找到了一对值交换
      iTemp = pData[i][0];
      pData[i][0] = pData[j][0];
      pData[j][0] = iTemp;

      iTemp = pData[i][1];
      pData[i][1] = pData[j][1];
      pData[j][1] = iTemp;

      iTemp = pData[i][2];
      pData[i][2] = pData[j][2];
      pData[j][2] = iTemp;

      iTemp = pData[i][3];
      pData[i][3] = pData[j][3];
      pData[j][3] = iTemp;

      iTemp = pData[i][4];
      pData[i][4] = pData[j][4];
      pData[j][4] = iTemp;

      iTemp = pData[i][5];
      pData[i][5] = pData[j][5];
      pData[j][5] = iTemp;

      iTemp = pData[i][6];
      pData[i][6] = pData[j][6];
      pData[j][6] = iTemp;

      iTemp = pData[i][7];
      pData[i][7] = pData[j][7];
      pData[j][7] = iTemp;

      iTemp = pData[i][8];
      pData[i][8] = pData[j][8];
      pData[j][8] = iTemp;

      iTemp = pData[i][9];
      pData[i][9] = pData[j][9];
      pData[j][9] = iTemp;

      iTemp = pData[i][10];
      pData[i][10] = pData[j][10];
      pData[j][10] = iTemp;

      iTemp = pData[i][11];
      pData[i][11] = pData[j][11];
      pData[j][11] = iTemp;

      iTemp = pData[i][12];
      pData[i][12] = pData[j][12];
      pData[j][12] = iTemp;

      iTemp = pData[i][13];
      pData[i][13] = pData[j][13];
      pData[j][13] = iTemp;

      iTemp = pData[i][14];
      pData[i][14] = pData[j][14];
      pData[j][14] = iTemp;


      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) paimasu3_hot(pData,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) paimasu3_hot(pData,i,right);
}

int CMy115backDlg::sortafile_1(CString filename)//不删除重复项, 从低到高
{




  DWORD dwAttr = ::GetFileAttributes(filename); 
  if (dwAttr == 0xffffffff){return 1;} 

  
  long n,i,ubound;
  CString s,fname,wr;
  i=0;  
  CStdioFile out;
  out.Open(filename, CFile::modeRead);
  do{
    out.ReadString(s);s=delern(s);
    if (s.GetLength()>0){i=i+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();
  ubound=i-1;
  //if (ubound<=0 || ubound>50000){
    if (ubound<0){DeleteFile(filename);return 1;}
    //return 1;
  //}
  CString *data=new CString[ubound+1];
  

  

  n=0;  
  out.Open(filename, CFile::modeRead);
  //MessageBox(fname);
  do{
    out.ReadString(s);s=delern(s);  
    if (s.GetLength()>0){data[n]=s;n=n+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();


  
  paixuatoz(data,n);
  
  fname=filename+"_sort.txt";
    //MessageBox(fname);
  out.Open(fname,CFile::modeCreate|CFile::modeWrite);   
  
  for (i=0;i<n;i++){
    wr=data[i];
    
    out.Write(wr+"\r\n",wr.GetLength()+2);
	
  }
  out.Close();
  
  DeleteFile(filename);
  CFile::Rename(fname,filename);
   
  delete[] data;
  return 0;
}







///////////////////////////////////////////////////////











void CMy115backDlg::OnButton14() 
{

   
   if (JieMian!=20){jiemian(20);return;}  
   setbutton(FALSE);
   UpdateData(TRUE);
   MessageBox("程序结束!");setbutton(TRUE);
}





//////////////////////////////////////////
////////////////////////////

////////////////////////////////////////////////////////////









/*
CStdioFile pr;
pr.Open("D:\\__dlc000_1_mdir\\ssc3\\err.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);  
pr.SeekToEnd();
CString ewr;
ewr=mbfile+"\r\n";
pr.Write(ewr,ewr.GetLength());pr.Flush();
*/





////////////////////////////



/////////////////////////////////


////////////////////////////////////////////////////

void CMy115backDlg::paimasu1(int **pData,int left,int right)
{ 
  int i,j,r;
  int middle,iTemp;
  i=left;
  j=right;
  r=(left+right)/2;//left+rand()%(right-left+1);
  middle=pData[r][1];


  //i=left;
  do {
    while((pData[i][1]>middle) && (i<right))//从左扫描大于中值的数 
    i++;
    while((pData[j][1]<middle) && (j>left))//从右扫描大于中值的数 　
    j--;
    if(i<=j){//找到了一对值交换
      iTemp = pData[i][0];
      pData[i][0] = pData[j][0];
      pData[j][0] = iTemp;

      iTemp = pData[i][1];
      pData[i][1] = pData[j][1];
      pData[j][1] = iTemp;

      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) paimasu3(pData,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) paimasu3(pData,i,right);
}




////////////////////////////////////////////////////
////////////////////////////////

///////////////////////////
/////&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&






////////////////////////////////////////////////////////////




void CMy115backDlg::OnButton50() 
{




  if (JieMian!=105){jiemian(105);return;} 
  setbutton(FALSE);UpdateData(TRUE);



  int pos;
 
  CString s;

  if (m_num==1){
    skydrive();
  }//if (m_num==1){



  if (m_num==2){
//////////////////////////////////////////////////////////////////////////////
    
/////////////////////////////////////////////////////////////////////////////
     CString s,lei=m_mo;
     if (lei.GetLength()==0){lei="java";}  
     CFileFind ff;
     pos=m_dfile.ReverseFind('\\');
     if (pos<0){MessageBox("请指定目录！");setbutton(TRUE);return;}
     CString dirpath=m_dfile.Left(pos+1);
     CStdioFile fin,out;
     
     int i=0;
     CString strDir=dirpath,strPath,nake;
     CString szDir = strDir;
     szDir += "*.*"; 
     bool res = ff.FindFile(szDir); 
     while( res ) 
     {  
       res = ff.FindNextFile(); 
       strPath = ff.GetFilePath();     
       if(!ff.IsDirectory() && !ff.IsDots()){   
          pos=strPath.ReverseFind('\\');  
          nake=strPath.Mid(pos+1); 

          if (nake.Find("_window.")>=0){continue;}       
          pos=nake.ReverseFind('.');

          if (nake.Mid(pos+1)!=lei){continue;}  
       
          mactowindow(strPath);  
        }
      } 
     
      ff.Close(); 
      
  }  


  MessageBox("程序结束！");setbutton(TRUE);
}


void CMy115backDlg::tcompany(){
    CStdioFile fin,out,out1;
    CString b[32],wr,jigo,dirpath,s;
    int bl,pos,i;
    DWORD dwAttr = ::GetFileAttributes(m_dfile); 
    if (dwAttr == 0xffffffff){MessageBox("请指定数据文件");setbutton(TRUE);return;}   
    pos=m_dfile.ReverseFind('\\');
    dirpath=m_dfile.Left(pos+1);
    jigo=dirpath+"tcompany.txt";
    fin.Open(m_dfile, CFile::modeRead);
    out.Open(jigo,CFile::modeCreate|CFile::modeWrite); 
    jigo=dirpath+"tcompany.html";    
    out1.Open(jigo,CFile::modeCreate|CFile::modeWrite); 
    fin.ReadString(s);
    i=2;
    int n=0,m=0,k=0;
    CString city="New York",state="NY";
    if (m_mo.GetLength()>=3 && m_mo.Find(",")>=0){  
      pos=m_mo.Find(",");
      city=m_mo.Left(pos);state=m_mo.Mid(pos+1);
    }
    CString old="1";
    do{
      fin.ReadString(s);s=delern(s);

      Split(s, b, bl,"\t");
      if (b[0]==old){i++;continue;}
      old=b[0];
      if (b[7].Find(".")>=0){
        CString link=b[7];
        if (link.Find("http")<0){link="http://"+link;}        
        wr=padstrcisu(Cstr(i),4," ",0)+":<a href="+link+" target=_blank>"+b[0]+"</a><br>\r\n";
        out1.Write(wr,wr.GetLength());out1.Flush();
        k++;
      }
      if (b[11].Find("@")>=0 || b[14].Find("@")>=0 && b[17].Find("@")>=0 || 
         b[20].Find("@")>=0){m++;}
      if (b[11].Find("@")<0 && b[14].Find("@")<0 && b[17].Find("@")<0 && 
         b[20].Find("@")<0 && b[24].Find("@")<0 && b[25].Find("@")<0){i++;continue;}
      if (b[2]!=city || b[3]!=state){i++;continue;}
      wr=padstrcisu(Cstr(i),4," ",0)+":"+b[0]+" Recruiting Team;";
      
      if (b[11].Find("@")>=0){
        s=b[9];
        pos=b[9].Find(' ');
        if (pos>=0){
          s=b[9].Left(pos);
        }
        wr=wr+"Hello "+s+",%"+b[11]+";";
      }

      if (b[14].Find("@")>=0 && b[14]!=b[11]){
        s=b[12];
        pos=b[12].Find(' ');
        if (pos>=0){
          s=b[12].Left(pos);
        }
        wr=wr+"Hello "+s+",%"+b[14]+";";
      }

      if (b[17].Find("@")>=0 && b[17]!=b[14] && b[17]!=b[11]){
        s=b[15];
        pos=b[15].Find(' ');
        if (pos>=0){
          s=b[15].Left(pos);
        }
        wr=wr+"Hello "+s+",%"+b[17]+";";
      }

      if (b[20].Find("@")>=0 && b[20]!=b[17] && b[20]!=b[14] && b[20]!=b[11]){
        s=b[18];
        pos=b[18].Find(' ');
        if (pos>=0){
          s=b[18].Left(pos);
        }
        wr=wr+"Hello "+s+",%"+b[20]+";";
      }

      if (b[24].Find("@")>=0 && b[24]!=b[20] && b[24]!=b[17] && b[24]!=b[14] && b[24]!=b[11]){        
        wr=wr+"Dear Sir / Madam,"+"%"+b[24]+";";
      }
      if (b[25].Find("@")>=0 && b[25]!=b[24] && b[25]!=b[20] && b[25]!=b[17] && b[25]!=b[14] && b[25]!=b[11]){        
        wr=wr+"Dear Sir / Madam,"+"%"+b[25];
      }
      wr=wr+"\r\n";
      out.Write(wr,wr.GetLength());out.Flush();

      i++;n++;
    }
    while (fin.GetPosition()!=fin.GetLength());
    wr="\r\n\r\n有邮箱的有"+Cstr(n)+"个,有个人邮箱的有"+Cstr(m)+"个,有网站的有"+Cstr(k)+"个\r\n";
    out.Write(wr,wr.GetLength());
    out.Close();
    out1.Close();
    fin.Close();
}


void CMy115backDlg::tcompany_check(){
  CStdioFile fin,out;
  CInternetSession session;
  CHttpFile *file = NULL;

  int pos,i;
  CString wr,jigo,dirpath,s,link,t,strHtml,strLine,u="";
  DWORD dwAttr = ::GetFileAttributes(m_dfile); 
  if (dwAttr == 0xffffffff){MessageBox("请指定数据文件");setbutton(TRUE);return;}   
  
  fin.Open(m_dfile, CFile::modeRead);
  pos=m_dfile.ReverseFind('\\');
  dirpath=m_dfile.Left(pos+1);
  jigo=dirpath+"tcompany_check.html";
  out.Open(jigo,CFile::modeCreate|CFile::modeWrite); 
  i=1;
  bool re;
  do{
    fin.ReadString(s);s=delern(s);  
    t=s;u="";
    pos=t.Find("=");
    t=t.Mid(pos+1);
    pos=t.Find(" ");
    link=t.Left(pos);
//MessageBox(link);
    re=false; 
   
    try{
       file = (CHttpFile*)session.OpenURL(link);
    }catch(CInternetException * m_pException){
      file = NULL;
      m_pException->m_dwError;
      m_pException->Delete();
      //session.Close();
      u="-打不开</a>";re=true;
    }   
    strHtml="";
    if(file != NULL){
      while(file->ReadString(strLine) != NULL){strHtml += strLine;}
//MessageBox(strHtml);
      strHtml.MakeLower();
//MessageBox(strHtml);
      if (strHtml.Find("career")>=0 || strHtml.Find("job")>=0 || strHtml.Find("recruit")>=0 
           || strHtml.Find("human resource")>=0  ){
        u="-网页上有招聘</a>";re=true;
      }
      if (strHtml.Find("intern ")>=0 || strHtml.Find("internship")>=0 ){
        u.Replace("</a>","");
        u=u+"-有招intern</a>";re=true;
      }
    } 

    if (re){s.Replace("</a>",u);}
    wr=s+"\r\n";
    out.Write(wr,wr.GetLength());out.Flush();
    DoEvents();GetDlgItem(idc_jingdu)->SetWindowText("处理个数="+Cstr(i));i++;
    DoEvents();DoEvents();DoEvents();DoEvents();DoEvents();DoEvents();
      
  }
  while (fin.GetPosition()!=fin.GetLength());
    
  
  out.Close();
  fin.Close();
  session.Close();
}



int CMy115backDlg::sortafile_2(CString filename)//删除重复项, 从低到高,分析专用
{




  DWORD dwAttr = ::GetFileAttributes(filename); 
  if (dwAttr == 0xffffffff){return 1;} 

  
  long n,i,ubound;
  CString s,fname,wr;
  i=0;  
  CStdioFile out;
  out.Open(filename, CFile::modeRead);
  do{
    out.ReadString(s);s=delern(s);
    if (s.GetLength()>0){i=i+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();
  ubound=i-1;
  //if (ubound<=0 || ubound>50000){
    if (ubound<0){DeleteFile(filename);return 1;}
    //return 1;
  //}
  CString *data=new CString[ubound+1];
  

  

  n=0;  
  out.Open(filename, CFile::modeRead);
  //MessageBox(fname);
  do{
    out.ReadString(s);s=delern(s);  
    if (s.GetLength()>0){data[n]=s;n=n+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();


  
  paixuatoz(data,n);
  
  fname=filename+"_sort.txt";
    //MessageBox(fname);
  out.Open(fname,CFile::modeCreate|CFile::modeWrite);   
  CString old="";
  int pos;
  for (i=0;i<n;i++){
    wr=data[i];
    pos=wr.Find("[");
    s=wr.Mid(pos+1);
    pos=s.Find("]");
    s=s.Left(pos);
    if (s==old){continue;}
    old=s;
    out.Write(wr+"\r\n",wr.GetLength()+2);
	
  }
  out.Close();
  
  DeleteFile(filename);
  CFile::Rename(fname,filename);
   
  delete[] data;
  return 0;
}







void CMy115backDlg::OnButton13() 
{



   if (JieMian!=2){jiemian(2);return;}  
   setbutton(FALSE);
   UpdateData(TRUE); 
   CString jigo,dirpath,tail,head,s;
   CStdioFile fin,out,out1;
   int pos,k,j,i1;
   if (m_num==1){
     CString b[33];
     int masu=1,n,i,i1,i2;   
     m_bfile.Replace("|",":");
     pos=m_bfile.Find(":");
     tail=m_bfile.Mid(pos);
     head=m_bfile.Left(pos);
     Split(head, b, n, ",");

     for (i=0;i<6;i++){masu=masu*(n+1-i);}
     masu=masu/720;
     pos=m_dfile.ReverseFind('\\');
     dirpath=m_dfile.Left(pos+1);  


     CString *touzu=new CString[masu];
     for (i=0;i<masu;i++){touzu[i]="xx";}
     
////////////////////////////////////////////////
     k=0;     
     CString buymodefile=dirpath+"buymode.txt";
     DWORD dwAttr= ::GetFileAttributes(buymodefile);


     if (dwAttr == 0xffffffff){
       out.Open(buymodefile,CFile::modeCreate|CFile::modeWrite);
       out.Close();
       ssqfufen(head,tail,touzu,k);
     }
     else {
       fin.Open(buymodefile, CFile::modeRead);
       do{       
          fin.ReadString(s);s=delern(s);
          if (s.GetLength()<3 || s.Left(1)=="/"){continue;}
          pos=s.Find(":");         
          if (pos<0){
            pos=s.Find(",");
            if (pos<0){continue;}
            ssqfufen(head,tail,s,touzu,k);
          }    
          else {  
            i1=atoi(s.Left(pos));i2=atoi(s.Mid(pos+1));
            if (i2+n+1-i1<6){continue;}
            ssqfufen(head,tail,i1,i2,touzu,k);
          }
       }
       while (fin.GetPosition()!=fin.GetLength());

       if (k==0){ssqfufen(head,tail,touzu,k);}
//////////////////////////////////////////////
     }
     jigo=dirpath+"buy.txt";
     out.Open(jigo,CFile::modeCreate|CFile::modeWrite);
     for (i=0;i<masu;i++){
        if (touzu[i]=="xx"){break;}
        out.Write(touzu[i]+"\r\n",touzu[i].GetLength()+2); 
     }
     out.Close();
     delete[] touzu;

     MessageBox("程序结束！");setbutton(TRUE); return;
   }//if (m_num==1){

   if (m_num==2){

     int i,filenum;
     CStdioFile fin,out;
    
     pos=m_dfile.ReverseFind('\\');
     dirpath=m_dfile.Left(pos+1);
     CString strDir=dirpath;
     CString szDir = strDir,buyfile,nake; 
     CFileFind ff; 
     szDir += "*.*"; 

     bool res = ff.FindFile(szDir);       
     filenum=0;
     while( res )
     { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 
       if(!ff.IsDirectory() && !ff.IsDots()){   
         if (buyfile.Right(4)!=".txt"){continue;}      
         filenum++;
       }
     }
     ff.Close(); 


     if (filenum<2){MessageBox("程序结束！");setbutton(TRUE);return;}
     CString *filezu=new CString [filenum];
     i=0;

     res = ff.FindFile(szDir);       
     i=0;
     while( res )
     { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 
       if(!ff.IsDirectory() && !ff.IsDots()){  
         if (buyfile.Right(4)!=".txt"){continue;}   
         filezu[i]=buyfile;i++;
       }
     }
     ff.Close(); 

     
     for (i=1;i<filenum;i++){
       jointwolotterfiles(filezu[i-1],filezu[i],dirpath);
       filezu[i]=dirpath+"hebing.txt";
     }

     MessageBox("程序结束！");setbutton(TRUE);return;
   }
   
  
}



//////////////////////////////////////////////////////
///yubegin/////////////////////////////////////////////
//////////////////////////////////////////////////////
/////////////////////////////////////////////////////

void CMy115backDlg::sarrayrandom(CString a[],int alen)
{  int i,k,m,n;
  CString tmp;
  bool you;
  srand( (unsigned)time( NULL ) );
  bool *flag=new bool[alen];
  for (i=0;i<alen;i++){flag[i]=false;}
 
  while (true){
    you=false; 
    for (i=0;i<alen;i++){
      if (!flag[i]){you=true;break;}
    }
    if (! you){break;}

    n=rand()%alen;
    for (i=n;i<n+alen;i++){
      k=i%alen;
      if (flag[k]){continue;}
      break;   
    }
    n=k;

    m=rand()%alen;
    for (i=m;i<m+alen;i++){
      k=i%alen;
      if (flag[k]){continue;}
      break;   
    }
    m=k;
    tmp=a[m];a[m]=a[n];a[n]=tmp;
    flag[m]=true;flag[n]=true;
  }
  delete[] flag;
}




void CMy115backDlg::filenamejiam(CString &fname,bool flag) 
{
  CString newname=fname;   
  if (flag){
    if (fname.Right(5)!="m.txt"){
      newname=fname.Left(fname.GetLength()-4)+"m.txt";     
      CFile::Rename(fname,newname);
      fname=newname;
    }  
  }
  else {
    if (fname.Right(5)=="m.txt"){
      newname=fname.Left(fname.GetLength()-5)+".txt";     
      CFile::Rename(fname,newname);
      fname=newname;
    }
  }

}



















////////////////////////////////////////////////////
/////////////////////////////////////////////////////
///////////////////////////////////////////////////////
void CMy115backDlg::sscbtzu(small btzu[],small btzu2[],small btzu3[],small btzu4[],int &back,int &fromwei)
{
  

  int i,h_i,k;
  small rdsn[10],h_n,m; 

  fromwei=myrnd()%5;
  //back=(m_wb)+(int) (1.0*(8000-m_wb)*(rand() / (RAND_MAX + 1.0)));

  //back=(m_wb)+myrnd()%(8000-m_wb);
  i=m_wb+m_tuib;
  back=i+myrnd()%5000;
  //back=i+rand()%(8000-i);
 

  for (i=0;i<10;i++){rdsn[i]=i;}
  for (h_i=10;h_i>1;h_i--) {  
    //h_n=myrnd()%h_i; 
    h_n=rand()%h_i;

    btzu[10-h_i]=rdsn[h_n];
    if (h_n<h_i-1){
       m=rdsn[h_n];
       for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
       rdsn[h_i-1]=m;
    }		  
  }  
  btzu[9]=rdsn[0];


  for (i=0;i<10;i++){rdsn[i]=i;}    
  for (h_i=10;h_i>1;h_i--) {  
    //h_n=myrnd()%h_i; 
    h_n=rand()%h_i;   
    btzu2[10-h_i]=rdsn[h_n];
    if (h_n<h_i-1){
       m=rdsn[h_n];
       for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
       rdsn[h_i-1]=m;
    }		  
  }  
  btzu2[9]=rdsn[0];

  for (i=0;i<10;i++){rdsn[i]=i;}    
  for (h_i=10;h_i>1;h_i--) {  
    //h_n=myrnd()%h_i;  
    h_n=rand()%h_i;  
    btzu3[10-h_i]=rdsn[h_n];
    if (h_n<h_i-1){
       m=rdsn[h_n];
       for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
       rdsn[h_i-1]=m;
    }		  
  }  
  btzu3[9]=rdsn[0];

  for (i=0;i<10;i++){rdsn[i]=i;}    
  for (h_i=10;h_i>1;h_i--) {  
    //h_n=myrnd()%h_i;
    h_n=rand()%h_i;    
    btzu4[10-h_i]=rdsn[h_n];
    if (h_n<h_i-1){
       m=rdsn[h_n];
       for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
       rdsn[h_i-1]=m;
    }		  
  }  
  btzu4[9]=rdsn[0];


}





////////////////////////////////////////////////////
/////////////////////////////////////////////////////
///////////////////////////////////////////////////////
void CMy115backDlg::qxcbtzu(small btzu[],small btzu2[],small btzu3[],small btzu4[],int &back,int &fromwei)
{
  

  int i,h_i,k;
  small rdsn[10],h_n,m; 

  fromwei=rand()%7;
  //back=(m_wb)+(int) (1.0*(10)*(rand() / (RAND_MAX + 1.0)));
  //back=(m_wb+m_tuib/100+m_tuib%100)+myrnd()%10;
  i=m_wb+m_tuib;
  back=i+myrnd()%300;

 

  for (i=0;i<10;i++){rdsn[i]=i;}
  for (h_i=10;h_i>1;h_i--) {  
    //h_n=myrnd()%h_i;  
    h_n=rand()%h_i;
    btzu[10-h_i]=rdsn[h_n];
    if (h_n<h_i-1){
       m=rdsn[h_n];
       for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
       rdsn[h_i-1]=m;
    }		  
  }  
  btzu[9]=rdsn[0];


  for (i=0;i<10;i++){rdsn[i]=i;}    
  for (h_i=10;h_i>1;h_i--) {  
    //h_n=myrnd()%h_i;  
    h_n=rand()%h_i;
    btzu2[10-h_i]=rdsn[h_n];
    if (h_n<h_i-1){
       m=rdsn[h_n];
       for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
       rdsn[h_i-1]=m;
    }		  
  }  
  btzu2[9]=rdsn[0];


  for (i=0;i<10;i++){rdsn[i]=i;}    
  for (h_i=10;h_i>1;h_i--) {  
    //h_n=myrnd()%h_i;  
    h_n=rand()%h_i;
    btzu3[10-h_i]=rdsn[h_n];
    if (h_n<h_i-1){
       m=rdsn[h_n];
       for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
       rdsn[h_i-1]=m;
    }		  
  }  
  btzu3[9]=rdsn[0];

  for (i=0;i<10;i++){rdsn[i]=i;}    
  for (h_i=10;h_i>1;h_i--) {  
    //h_n=myrnd()%h_i; 
    h_n=rand()%h_i; 
    btzu4[10-h_i]=rdsn[h_n];
    if (h_n<h_i-1){
       m=rdsn[h_n];
       for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
       rdsn[h_i-1]=m;
    }		  
  }  
  btzu4[9]=rdsn[0];



}




///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////




////////////////////////////////////////////////////
/////////////////////////////////////////////////////
unsigned long CMy115backDlg::myrnd(void)
{
  unsigned long y;
  static unsigned long mag01[2]={0x0UL, MATRIX_A};
  /* mag01[x] = x * MATRIX_A for x=0,1 */
  if (mti >= N) { /* generate N words at one time */
    int kk;
    if (mti == N+1) /* if init_genrand() has not been called, */
      init_genrand(5489UL); /* a default initial seed is used */
    for (kk=0;kk<N-M;kk++) {
       y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
       mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
    }
    for (;kk<N-1;kk++) {
      y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
      mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
    }
    y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
    mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];
    mti = 0;
  }
  y = mt[mti++];
  /* Tempering */
  y ^= (y >> 11);
  y ^= (y << 7) & 0x9d2c5680UL;
  y ^= (y << 15) & 0xefc60000UL;
  y ^= (y >> 18);
  return y;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void CMy115backDlg::init_genrand(unsigned long s)
{
  mt[0]= s & 0xffffffffUL;
  for (mti=1; mti<N; mti++) {
    mt[mti] =(1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti);
    /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
    /* In the previous versions, MSBs of the seed affect */
    /* only MSBs of the array mt[]. */
    /* 2002/01/09 modified by Makoto Matsumoto */
    mt[mti] &= 0xffffffffUL;
    /* for >32 bit machines */
  }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////








///////////////////////////////////////////
////////////////////////////////////////////


//////////////////////////////////////


//////////////////////////////////////////
//////////////////////////////////////////








int CMy115backDlg::sortafileatoz(CString filename) 
{



  DWORD dwAttr = ::GetFileAttributes(filename); 
  if (dwAttr == 0xffffffff){return -1;} 

  
  long n,i,ubound;
  CString s,fname,wr;
  i=0;  
  CStdioFile out;
  out.Open(filename, CFile::modeRead);
  do{
    out.ReadString(s);s=delern(s);
    if (s.GetLength()>0){i=i+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();
  ubound=i;
  if (ubound<=0){
    if (ubound<0){DeleteFile(filename);}
    return -1;
  }
  CString *data=new CString[ubound+1];
  

  

  n=0;  
  out.Open(filename, CFile::modeRead);
  //MessageBox(fname);
  do{
    out.ReadString(s);s=delern(s);  
    if (s.GetLength()>0){data[n]=s;n=n+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();


  
  paixuatoz(data,n);
  
  fname=filename+"_sort.txt";
  out.Open(fname,CFile::modeCreate|CFile::modeWrite);   
  for (i=0;i<n;i++){
    wr=data[i];
    
    out.Write(wr+"\r\n",wr.GetLength()+2);
	
  }
  out.Close();
  
  DeleteFile(filename);
  CFile::Rename(fname,filename);
   
  delete[] data;
  return (ubound+1);  
}



int CMy115backDlg::sortafileztoa(CString filename) 
{



  DWORD dwAttr = ::GetFileAttributes(filename); 
  if (dwAttr == 0xffffffff){return -1;} 

  
  long n,i,ubound;
  CString s,fname,wr;
  i=0;  
  CStdioFile out;
  out.Open(filename, CFile::modeRead);
  do{
    out.ReadString(s);s=delern(s);
    if (s.GetLength()>0){i=i+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();
  ubound=i-1;
  if (ubound<=0){
    if (ubound<0){DeleteFile(filename);}
    return -1;
  }
  CString *data=new CString[ubound+1];
  

  

  n=0;  
  out.Open(filename, CFile::modeRead);
  //MessageBox(fname);
  do{
    out.ReadString(s);s=delern(s);  
    if (s.GetLength()>0){data[n]=s;n=n+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();


  
  paixuztoa(data,n);
  
  fname=filename+"_sort.txt";
  out.Open(fname,CFile::modeCreate|CFile::modeWrite);   
  for (i=0;i<n;i++){
    wr=data[i];
    
    out.Write(wr+"\r\n",wr.GetLength()+2);
	
  }
  out.Close();
  
  DeleteFile(filename);
  CFile::Rename(fname,filename);
   
  delete[] data;
  return (ubound+1);  
}












































void CMy115backDlg::sscgosta(CString stafile,CString stafileall,int filenum)
{

  const int ZL=3000;
  int chang=30,be,en,bei,i,j,k,m,n,su[ZL];
  CString s,t,wr;
  CStdioFile fin,out;
  CString analfile;
  CString now,old;
  CString b[100];

////////////////////////////////////////////////////////////////////////////
  analfile=stafile;

  analfile.Replace(".txt","_anal.txt");

  out.Open(analfile,CFile::modeCreate|CFile::modeWrite);

  fin.Open(stafile, CFile::modeRead);
  old="";


  for (j=0;j<ZL;j++){su[j]=0;}  
  do{
    fin.ReadString(s);s=delern(s);
    
    now=s.Left(2);

    if (now!=old){
      if (old!=""){
        for (j=ZL-1;j>=0;j--){
          if (su[j]>0){break;}
        }
        wr="";
        m=0;
        for (k=0;k<=j;k++){
          n=0;
          for (i=k;i<k+chang;i++){n+=su[i];}

          bei=0;
          if (n>0){
            bei=(filenum-m)*100/n;
          }
          wr=old+"["+padstrcisu(Cstr(k),4," ",0)+"-"+padstrcisu(Cstr(k+chang-1),4," ",0)+"]="+padstrcisu(Cstr(n),3," ",0)+","+padstrcisu(Cstr(filenum-m),5," ",0)
                  +"   "+Cstr(bei)+"\r\n";
          out.Write(wr,wr.GetLength());
          m+=su[k];  
        }         
      }

      for (j=0;j<ZL;j++){su[j]=0;}
      old=now;
    } 

       
    
    if (now=="S1"){break;}

    s=s.Mid(3);

    if (s.Left(1)=="X"){continue;}
    n=atoi(s.Left(4));
    su[n]++;
    

  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();out.Close();

///////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
  int bl,l2num=0,r2num=0,l3num=0,r3num=0,r4num=0,r5num=0;
  analfile=stafileall;
  analfile.Replace(".txt","_anal.txt");
  out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
  fin.Open(stafileall, CFile::modeRead);
  old="";
  for (j=0;j<ZL;j++){su[j]=0;}  
  do{
    fin.ReadString(s);s=delern(s);
    if (s.GetLength()<=3){continue;}
    now=s.Left(2);

    if (now!=old){


      for (j=ZL-1;j>=0;j--){
        if (su[j]>0){break;}
      }

      wr="";
       
      for (k=0;k<=j;k++){
        bei=0;
        if (su[k]>0){
          bei=(filenum)*100/su[k];
        }
        wr=old+"["+padstrcisu(Cstr(k),4," ",0)+"-"+padstrcisu(Cstr(k+chang-1),4," ",0)+"]="+padstrcisu(Cstr(su[k]),3," ",0)+","+padstrcisu(Cstr(filenum),5," ",0)
                  +"   "+Cstr(bei)+"\r\n";
        out.Write(wr,wr.GetLength());
          
      }         


      for (j=0;j<ZL;j++){su[j]=0;}
      old=now;
    } 

    
    

    s=s.Mid(3);

    Split(s,b,bl,",");

    for (j=0;j<=bl;j++){
      n=atoi(b[j]);
      be=n-chang+1;
      en=be+chang;
      if (be<0){be=0;}
      for (i=be;i<en;i++){
        su[i]++;
      }
      if (now=="L2"){l2num++;}
      if (now=="R2"){r2num++;}
      if (now=="L3"){l3num++;}    
      if (now=="R3"){r3num++;}
      if (now=="R4"){r4num++;}
      if (now=="R5"){r5num++;}
    }
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();out.Close();
///////////////////////////////////////////////
  CString *datal2,*datal3,*datar2,*datar3,*datar4,*datar5;


  if (l2num+l3num+r2num+r3num+r4num+r5num>0){
    int il2=0,il3=0,ir2=0,ir3=0,ir4=0,ir5=0;
    if (l2num>0){datal2=new CString[l2num];}
    if (l3num>0){datal3=new CString[l3num];}
    if (r2num>0){datar2=new CString[r2num];}
    if (r3num>0){datar3=new CString[r3num];}
    if (r4num>0){datar4=new CString[r4num];}
    if (r5num>0){datar5=new CString[r5num];}



    fin.Open(stafileall, CFile::modeRead);

     
    do{
      fin.ReadString(s);s=delern(s);
      if (s.Left(1)=="Z"){break;}
      now=s.Left(2);
      s=s.Mid(3);
      Split(s,b,bl,",");
      for (j=0;j<=bl;j++){
        t=padstrcisu(b[j],4," ",0);
        if (now=="L2"){datal2[il2]=t;il2++;}
        if (now=="L3"){datal3[il3]=t;il3++;}
        if (now=="R2"){datar2[ir2]=t;ir2++;}
        if (now=="R3"){datar3[ir3]=t;ir3++;}
        if (now=="R4"){datar4[ir4]=t;ir4++;}
        if (now=="R5"){datar5[ir5]=t;ir5++;}
        
      }
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
//////////////////////////////////////////
    if (l2num>0){
       paixuatoz(datal2,l2num);

       analfile=stafileall;
       analfile.Replace(".txt","_l2.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<l2num;i++){
         wr=datal2[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datal2;
    }
  
//////////////////////////////////////////


//////////////////////////////////////////
    if (l3num>0){
       paixuatoz(datal3,l3num);

       analfile=stafileall;
       analfile.Replace(".txt","_l3.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<l3num;i++){
         wr=datal3[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datal3;
    }

//////////////////////////////////////////



//////////////////////////////////////////
   if (r2num>0){
       paixuatoz(datar2,r2num);

       analfile=stafileall;
       analfile.Replace(".txt","_r2.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<r2num;i++){
         wr=datar2[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datar2;
   }

//////////////////////////////////////////



//////////////////////////////////////////
    if (r3num>0){
       paixuatoz(datar3,r3num);

       analfile=stafileall;
       analfile.Replace(".txt","_r3.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<r3num;i++){
         wr=datar3[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datar3;
    }
  
//////////////////////////////////////////



//////////////////////////////////////////
    if (r4num>0){
       paixuatoz(datar4,r4num);

       analfile=stafileall;
       analfile.Replace(".txt","_r4.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<r4num;i++){
         wr=datar4[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datar4;
    }
  
//////////////////////////////////////////



//////////////////////////////////////////
    if (r5num>0){
       paixuatoz(datar5,r5num);

       analfile=stafileall;
       analfile.Replace(".txt","_r5.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<r5num;i++){
         wr=datar5[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datar5;
    }
  }
//////////////////////////////////////////



}






void CMy115backDlg::qxcgosta(CString stafile,CString stafileall,int filenum)
{

  const int ZL=3000;
  int chang=3,be,en,bei,i,j,k,m,n,su[ZL];
  CString s,t,wr;
  CStdioFile fin,out;
  CString analfile=stafile;
  CString now,old="";

  CString b[100];
////////////////////////////////////////////////////////////////////////////
  analfile=stafile;

  analfile.Replace(".txt","_anal.txt");

  out.Open(analfile,CFile::modeCreate|CFile::modeWrite);

  fin.Open(stafile, CFile::modeRead);
  old="";


  for (j=0;j<ZL;j++){su[j]=0;}  
  do{
    fin.ReadString(s);s=delern(s);
    
    now=s.Left(2);

    if (now!=old){
      if (old!=""){
        for (j=ZL-1;j>=0;j--){
          if (su[j]>0){break;}
        }
        wr="";
        m=0;
        for (k=0;k<=j;k++){
          n=0;
          for (i=k;i<k+chang;i++){n+=su[i];}

          bei=0;
          if (n>0){
            bei=(filenum-m)*100/n;
          }
          wr=old+"["+padstrcisu(Cstr(k),4," ",0)+"-"+padstrcisu(Cstr(k+chang-1),4," ",0)+"]="+padstrcisu(Cstr(n),3," ",0)+","+padstrcisu(Cstr(filenum-m),5," ",0)
                  +"   "+Cstr(bei)+"\r\n";
          out.Write(wr,wr.GetLength());
          m+=su[k];  
        }         
      }

      for (j=0;j<ZL;j++){su[j]=0;}
      old=now;
    } 

       
    
    if (now=="S1"){break;}

    s=s.Mid(3);

    if (s.Left(1)=="X"){continue;}
    n=atoi(s.Left(4));
    su[n]++;
    

  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();out.Close();

///////////////////////////////////////////////

  int bl,l2num=0,l3num=0,l4num=0,l5num=0,l6num=0,l7num=0;
  analfile=stafileall;
  analfile.Replace(".txt","_anal.txt");
  out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
  fin.Open(stafileall, CFile::modeRead);

  old="";
  for (j=0;j<ZL;j++){su[j]=0;}  
  do{
    fin.ReadString(s);s=delern(s);
    if (s.GetLength()<=3){continue;}
    now=s.Left(2);

    if (now!=old){

     

      for (j=ZL-1;j>=0;j--){
        if (su[j]>0){break;}
      }

      wr="";
       
      for (k=0;k<=j;k++){
        bei=0;
        if (su[k]>0){
          bei=(filenum)*100/su[k];
        }
        wr=old+"["+padstrcisu(Cstr(k),4," ",0)+"-"+padstrcisu(Cstr(k+chang-1),4," ",0)+"]="+padstrcisu(Cstr(su[k]),3," ",0)+","+padstrcisu(Cstr(filenum),5," ",0)
                +"   "+Cstr(bei)+"\r\n";
        out.Write(wr,wr.GetLength());
         
      }         


      for (j=0;j<ZL;j++){su[j]=0;}
      old=now;
    } 

    
    

    s=s.Mid(3);  
    Split(s,b,bl,",");

    for (j=0;j<=bl;j++){
      n=atoi(b[j]);
      be=n-chang+1;
      en=be+chang;
      if (be<0){be=0;}
      for (i=be;i<en;i++){
        su[i]++;
      }
      if (now=="L2"){l2num++;}
      if (now=="L3"){l3num++;}    
      if (now=="L4"){l4num++;}
      if (now=="L5"){l5num++;}
      if (now=="L6"){l6num++;}
      if (now=="L7"){l7num++;}
    }

  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();out.Close();
///////////////////////////////////////////////
  CString *datal2,*datal3,*datal4,*datal5,*datal6,*datal7;


  if (l2num+l3num+l4num+l5num+l6num+l7num>0){
    int il2=0,il3=0,il4=0,il5=0,il6=0,il7=0;
    if (l2num>0){datal2=new CString[l2num];}
    if (l3num>0){datal3=new CString[l3num];}
    if (l4num>0){datal4=new CString[l4num];}
    if (l5num>0){datal5=new CString[l5num];}
    if (l6num>0){datal6=new CString[l6num];}
    if (l7num>0){datal7=new CString[l7num];}



    fin.Open(stafileall, CFile::modeRead);

     
    do{
      fin.ReadString(s);s=delern(s);
      if (s.Left(1)=="Z"){break;}
      now=s.Left(2);
      s=s.Mid(3);
      Split(s,b,bl,",");
      for (j=0;j<=bl;j++){
        t=padstrcisu(b[j],4," ",0);
        if (now=="L2"){datal2[il2]=t;il2++;}
        if (now=="L3"){datal3[il3]=t;il3++;}
        if (now=="L4"){datal4[il4]=t;il4++;}
        if (now=="L5"){datal5[il5]=t;il5++;}
        if (now=="L6"){datal6[il6]=t;il6++;}
        if (now=="L7"){datal7[il7]=t;il7++;}
        
      }
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
//////////////////////////////////////////
    if (l2num>0){
       paixuatoz(datal2,l2num);

       analfile=stafileall;
       analfile.Replace(".txt","_l2.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<l2num;i++){
         wr=datal2[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datal2;
    }
  
//////////////////////////////////////////


//////////////////////////////////////////
    if (l3num>0){
       paixuatoz(datal3,l3num);

       analfile=stafileall;
       analfile.Replace(".txt","_l3.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<l3num;i++){
         wr=datal3[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datal3;
    }

//////////////////////////////////////////



//////////////////////////////////////////
   if (l4num>0){
       paixuatoz(datal4,l4num);

       analfile=stafileall;
       analfile.Replace(".txt","_l4.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<l4num;i++){
         wr=datal4[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datal4;
   }

//////////////////////////////////////////



//////////////////////////////////////////
    if (l5num>0){
       paixuatoz(datal5,l5num);

       analfile=stafileall;
       analfile.Replace(".txt","_l5.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<l5num;i++){
         wr=datal5[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datal5;
    }
  
//////////////////////////////////////////



//////////////////////////////////////////
    if (l6num>0){
       paixuatoz(datal6,l6num);

       analfile=stafileall;
       analfile.Replace(".txt","_l6.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<l6num;i++){
         wr=datal6[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datal6;
    }
  
//////////////////////////////////////////



//////////////////////////////////////////
    if (l7num>0){
       paixuatoz(datal7,l7num);

       analfile=stafileall;
       analfile.Replace(".txt","_l7.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<l7num;i++){
         wr=datal7[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datal7;
    }
  }
//////////////////////////////////////////



}







//m_e











void CMy115backDlg::ssqgosta(CString stafile,CString stafileall,int filenum)
{

  const int ZL=3000;
  int chang=3,be,en,bei,i,j,k,m,n,su[ZL];
  CString s,t,wr;
  CStdioFile fin,out;
  CString analfile=stafile;
  CString now,old="";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
  CString b[100];

////////////////////////////////////////////////////////////////////////////
  analfile=stafile;

  analfile.Replace(".txt","_anal.txt");

  out.Open(analfile,CFile::modeCreate|CFile::modeWrite);

  fin.Open(stafile, CFile::modeRead);
  old="";


  for (j=0;j<ZL;j++){su[j]=0;}  
  do{
    fin.ReadString(s);s=delern(s);
    
    now=s.Left(2);

    if (now!=old){
      if (old!=""){
        for (j=ZL-1;j>=0;j--){
          if (su[j]>0){break;}
        }
        wr="";
        m=0;
        for (k=0;k<=j;k++){
          n=0;
          for (i=k;i<k+chang;i++){n+=su[i];}

          bei=0;
          if (n>0){
            bei=(filenum-m)*100/n;
          }
          wr=old+"["+padstrcisu(Cstr(k),4," ",0)+"-"+padstrcisu(Cstr(k+chang-1),4," ",0)+"]="+padstrcisu(Cstr(n),3," ",0)+","+padstrcisu(Cstr(filenum-m),5," ",0)
                  +"   "+Cstr(bei)+"\r\n";
          out.Write(wr,wr.GetLength());
          m+=su[k];  
        }         
      }

      for (j=0;j<ZL;j++){su[j]=0;}
      old=now;
    } 

       
    
    if (now=="S1"){break;}

    s=s.Mid(3);

    if (s.Left(1)=="X"){continue;}
    n=atoi(s.Left(4));
    su[n]++;
    

  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();out.Close();

///////////////////////////////////////////////


  int bl,l4num=0,l5num=0,t1num=0;
  analfile=stafileall;
  analfile.Replace(".txt","_anal.txt");
  out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
  fin.Open(stafileall, CFile::modeRead);

  old="";
  for (j=0;j<ZL;j++){su[j]=0;}  
  do{
    fin.ReadString(s);s=delern(s);
    if (s.GetLength()<=3){continue;}
    now=s.Left(2);

    if (now!=old){


      for (j=ZL-1;j>=0;j--){
        if (su[j]>0){break;}
      }

      wr="";
       
      for (k=0;k<=j;k++){
        bei=0;
        if (su[k]>0){
          bei=(filenum)*100/su[k];
        }
        wr=old+"["+padstrcisu(Cstr(k),4," ",0)+"-"+padstrcisu(Cstr(k+chang-1),4," ",0)+"]="+padstrcisu(Cstr(su[k]),3," ",0)+","+padstrcisu(Cstr(filenum),5," ",0)
                +"   "+Cstr(bei)+"\r\n";
        out.Write(wr,wr.GetLength());
          
      }         


      for (j=0;j<ZL;j++){su[j]=0;}
      old=now;
    } 

    
    
////////////////////
    s=s.Mid(3);

    Split(s,b,bl,",");

    for (j=0;j<=bl;j++){
      n=atoi(b[j]);
      be=n-chang+1;
      en=be+chang;
      if (be<0){be=0;}
      for (i=be;i<en;i++){
        su[i]++;
      }
      if (now=="L4"){l4num++;}
      if (now=="L5"){l5num++;}
      if (now=="E1"){t1num++;}
    }



///////////////////////
      
   }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();out.Close();

///////////////////////////////////////////////
  CString *datal4,*datal5,*datat1;

 
  if (l4num+l5num+t1num>0){
    int il4=0,il5=0,it1=0;
    if (l4num>0){datal4=new CString[l4num];}
    if (l5num>0){datal5=new CString[l5num];}
    if (t1num>0){datat1=new CString[t1num];}
    



    fin.Open(stafileall, CFile::modeRead);

     
    do{
      fin.ReadString(s);s=delern(s);
      if (s.Left(1)=="Z"){break;}
      now=s.Left(2);
      s=s.Mid(3);
      Split(s,b,bl,",");
      for (j=0;j<=bl;j++){
        t=padstrcisu(b[j],4," ",0);
        if (now=="L4"){datal4[il4]=t;il4++;}
        if (now=="L5"){datal5[il5]=t;il5++;}
        if (now=="E1"){datat1[it1]=t;it1++;}

       
        
      }
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();


//////////////////////////////////////////
    if (l4num>0){
       paixuatoz(datal4,l4num);

       analfile=stafileall;
       analfile.Replace(".txt","_l4.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<l4num;i++){
         wr=datal4[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datal4;
    }

//////////////////////////////////////////







//////////////////////////////////////////
    if (l5num>0){
       paixuatoz(datal5,l5num);

       analfile=stafileall;
       analfile.Replace(".txt","_l5.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<l5num;i++){
         wr=datal5[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datal5;
    }
  
//////////////////////////////////////////


//////////////////////////////////////////
    if (t1num>0){
       paixuatoz(datat1,t1num);

       analfile=stafileall;
       analfile.Replace(".txt","_t1.txt");
       out.Open(analfile,CFile::modeCreate|CFile::modeWrite);
       for (i=0;i<t1num;i++){
         wr=datat1[i];

         if (i%20==19){
           wr=wr+"\r\n";
         }
         else {wr=wr+" ";}


         out.Write(wr,wr.GetLength());
 
      }
      out.Close();
      delete[] datat1;
    }
  }  
//////////////////////////////////////////


}











void CMy115backDlg::skydrive(){
/*
CStdioFile pr;
pr.Open("E:\\adrive\\folder\\err.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);  
pr.SeekToEnd();
CString ewr;
ewr="jin\r\n";
pr.Write(ewr,ewr.GetLength());pr.Flush();
*/
    CStdioFile out;
    CString dirpath,s,t,name1,name2;
    int pos;
    DWORD dwAttr = ::GetFileAttributes(m_dfile); 
    if (dwAttr == 0xffffffff){MessageBox("请指定数据文件");setbutton(TRUE);return;}   
    pos=m_dfile.ReverseFind('\\');
    dirpath=m_dfile.Left(pos+1);
    CString newdir,na1,na2;
////////////////////////////////////////////////////////////////CFile::Rename(fname,newname);
    out.Open(m_dfile, CFile::modeRead);
    do{
      out.ReadString(s);s=delern(s);
      s.Replace("/","\\");
      if (s.Find("Original File Name")>=0){continue;}
      pos=s.Find(" -> ");

      if (pos<=0){continue;}   
  
      t=s.Mid(pos+4);
      s=s.Left(pos);
/*
ewr="s="+s+"\r\nt="+t+"\r\n";
pr.Write(ewr,ewr.GetLength());pr.Flush();
*/
      pos=t.ReverseFind('\\');
      newdir=dirpath;
      if (pos>=0){newdir=newdir+t.Left(pos+1);}
      name2=dirpath+t;
      pos=s.ReverseFind('\\');
      if (pos<0){
        name1=dirpath+s;        
      }
      else {name1=newdir+s.Mid(pos+1);}
      dwAttr = ::GetFileAttributes(name2); 
/*
ewr="name1="+name1+"\r\nname2="+name2+"\r\n";
pr.Write(ewr,ewr.GetLength());pr.Flush();
*/
      if (dwAttr == 0xffffffff){continue;}   
      CFile::Rename(name2,name1);
    }
    while (out.GetPosition()!=out.GetLength());
    out.Close();    
}










int CMy115backDlg::sortafileatoz_2(CString filename)//删除重复项, 从低到高
{




  DWORD dwAttr = ::GetFileAttributes(filename); 
  if (dwAttr == 0xffffffff){return 1;} 

  
  long n,i,ubound;
  CString s,fname,wr;
  i=0;  
  CStdioFile out;
  out.Open(filename, CFile::modeRead);
  do{
    out.ReadString(s);s=delern(s);
    if (s.GetLength()>0){i=i+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();
  ubound=i-1;
  CString *data=new CString[ubound+1];
  

  

  n=0;  
  out.Open(filename, CFile::modeRead);
  //MessageBox(fname);
  do{
    out.ReadString(s);s=delern(s);  
    if (s.GetLength()>0){data[n]=s;n=n+1;}
  }
  while (out.GetPosition()!=out.GetLength());
  out.Close();


  
  paixuatoz(data,n);
  
  fname=filename+"_sort.txt";
    //MessageBox(fname);
  out.Open(fname,CFile::modeCreate|CFile::modeWrite);   
  CString old="";
  //int pos;
  for (i=0;i<n;i++){
    wr=data[i];
    if (wr==old){continue;}
    old=wr;
    out.Write(wr+"\r\n",wr.GetLength()+2);
	
  }
  out.Close();
  
  DeleteFile(filename);
  CFile::Rename(fname,filename);
   
  delete[] data;
  return 0;
}



void CMy115backDlg::OnButton26() 
{
   if (JieMian!=24){jiemian(24);return;}  
   
   setbutton(FALSE);
   UpdateData(TRUE); 
   //function26();
   int pos;
   CString wr,s,dirpath,b[10];
   pos=m_dfile.ReverseFind('\\');
   dirpath=m_dfile.Left(pos+1);

   CStdioFile fin;
   CString strDir=dirpath;
   CString szDir = strDir,datafile; 
   CFileFind ff; 
   szDir += "*.*"; 


   bool res = ff.FindFile(szDir);   


///////////////////////////////////////////////////////
   CStdioFile out2;
   CString nake;
   while( res ) 
   { 
      res = ff.FindNextFile(); 
      datafile = ff.GetFilePath(); 
      pos=datafile.ReverseFind('\\');
      nake=datafile.Mid(pos+1); 
      if(!ff.IsDirectory() && !ff.IsDots()){
        if (datafile.Right(3)!="txt"){continue;}; 
        if (datafile.Right(9)=="_dian.txt"){continue;}; 
        if (nake.Find("统计.txt")>=0){continue;}
        if (nake.Find("_new.txt")>=0){continue;}
        if (nake.Find("_old.txt")>=0){continue;}
        if (nake.Find("alllinks.txt")>=0){continue;}
        pos=nake.Find("-");
        MMO=nake.Left(pos);
        CString dianfile=dirpath+MMO+"_dian.txt";
        out2.Open(dianfile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);  
        out2.SeekToEnd();        
        taobaolinks(datafile,dirpath,out2);
        out2.Close();
        taobao_dianfile(dirpath,dianfile);
      }
   } 
   ff.Close();



   taobaoalllinks(dirpath);
   MessageBox("程序结束！");setbutton(TRUE);
}




void CMy115backDlg::taobaolinks_chang(CString *data,int ubound,CString dirpath,CString shun){
   
   DWORD dwAttr;
   int i,bl,j;
   CString b[10],s,wr,fname;


   CStdioFile out1,out2;
   

   int chang1=m_btui,chang2=m_mas;
   CString wpath=dirpath+"allwen\\";
   if(_access(wpath, 0) == -1){_mkdir(wpath);}
   
   
  

   bool f1,f2;
   for (i=1;i<=ubound;i++){
  
      if (i%chang1==1){
        j=1;
        while (true){
          fname=wpath+"淘宝店商品价格采样(无图,"+shun+")_"+MMO+"_"+Cstr(j)+".html";
          dwAttr= ::GetFileAttributes(fname);
          if (dwAttr == 0xffffffff){break;}
          j++;
        }

        out1.Open(fname,CFile::modeCreate|CFile::modeWrite);
        f1=false;
      }

      if (i%chang2==1){
        j=1;
        while (true){
          fname=wpath+"淘宝店商品价格采样(有图,"+shun+")_"+MMO+"_"+Cstr(j)+".html";
          dwAttr= ::GetFileAttributes(fname);
          if (dwAttr == 0xffffffff){break;}
          j++;
        }

        out2.Open(fname,CFile::modeCreate|CFile::modeWrite);
        

        f2=false;
      }
      

      s=data[i-1];
      

      Split(s,b,bl,"\t");
      b[3].TrimLeft();b[3].TrimRight();
      //店名0，宝贝名1，时间2,价格3，宝贝链接4，店铺链接5，图片6
      if (shun=="店名顺序"){
        wr="商铺名称:<a href="+b[5]+" target=_blank>"+b[0]+"</a>[采样时间:"+b[2]+"]<br>\r\n";
        wr=wr+"采样商品:<a href="+b[4]+" target=_blank>"+b[1]+"</a>[采样时价格:"+b[3]+"]<br>\r\n";
      }
      else {
        wr="商铺名称:<a href="+b[5]+" target=_blank>"+b[3]+"</a>[采样时间:"+b[2]+"]<br>\r\n";
        wr=wr+"采样商品:<a href="+b[4]+" target=_blank>"+b[1]+"</a>[采样时价格:"+b[0]+"]<br>\r\n";
      }
      out1.Write(wr+"<hr><br>\r\n",wr.GetLength()+10);
      wr=wr+"采样时图片:<br>\r\n";
      wr=wr+"<img src="+b[6]+"></img><br><hr><br>\r\n";
      out2.Write(wr,wr.GetLength());
      
      if (i%chang1==0){
        wr="<a href=http://pan.baidu.com/s/"+m_mo+" target=_blank><strong>资源下载</strong></a><br>\r\n";
        out1.Write(wr,wr.GetLength());
        out1.Close();
        f1=true;
      }
      if (i%chang2==0){
        wr="<a href=http://pan.baidu.com/s/"+m_mo+" target=_blank><strong>资源下载</strong></a><br>\r\n";
        out2.Write(wr,wr.GetLength());
        out2.Close();
        f2=true;
      }

      
     
   }

   if (!f1){
      out1.Close();
   }
   if (!f2){
      out2.Close();
   }

 


}





void CMy115backDlg::taobao_dianfile(CString dirpath,CString dianfile){
   
   int i,j,bl,pos;
   CString s,wr,b[10];
   CStdioFile fin;
////////////////////////////////////////////////
////////////////////////////////////////////////   
   sortafileatoz_2(dianfile);
   ////////////////////////////////////////////
   


   ///////////////////////////////////////////

   /////////////////////
   CString timestr="";
   i=0;j=0;
   fin.Open(dianfile, CFile::modeRead);
   do{
     fin.ReadString(s);s=delern(s);
     j++;
     Split(s,b,bl,"\t");
     if (timestr.Find(b[2])<0){timestr=timestr+b[2]+"\t";i++;}
   }
   while (fin.GetPosition()!=fin.GetLength());   
   fin.Close(); 
   if (timestr.GetLength()>0){timestr=timestr.Left(timestr.GetLength()-1);}
   int tnum=i,ubound=j;
   CString *ts=new CString [tnum];
   float **txu=new float *[tnum];
   CString *data=new CString [ubound];
   for (i=0;i<tnum;i++){
     *(txu+i)=new float [4];
   }
   for (i=0;i<tnum;i++){
     txu[i][0]=0;txu[i][1]=0;txu[i][2]=99999999;txu[i][3]=0;
   }
   Split(timestr,ts,bl,"\t");
   paixuatoz(ts,tnum);
   double jia;
   fin.Open(dianfile, CFile::modeRead);
   j=0;
   do{
     fin.ReadString(s);s=delern(s);
     Split(s,b,bl,"\t");
     //////////////////////////////////////////
     data[j]=b[0]+"\t"+b[1]+"\t"+b[2]+"\t"+b[3]+"\t"+b[4]+"\t"+b[5]+"\t"+b[6];j++;
     /////////////////////////////////////////
         
     for (i=0;i<tnum;i++){
       if (ts[i]==b[2]){txu[i][3]++;break;}
     }
     jia=atof(b[3]);
     txu[i][0]+=jia;
     if (jia>txu[i][1]){txu[i][1]=jia;}
     if (jia<txu[i][2]){txu[i][2]=jia;}
   }
   while (fin.GetPosition()!=fin.GetLength());   
   fin.Close(); 

   
   for (i=0;i<tnum;i++){txu[i][0]=txu[i][0]/txu[i][3];}
   fin.Open(dirpath+"淘宝商品历史价格采样统计.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);  
   fin.SeekToEnd();
   for (i=0;i<tnum;i++){     
     wr=padstrcisu(MMO,20," ",1);
     s.Format("%10.2f",txu[i][0]);     
     wr=wr+ts[i]+"\t平均价格:"+s;
     s.Format("%10.2f",txu[i][1]);
     wr=wr+"\t最高价格:"+s;
     s.Format("%10.2f",txu[i][2]);
     wr=wr+"\t最低价格:"+s;
     pos=txu[i][3];
     wr=wr+"\t采样数量:"+Cstr(pos)+"\r\n";
     fin.Write(wr,wr.GetLength());
   }
   fin.Close();
   sortafileatoz_2(dirpath+"淘宝商品历史价格采样统计.txt");   
   for (i=0;i<tnum;i++){
     delete[] txu[i];
   }
   delete[] txu;delete[] ts;
   //////////////////////
   taobaolinks_chang(data,ubound,dirpath,"店名顺序");

/////////////////////////////////////////////////////
   
   
   fin.Open(dianfile, CFile::modeRead);
   i=0;
   do{
     fin.ReadString(s);s=delern(s);
     Split(s,b,bl,"\t");
     wr=b[3]+"\t"+b[1]+"\t"+b[2]+"\t"+b[0]+"\t"+b[4]+"\t"+b[5]+"\t"+b[6];
     data[i]=wr;
     i++;
   }
   while (fin.GetPosition()!=fin.GetLength());   
   fin.Close();
   paixuatoz(data,ubound);
   
   taobaolinks_chang(data,ubound,dirpath,"价格顺序");
   delete[] data;
   
/////////////////////////////////////////////////////

}




void CMy115backDlg::taobaoalllinks(CString dirpath){
   
   int i,bl,j;
   CString b[10],s,wr,fname;


   CStdioFile fin,out1,out2;
   

   int chang1=m_btui;
   CString wpath=dirpath+"allwen\\";
   if(_access(wpath, 0) == -1){_mkdir(wpath);}

   
   CString strDir=dirpath;
   CString szDir = strDir,datafile; 
   CFileFind ff; 
   szDir += "*.*"; 


   bool res = ff.FindFile(szDir);   


///////////////////////////////////////////////////////
   
   CString alllinkfile=dirpath+"alllinks.txt",purlinkfile=dirpath+"purelinks_new.txt";
   out1.Open(alllinkfile,CFile::modeCreate|CFile::modeWrite);  
   out2.Open(purlinkfile,CFile::modeCreate|CFile::modeWrite);  
  
   while( res ) 
   { 
      res = ff.FindNextFile(); 
      datafile = ff.GetFilePath();     
      if(!ff.IsDirectory() && !ff.IsDots()){       
        if (datafile.Right(9)!="_dian.txt"){continue;}; 
        fin.Open(datafile, CFile::modeRead);	
        do{
          fin.ReadString(s);s=delern(s);
	  wr=s+"\r\n";
          out1.Write(wr,wr.GetLength());
          
        }
        while (fin.GetPosition()!=fin.GetLength());
        fin.Close();
      }
   } 
   ff.Close();
   out1.Close();
   sortafileatoz_2(alllinkfile);
////////////////////////////////////////////////////////////////////
   bool f1;
   i=0;j=1;
   fin.Open(alllinkfile, CFile::modeRead);	
   do{
      i++;
      if (i%chang1==1){
        fname=wpath+"淘宝店商品价格采样_所有采样商品"+Cstr(j)+".html";j++;
        out1.Open(fname,CFile::modeCreate|CFile::modeWrite);        
        f1=false;
      }

      

      fin.ReadString(s);s=delern(s);
      

      Split(s,b,bl,"\t");
      wr="商铺名称:<a href="+b[5]+" target=_blank>"+b[0]+"</a>[采样时间:"+b[2]+"]<br>\r\n";
      wr=wr+"采样商品:<a href="+b[4]+" target=_blank>"+b[1]+"</a>[采样时价格:"+b[3]+"]<br>\r\n";
      out1.Write(wr+"<hr><br>\r\n",wr.GetLength()+10);
      wr=b[4]+"\r\n"+b[6]+"\r\n";
      out2.Write(wr,wr.GetLength());
     
      if (i%chang1==0){
        wr="<a href=http://pan.baidu.com/s/"+m_mo+" target=_blank><strong>资源下载</strong></a><br>\r\n";
        out1.Write(wr,wr.GetLength());
        out1.Close();
        f1=true;
      }

      
   }  
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   out2.Close();
   if (!f1){
      wr="<a href=http://pan.baidu.com/s/"+m_mo+" target=_blank><strong>资源下载</strong></a><br>\r\n";
      out1.Write(wr,wr.GetLength());

      out1.Close();
   }

////////////////////////////////////////////

   DWORD dwAttr;
   CString oldpurelinkfile=dirpath+"purelinks_old.txt";
   dwAttr= ::GetFileAttributes(oldpurelinkfile);
   if (dwAttr == 0xffffffff){return;}
   fin.Open(oldpurelinkfile, CFile::modeRead);	
   i=0;
   do{
     fin.ReadString(s);s=delern(s);
     if (s.GetLength()>20){i++;}     
   }  
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   if (i==0){return;}
   int ubound=i;

   CString *olddata=new CString [ubound];
   i=0;
   fin.Open(oldpurelinkfile, CFile::modeRead);
   do{
     fin.ReadString(s);s=delern(s);
     if (s.GetLength()>20){olddata[i]=s;i++;}     
   }  
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   CString tmp=dirpath+"tmp.txt";
   out1.Open(tmp,CFile::modeCreate|CFile::modeWrite);  
   bool you;
   fin.Open(purlinkfile, CFile::modeRead);
   do{
     fin.ReadString(s);s=delern(s);
     you=false;
     for (i=0;i<ubound;i++){
       if (s==olddata[i]){you=true;break;}
     }
     if (! you){out1.Write(s+"\r\n",s.GetLength()+2);}
   }  
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();out1.Close();
   CopyFile(tmp,purlinkfile,0);
   DeleteFile(tmp);
   delete[] olddata;   
////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////   


}



void CMy115backDlg::taobaolinks(CString datafile,CString dirpath,CStdioFile &out2){
   
   DWORD dwAttr;
   int i,pos,bl,j,j1,k;
   CString b[10],s,wr,fname;


   CStdioFile fin,out1,outpost;
   fin.Open(datafile, CFile::modeRead);
   fin.ReadString(s);
   if (s.Find("导出日期")!=0){return;}
   pos=datafile.ReverseFind('\\');
   CString nake=datafile.Mid(pos+1);
   pos=nake.Find("-");
   MMO=nake.Left(pos);
   CString wpath=dirpath+"wen\\";
   if(_access(wpath, 0) == -1){_mkdir(wpath);}   
   

   int chang1=m_num,chang2=m_mas;

   i=0;k=0;
   bool f1,f2;
   do{
      i++;
      if (i%chang1==1){
        j=1;
        while (true){
          fname=wpath+"淘宝店商品价格采样_"+MMO+"_"+Cstr(j)+".html";
          dwAttr= ::GetFileAttributes(fname);
          if (dwAttr == 0xffffffff){break;}
          j++;
        }

        out1.Open(fname,CFile::modeCreate|CFile::modeWrite);
        f1=false;
      }

      fin.ReadString(s);s=delern(s);
      

      Split(s,b,bl,"\t");
      wr="店铺名称:<a href="+b[6]+" target=_blank>"+b[5]+"</a>[采样时间:"+b[0]+"]<br>\r\n";
      wr=wr+"采样商品:<a href="+b[4]+" target=_blank>"+b[2]+"</a>[采样时价格:"+b[3]+"元]<br>\r\n";
      wr=wr+"采样时图片:<br>\r\n";
      wr=wr+"<img src="+b[1]+"></img><br><hr><br>\r\n";
      out1.Write(wr,wr.GetLength());
      
      //店名0，宝贝名1，时间2,价格3，宝贝链接4，店铺链接5，图片6
      wr=b[5]+"\t"+b[2]+"\t"+b[0]+"\t"+padstrcisu(b[3],8," ",0)+"\t"+b[4]+"\t"+b[6]+"\t"+b[1]+"\r\n";
      out2.Write(wr,wr.GetLength());
      if (i%chang1==0){
        wr="<a href=http://pan.baidu.com/s/"+m_mo+" target=_blank><strong>资源下载</strong></a><br>\r\n";
        out1.Write(wr,wr.GetLength());
        out1.Close();
        f1=true;
      }

      if (atof(b[3])>=100){
        k++;
        if (k%chang1==1){
          j1=1;
          while (true){
            fname=wpath+"post_"+MMO+"_"+Cstr(j1)+".html";
            dwAttr= ::GetFileAttributes(fname);
            if (dwAttr == 0xffffffff){break;}
            j1++;
          }

          outpost.Open(fname,CFile::modeCreate|CFile::modeWrite);
          f2=false;
        }
        wr="<img src="+b[1]+"></img><br>\r\n";
        wr=wr+b[2]+"\r\n"+b[3]+"\r\n"+b[4]+"\r\n<hr>\r\n";
        outpost.Write(wr,wr.GetLength());
        if (k%chang1==0){
          outpost.Close();
          f2=true;
        }
 

      }

      

     
   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();

   if (!f1){
     wr="<a href=http://pan.baidu.com/s/"+m_mo+" target=_blank><strong>资源下载</strong></a><br>\r\n";
     out1.Write(wr,wr.GetLength());
     out1.Close();
   }
 
   if (!f2){
     outpost.Close();
   }


}





//////////////////
int CMy115backDlg::getsinahao(CString *haos,CString url,int ubound,int nowsu,CStdioFile &out){



  CString be="blog.sina.com.cn/u",en="\"";
  
  
  CString wr,strHtml,strLine,hao,s;
  int i,pos,belen=19,n;
  bool you;

  
  strHtml =gethtml(url);
  pos=strHtml.Find(be);
  if (pos<0){return nowsu;}
  CString fanke="module_12";

    
  while (pos>=0){
    strHtml=strHtml.Mid(pos+belen);
    pos=strHtml.Find(en);
    hao=strHtml.Left(pos);    
    strHtml=strHtml.Mid(pos+10);
    you=false;
    for (i=0;i<nowsu;i++){
      if (haos[i]==hao){you=true;break;}
    }
    if (! you){
      wr="http://blog.sina.com.cn/u/"+hao;      

     s=gethtml(wr);

     n=s.Find(fanke);

     if (n>=0){

        haos[nowsu]=hao;
        visiturl(wr);
        wr=wr+"\r\n";
        out.Write(wr,wr.GetLength());
        nowsu++;
        if (nowsu>=ubound){
          return nowsu;
        }
      }
      
    }
    
    pos=strHtml.Find(be);
  }//while (pos>=0){
  return nowsu;
}


//////////////////
int CMy115backDlg::getyeahhao(CString *haos,CString url,int ubound,int nowsu,CStdioFile &out){


 
  CString be="/blog/static/",en="\"";
  
  
  CString wr,strHtml,strLine,hao;
  int i,pos,belen=19;
  bool you;

  
  strHtml =gethtml(url);
  CString fanke="target=visitor";

  pos=strHtml.Find(be);
  if (pos<0){return nowsu;}
    
  while (pos>=0){
    strHtml=strHtml.Mid(pos-60);
    pos=strHtml.Find("href=\"http://");
    strHtml=strHtml.Mid(pos+6);
    pos=strHtml.Find(be);
    hao=strHtml.Left(pos);    
    strHtml=strHtml.Mid(pos+10);
    you=false;
    for (i=0;i<nowsu;i++){
      if (haos[i]==hao){you=true;break;}
    }
    if (! you && hao.Find("<")<0  && hao.Find(">")<0 && gethtml(hao).Find(fanke)>=0){

      haos[nowsu]=hao;
      visiturl(hao);
      wr=hao+"\r\n";
      out.Write(wr,wr.GetLength());
      nowsu++;
      if (nowsu>=ubound){
        return nowsu;
      }
    }
    pos=strHtml.Find(be);
  }//while (pos>=0){
  return nowsu;
}


int CMy115backDlg::getyeahspecial(CString *special){


  CString url="http://blog.163.com"; 
  CString be="http://blog.163.com/special/",en="/";
  
  
  CString wr,strHtml,strLine,hao;
  int i,pos,belen=19;
  bool you;

  
  strHtml =gethtml(url);
  CString yuan=strHtml;
  CString tmp[3000];
  pos=strHtml.Find(be);
  if (pos<0){return 0;}
  i=0;
  int j;
  while (pos>=0){
    strHtml=strHtml.Mid(pos);
    pos=strHtml.Find(".html");
    hao=strHtml.Left(pos+5);
    if (i==0){tmp[i]=hao;i=1;}
    else {
      you=false;
      for (j=0;j<i;j++){
        if (tmp[j]==hao){you=true;break;}
      }
      if (! you){
        tmp[i]=hao;i++;
      }
    }
   
    strHtml=strHtml.Mid(pos+6);
    pos=strHtml.Find(be);
  }//while (pos>=0){

  if (i==0){return 0;}
  //special=new CString [i+1];
  special[0]="http://blog.163.com";
  if (i>100){i=100;}
  for (j=1;j<=i;j++){special[j]=tmp[j-1];}

  return i;
}

void CMy115backDlg::visiturl(CString url){
  clock_t start, finish; 
  long duration;              
  
  STARTUPINFO si = { sizeof(si) };   
  PROCESS_INFORMATION pi;   

  si.dwFlags = STARTF_USESHOWWINDOW;   
  si.wShowWindow = FALSE; //TRUE;//TRUE表示显示创建的进程的窗口  
  
  //TCHAR cmdline[] =TEXT(" http://community.csdn.net/"); //注意前面有空格，否则打开的是主页。 
  char cmdline[200];
  int l=url.GetLength();
  if (l==0){cmdline[0]='\0';}
  else {
    cmdline[0]=' ';
    for (int i=0;i<l;i++){
      cmdline[i+1]=url.GetAt(i);  
    }
    cmdline[l+1]='\0';
  }
  //TCHAR cmdline[] =TEXT(str); //注意前面有空格，否则打开的是主页。 
  BOOL bRet = ::CreateProcess (   
        TEXT("c://program files//internet explorer//iexplore.exe"),  
        cmdline, //在Unicode版本中此参数不能为常量字符串，因为此参数会被修改     
        NULL,   
        NULL,   
        FALSE,   
        CREATE_NEW_CONSOLE,   
        NULL,   
        NULL,   
        &si,   
        &pi);   

  if(bRet){
    ::CloseHandle (pi.hThread);   
    ::CloseHandle (pi.hProcess);   
  }
  
  start = clock(); 
  while (true){
    finish = clock();               
    duration = (long)(finish - start) / CLOCKS_PER_SEC; 
    
    if (duration>m_mas){break;}
  }

}


CString CMy115backDlg::gethtml(CString url){
  CInternetSession session;
  CHttpFile *file = NULL; 
  CString strHtml,strLine;
  strHtml = "";
  try{
    file = (CHttpFile*)session.OpenURL(url);
  }catch(CInternetException * m_pException){
    file = NULL;
    m_pException->m_dwError;
    m_pException->Delete();
    session.Close();
    return strHtml;
  }    
  if(file != NULL){while(file->ReadString(strLine) != NULL){strHtml += strLine;}}
  session.Close();
  return strHtml;
}












void CMy115backDlg::srnd(small sscrnd[])
{

  for (int i=0;i<5;i++){sscrnd[i]=i;}
/*
  small rdsn[5],h_n,m,i,k,h_i; 
  sscrnd[0]=0;
  while (sscrnd[0]==0 || sscrnd[1]==1 || sscrnd[2]==2 || sscrnd[3]==3 || sscrnd[4]==4){
    for (i=0;i<5;i++){rdsn[i]=i;}
    for (h_i=5;h_i>1;h_i--) {  
      h_n=myrnd()%h_i;  
      sscrnd[5-h_i]=rdsn[h_n];
      if (h_n<h_i-1){
        m=rdsn[h_n];
        for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
        rdsn[h_i-1]=m;
      }		  
    }  
    sscrnd[4]=rdsn[0];
  }
*/
}























void CMy115backDlg::ssc3allrefresh(CString dirpath,CString qihao[],CString datas[],int ubound) 
{
    CString strDir=dirpath,nake;
    CString szDir = strDir,buyfile; 
    
    CString bqi,s,s1,s2,s3,wr,t;

    CFileFind ff; 
    szDir += "*.*"; 
    int i,bl,n;
    bool res = ff.FindFile(szDir);   
    CStdioFile fin,out,outall;
    CString gostafile=dirpath+"gosta.txt",b[10],bb[3];
    out.Open(gostafile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate); 
    out.SeekToEnd(); 

    i=0;
    while( res ) 
    { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 

       if(!ff.IsDirectory() && !ff.IsDots()){

         if (buyfile.Right(6)!="go.txt"){continue;}    
         i++;
                  
       }
          
    } 
    ff.Close();
    if (i==0){return;}
    n=i;
    CString *filename=new CString [n];
///////////////////////////////////////////////////
    res = ff.FindFile(szDir);  
    i=0;
    while( res ) 
    { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 

       if(!ff.IsDirectory() && !ff.IsDots()){

         if (buyfile.Right(6)!="go.txt"){continue;}    
         filename[i]=buyfile;
         i++;                 
       }
          
    } 
    ff.Close();



///////////////////////////////////////////////
///////////////////////////////////////////////////
    int zuida=0;
    //int yimax[5];
    
    for (i=0;i<n;i++){
      sscgorefresh3(filename[i],qihao,datas,ubound,out,true,zuida); 
    }
    delete[] filename;   
    out.Close();

    sortafileatoz(gostafile);
    DWORD dwAttr= ::GetFileAttributes(gostafile);
    if (dwAttr == 0xffffffff){return;}

    
///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

    const SU=600;
    int zhongsu[SU],allsu[SU],chasu[SU],sum,jian;
    CString sufile;
    for (i=0;i<SU;i++){zhongsu[i]=0;allsu[i]=0;}
    fin.Open(gostafile, CFile::modeRead);
    do{
      fin.ReadString(s);s=delern(s);
      if (s.Left(5)!="after"){continue;}

      s=s.Mid(5);
      Split(s,b,bl,"\t");
      
      i=atoi(b[0]);

      if (i>=SU-1){i=SU-1;}   
      allsu[i]++;
      if (b[1]=="$"){zhongsu[i]++;}
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();

    sum=0;jian=0;
    for (i=0;i<SU;i++){sum+=allsu[i];}
    for (i=0;i<SU;i++){
      chasu[i]=sum-jian;
      jian+=allsu[i];
    }

    sufile=dirpath+"suafter.txt";
    out.Open(sufile,CFile::modeCreate|CFile::modeWrite);
    for (i=m_num;i<SU;i++){
      if (chasu[i]==0){break;}
      wr=padstrcisu(Cstr(i),4," ",0)+"  ";
      wr+=padstrcisu(Cstr(zhongsu[i]),6," ",0)+"  ";
      wr+=padstrcisu(Cstr(chasu[i]),6," ",0)+"  ";
      wr+=padstrcisu(Cstr(zhongsu[i]*1800/chasu[i]/2),6," ",0)+"\r\n";
      out.Write(wr,wr.GetLength());
    }
    out.Close();

}












///////////////////////////////////////////
void CMy115backDlg::OnButton16() 
{
   if (JieMian!=22){jiemian(22);return;}  
   setbutton(FALSE);
   UpdateData(TRUE);
   if (m_dfile.GetLength()==0){setbutton(TRUE);return;} 
   int ai,pos,i,ubound;
   CString s,t,dirpath,datafile;
   CStdioFile out;

   pos=m_dfile.ReverseFind('\\');
   dirpath=m_dfile.Left(pos+1);
   datafile=dirpath+"qxcdata.txt";

  //dis="类型:1 求预测单码 2 由单码求合成码 3 核对合成码 4 清理重复合成 5 由合成码求合成码 6 生成文件 \r\n";
   if (m_mo=="2"){
     getqxcbuycode(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }


   if (m_mo=="5"){
     getqxche(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }



   if (m_mo=="6"){
     getqxcbuyfile(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }


   if (m_mo=="4"){
     deletehe(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }


   if (m_mo=="1" || m_mo=="3"){////////////////////////////////
   DWORD dwAttr = ::GetFileAttributes(datafile); 
   if (dwAttr == 0xffffffff){MessageBox("没有数据文件");setbutton(TRUE);return;}

   out.Open(datafile, CFile::modeRead);
   
   if (m_mo=="1" && m_dfile.Find("qxcdata.txt")>=0){for (i=0;i<m_step;i++){out.ReadString(s);}}
   i=0;   
   do{
     out.ReadString(s);
     i=i+1;    
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
   ubound=i;

   CString *datas=new CString[ubound];
   CString *qihao=new CString[ubound];
   small  **data=new small *[ubound];
   for (i=0;i<ubound;i++){
     *(data+i)=new small[7];
   } 

   out.Open(datafile, CFile::modeRead);
   if (m_mo=="1" && m_dfile.Find("qxcdata.txt")>=0){for (i=0;i<m_step;i++){out.ReadString(s);}}
   i=0;   
   do{
     out.ReadString(s);s=delern(s);    
     s.Replace(" ","");     	 
     qihao[i]=s.Left(5);
     s=s.Mid(5,7); 
     datas[i]=s;	
     data[i][0]=atoi(s.Mid(0,1));
     data[i][1]=atoi(s.Mid(1,1));
     data[i][2]=atoi(s.Mid(2,1));
     data[i][3]=atoi(s.Mid(3,1));
     data[i][4]=atoi(s.Mid(4,1));
     data[i][5]=atoi(s.Mid(5,1));
     data[i][6]=atoi(s.Mid(6,1));
     i=i+1;
     
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
/////////////////////////////////////////////////////
 
   if (m_mo=="1"){   
     if (m_dfile.Find("qxcdata.txt")>=0){
       m_wb=m_wb+m_e;
       qxcfindtong(qihao,datas,data,dirpath,ubound); 
       m_wb=m_wb-m_e;     
     }
     else {
       qxcallrefresh(dirpath,qihao,datas,ubound);
     }
   }

  

///////////////////////////////////////
   if (m_mo=="3"){
//////////////////////////////////////////////////////////

     CString strDir=dirpath;
     CString szDir = strDir,buyfile,nake; 
     CFileFind ff; 
     szDir += "*.*"; 
     CStdioFile fin;   
     bool res = ff.FindFile(szDir);   
    
     while( res ) 
     { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 

       if(!ff.IsDirectory() && !ff.IsDots()){
         pos=buyfile.ReverseFind('\\'); 
         nake=buyfile.Mid(pos+1);          
         if (nake.Find("he")<0){continue;}      

         checkqxchccode(dirpath,qihao,datas,ubound,buyfile);
       }        
       
     }
     ff.Close(); 
     //MessageBox("程序结束！");setbutton(TRUE);	return;
   }



///////////////////////////////////////////////////////
   delete[] datas;delete[] qihao;
   for (ai=0;ai<ubound;ai++){delete[] data[ai];}
   delete[] data;  

   }//   if (m_mo=="1" || m_mo=="3"){////////////////////////////////


 
   MessageBox("程序结束！");setbutton(TRUE);	
}


















void CMy115backDlg::qxcallrefresh(CString dirpath,CString qihao[],CString datas[],int ubound) 
{
    CString strDir=dirpath,nake;
    CString szDir = strDir,buyfile; 
    
    CString bqi,s,s1,s2,s3,wr,t;

    CFileFind ff; 
    szDir += "*.*"; 
    int i,bl,n;
    bool res = ff.FindFile(szDir);   
    CStdioFile fin,out,outall;
    CString gostafile=dirpath+"gosta.txt",b[10],bb[3];
    out.Open(gostafile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate); 
    out.SeekToEnd(); 

    i=0;
    while( res ) 
    { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 

       if(!ff.IsDirectory() && !ff.IsDots()){

         if (buyfile.Right(6)!="go.txt"){continue;}    
         i++;
                  
       }
          
    } 
    ff.Close();
    if (i==0){return;}
    n=i;
    CString *filename=new CString [n];
///////////////////////////////////////////////////
    res = ff.FindFile(szDir);  
    i=0;
    while( res ) 
    { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 

       if(!ff.IsDirectory() && !ff.IsDots()){

         if (buyfile.Right(6)!="go.txt"){continue;}    
         filename[i]=buyfile;
         i++;                 
       }
          
    } 
    ff.Close();



///////////////////////////////////////////////
///////////////////////////////////////////////////
    int zuida=0;
    for (i=0;i<n;i++){
      qxcgorefresh3(filename[i],qihao,datas,ubound,out,true,zuida); 
    }
    delete[] filename;   
    out.Close();

    sortafileatoz(gostafile);
    DWORD dwAttr= ::GetFileAttributes(gostafile);
    if (dwAttr == 0xffffffff){return;}

    
///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

    const SU=600;
    int zhongsu[SU],allsu[SU],chasu[SU],sum,jian;
    CString sufile;

    for (i=0;i<SU;i++){zhongsu[i]=0;allsu[i]=0;}
    fin.Open(gostafile, CFile::modeRead);
    do{
      fin.ReadString(s);s=delern(s);
      if (s.Left(5)!="after"){continue;}

      s=s.Mid(5);
      Split(s,b,bl,"\t");
      
      i=atoi(b[0]);

      if (i>=SU-1){i=SU-1;}   
      allsu[i]++;
      if (b[1]=="$"){zhongsu[i]++;}
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();

    sum=0;jian=0;
    for (i=0;i<SU;i++){sum+=allsu[i];}
    for (i=0;i<SU;i++){
      chasu[i]=sum-jian;
      jian+=allsu[i];
    }

    sufile=dirpath+"suafter.txt";
    out.Open(sufile,CFile::modeCreate|CFile::modeWrite);
    for (i=m_num;i<SU;i++){
      if (chasu[i]==0){break;}
      wr=padstrcisu(Cstr(i),4," ",0)+"  ";
      wr+=padstrcisu(Cstr(zhongsu[i]),6," ",0)+"  ";
      wr+=padstrcisu(Cstr(chasu[i]),6," ",0)+"  ";
      wr+=padstrcisu(Cstr(zhongsu[i]*1800/chasu[i]/2),6," ",0)+"\r\n";
      out.Write(wr,wr.GetLength());
    }
    out.Close();

}






void CMy115backDlg::getqxcbuycode(CString dirpath) 
{

  int filenum=0,i,j,k,bl,pos;
  CString outfile,s,t,rd[7],b[4],wr;
  CString strDir=dirpath;
  CString szDir = strDir,buyfile,nake; 
  CFileFind ff; 
  szDir += "*.*"; 



  bool res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)!="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")>=0){continue;}
       filenum++;
     }
  }
  ff.Close(); 
  if (filenum<7){return;}
  CString * filename=new CString [filenum];

  res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)!="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")>=0){continue;}
       filename[i]=nake;
       i++;
     }
  }
  ff.Close(); 
  paixuztoa(filename,filenum);
  bool zuflag[7];
  for (i=0;i<7;i++){zuflag[i]=false;}
  CString zu[7];

  k=0;
  for (i=0;i<filenum;i++){
    buyfile=filename[i];
    pos=buyfile.ReverseFind('\\');
    nake=buyfile.Mid(pos+1);
    j=atoi(nake.Left(1))-1;
    if (!zuflag[j]){
      zu[j]=nake;zuflag[j]=true;
      k++;
      if (k>=7){break;}      
    }    
  }

  if (k<7){return;}
  int yisum=0;
  for (i=0;i<7;i++){
    yisum+=atoi(zu[i].Mid(2,3));
  }
  if (yisum<m_qmas){return;}

  CStdioFile fin[7],out;
  outfile=dirpath+"h0000he[";
  int fromsu=0;
  for (i=0;i<7;i++){
    fin[i].Open(dirpath+zu[i], CFile::modeRead);

    while (true){
      fin[i].ReadString(rd[i]);rd[i]=delern(rd[i]);
      if (rd[i].Find(":       :")>0){break;}  
    }
    s=zu[i];
    pos=s.Find("[");
    s=s.Mid(pos+1);
    pos=s.Find("]");
    s=s.Left(pos);
    fromsu+=atoi(s);
    s=rd[i].Left(5);    
  }
  outfile+=padstrcisu(Cstr(fromsu),8,"0",0)+"-"+Cstr(yisum);
  outfile+="]"+s+".txt";
  out.Open(outfile,CFile::modeCreate|CFile::modeWrite);  
  while (rd[0]!="0" && rd[1]!="0" && rd[2]!="0" && rd[3]!="0" && rd[4]!="0" && rd[5]!="0" && rd[6]!="0"){
    Split(rd[0],b,bl,":");
    wr=b[0]+":       :"+b[2];

    Split(rd[1],b,bl,":");
    wr+=b[2];
      
    Split(rd[2],b,bl,":");
    wr+=b[2];

    Split(rd[3],b,bl,":");
    wr+=b[2];

    Split(rd[4],b,bl,":");
    wr+=b[2];

    Split(rd[5],b,bl,":");
    wr+=b[2];

    Split(rd[6],b,bl,":");
    wr+=b[2]+"\r\n";
   
    out.Write(wr,wr.GetLength());
    ////////////////////////////////////////////////////
    for (j=0;j<7;j++){
      if (fin[j].GetPosition()!=fin[j].GetLength()){
        fin[j].ReadString(rd[j]);rd[j]=delern(rd[j]);
      }
      else {rd[j]="0";}
    }
//MessageBox(rd[0]+"\r\n"+rd[1]+"\r\n"+rd[2]+"\r\n"+rd[3]+"\r\n"+rd[4]+"\r\n"+rd[5]+"\r\n"+rd[6]);

    ///////////////////////////////////////////////////
  }  
    

  out.Close();
  for (j=0;j<7;j++){fin[j].Close();}
  delete[] filename;
}





void CMy115backDlg::OnButton37() 
{
   if (JieMian!=41){jiemian(41);return;}  
   setbutton(FALSE);
   UpdateData(TRUE);
   tuichu=0;
   if (m_dfile.GetLength()==0){setbutton(TRUE);return;} 
   int ai,bl,pos,i,ubound;
   CString s,t,dirpath,datafile,ba[8];
   CStdioFile out,fin;



   pos=m_dfile.ReverseFind('\\');
   dirpath=m_dfile.Left(pos+1);
   datafile=dirpath+"ssqdata.txt";
   






   if (m_mo=="3"){
     copybuyfile(dirpath,5); 
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }




   DWORD dwAttr = ::GetFileAttributes(datafile); 
   if (dwAttr == 0xffffffff){MessageBox("没有数据文件");setbutton(TRUE);return;}

   out.Open(datafile, CFile::modeRead);

   
   i=0;   
   do{
     out.ReadString(s);
     i=i+1;    
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
   ubound=i;


   CString *datas=new CString[ubound];
   CString *qihao=new CString[ubound];


   out.Open(datafile, CFile::modeRead);
   i=0;   
   do{
     out.ReadString(s);s=delern(s);    
     s=s.Left(26);	
     Split(s,ba,bl," ");
     datas[i]=ba[1]+","+ba[2]+","+ba[3]+","+ba[4]+","+ba[5]+","+ba[6]+","+ba[7];    	 
     qihao[i]=ba[0];   


     i=i+1;
     
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
/////////////////////////////////////////////////////
   if (m_mo=="1"){
     getssqbuyfile(dirpath,qihao[0],datas);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }


   if (m_mo=="2"){  
//MessageBox("1");
      const int ZUSU=20;
      int ZSU=getcansu(dirpath,2);

      CString tjsrc=dirpath+"tjsrc\\",srcfile;
      if(_access(tjsrc, 0) == -1){_mkdir(tjsrc);} 
      CString tjfile,oldstr,wr;
 
      tjfile=dirpath+"tongji.txt";
      oldstr="";
      dwAttr = ::GetFileAttributes(tjfile);
      if (dwAttr != 0xffffffff){
        fin.Open(tjfile,CFile::modeRead);
        fin.ReadString(s);fin.ReadString(s);
//MessageBox("2 s="+s+"\r\nqihao[0]="+qihao[0]);

        if (s.Left(5)<qihao[0]){
          s=delern(s);
          oldstr+=s+"\r\n";
        }
        else {
          delete[] datas;delete[] qihao;
          
          MessageBox("程序结束！");setbutton(TRUE);return;
        }
          
        while(fin.ReadString(s)){
          s=delern(s);
          oldstr+=s+"\r\n";
        }
        fin.Close();                  
      }
//MessageBox("3");
     
      //CString records[ZUSU][2];
      CString **records=new CString *[ZUSU];
      for (i=0;i<ZUSU;i++){
        records[i]=new CString [2];
      }

      for (i=0;i<ZUSU;i++){
        records[i][0]="0";
      }
   


      CString zerofile=dirpath+"zero.txt";
      CStdioFile outz;
      outz.Open(zerofile,CFile::modeCreate|CFile::modeWrite);    
       
      
      checkssqbuyfile(dirpath+"buy\\",qihao,datas,ubound,tjsrc);

      for (i=0;i<ZSU;i++){
        srcfile=tjsrc+padstrcisu(Cstr(i),5,"0",0)+".txt";
        ssqmegarecords(srcfile,records,outz);
      }
      outz.Close();
      CString head="   qi";
      for (i=0;i<ZUSU;i++){
         head+=";"+padstrcisu(Cstr(i+1),9," ",0);
      }


      out.Open(tjfile,CFile::modeCreate|CFile::modeWrite);  

      wr=head+"\r\n";

      out.Write(wr,wr.GetLength());

      wr=qihao[0];
      for (i=0;i<ZUSU;i++){
        if (records[i][0]!="0"){
          wr+=";"+padstrcisu(records[i][0]+"["+records[i][1]+"]",9," ",0);
        }
        else {wr+=";         ";}
      }

      wr=wr+"\r\n";
      out.Write(wr,wr.GetLength());

      wr=oldstr;

      out.Write(wr,wr.GetLength());
      out.Close();     
      for(i=0;i<ZUSU;i++){delete[] records[i];}
      delete[] records;
////////////////////////////////////////
      int re=sortafileatoz(zerofile);
      if (re==-1){
        delete[] datas;delete[] qihao;
        
        MessageBox("程序结束！");setbutton(TRUE);	return;
      }

      CString b[10];
      int bl;
      i=0;
      fin.Open(zerofile,CFile::modeRead);
      while(fin.ReadString(s)){
        i++;
      }
      fin.Close(); 


      if (i>0){


        ubound=i;
        i=0;
        CString *zu=new CString [ubound];
        CString *zuwr=new CString [ubound];
        fin.Open(zerofile,CFile::modeRead);
        while(fin.ReadString(s)){
          s=delern(s);
          zu[i]=s;i++;
        }
        fin.Close();  
        for (i=0;i<ubound;i++){
          Split(zu[i],b,bl,"\t");
          zuwr[i]=b[1]+"#"+zu[i];
        } 
      
        paixuatoz(zuwr,ubound);

        out.Open(dirpath+"zerozu.txt",CFile::modeCreate|CFile::modeWrite);

        for (i=0;i<ubound;i++){
          wr=zuwr[i];
          pos=wr.Find("#");
          wr=wr.Mid(pos+1)+"\r\n";      
    
          out.Write(wr,wr.GetLength());
        }
        out.Close();
 
        for (i=0;i<ubound;i++){
          Split(zu[i],b,bl,"\t");
          zuwr[i]=b[2]+"#"+zu[i];
        }       
        paixuztoa(zuwr,ubound);
        out.Open(dirpath+"zeronum.txt",CFile::modeCreate|CFile::modeWrite);

        for (i=0;i<ubound;i++){
          wr=zuwr[i];
          pos=wr.Find("#");
          wr=wr.Mid(pos+1)+"\r\n";          
          out.Write(wr,wr.GetLength());
        }
        out.Close();
        delete[] zu;delete[] zuwr;


      }
////////////////////////////////////////

      
   }


/////////////////////////////////////////////////////



///////////////////////////////////////////////////////
   delete[] datas;delete[] qihao;
   


  
   MessageBox("程序结束！");setbutton(TRUE);	
 
}












void CMy115backDlg::checkqxchccode(CString dirpath,CString qihao[],CString datas[],int ubound,CString buyfile) 
{

  CStdioFile fin,out;
  int i,j,pos,bl,bqinum,qinum,m;
  CString c,s,t,wr,b[11],bqi,nowqi,gofile,zhong;
  int yis[11];
  for (i=0;i<11;i++){yis[i]=0;}  
  
//////////////////////////////////////////////
  pos=buyfile.ReverseFind('\\');
  CString nake=buyfile.Mid(pos+1);

  CString mingstr="he",headstr="h";
  if (nake.Find("ahe")>0){mingstr="ahe";}

  CString myqi=nake;
  pos=nake.ReverseFind(']');  
  myqi=myqi.Mid(pos+1);
  myqi=myqi.Left(5);


  if (myqi>qihao[0]){return;}

////////////////////////////////////////
  int yi;
  CString real;
  
  pos=nake.Find("[");
  real=nake.Mid(pos);
  pos=real.Find("]");
  real=real.Left(pos+1);
  pos=nake.Find("(");
  if (pos>=0){
    s=nake.Mid(pos+1);
    pos=s.Find(")");
    s=s.Left(pos);
    Split(s,b,bl,",");
    for (i=0;i<11;i++){yis[i]=atoi(b[i]);} 
  }
  qinum=yis[10];
///////////////////////////////////////////////




  CString tmpfile=dirpath+"tmp.txt";
  out.Open(tmpfile,CFile::modeCreate|CFile::modeWrite);



  fin.Open(buyfile, CFile::modeRead);
  fin.ReadString(s);s=delern(s);
  while (s.Left(1)=="/" || s.Find("[")>=0){
    fin.ReadString(s);s=delern(s);
  }

  CString yuan=s;
  pos=s.Find(':');
  bqi=s.Left(pos);

  fin.Close();


  if (bqi>qihao[0]){return;}
  bool deng=false;
  for (i=0;i<ubound;i++){
    if (qihao[i]==bqi){deng=true;break;}
    if (qihao[i]<bqi){break;}
  }
  if (! deng){MessageBox(buyfile+"\r\n"+bqi+" is not in qxcdata.txt!");return;}
  bqinum=i;

  nowqi=qihao[bqinum];


  fin.Open(buyfile, CFile::modeRead);

  

  
  int blk=0;
  int znum;
  i=0;
  do{
    fin.ReadString(s);s=delern(s);

    if (s.GetLength()<20){continue;}
    if (s.Find("/")>=0){continue;}
    if (s.Find("[")>=0){continue;}
    m=bqinum-i;
    if (m<0){   
      blk++;
      nowqi=qijia1(nowqi);
      wr=nowqi+":       :";
      Split(s,b,bl,":");
      wr=wr+b[2];
      wr=wr+"\r\n";
      out.Write(wr,wr.GetLength());
      i++;
      continue;
    }

    qinum++;yis[10]++;
    nowqi=qihao[m];
    wr=nowqi+":"+datas[m]+":";


    pos=s.ReverseFind(':');
    s=s.Mid(pos+1);
    
    zhong="";
    wr=wr+s+":";



    znum=0;
    
    for (j=0;j<7;j++){
      if (datas[m].Mid(j,1)==s.Mid(j,1)){        
        zhong=zhong+Cstr(j+1);        
        yis[j]=0;znum++;
      }
      else {
        zhong+="*";  
        yis[j]++;
      }
      
    }

    
    

    
    wr+=zhong+"["+padstrcisu(Cstr(qinum),4," ",0)+"]";
//MessageBox("wr="+wr);
    if (zhong=="1234567"){wr+="!!!!!!!!!!!!!!!!!!!!!!!";}
    wr+="\r\n";
  
//MessageBox("wr="+wr);
    out.Write(wr,wr.GetLength());
    i++;   
    if (znum==7){yis[7]++;}
    if (znum>=6){yis[8]++;}
    if (znum>=5){yis[9]++;}

  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();out.Close();


  DeleteFile(buyfile);
  CString ystr="(";yi=0;
  for (i=0;i<11;i++){
    if (i<7){yi+=yis[i];}
    ystr+=Cstr(yis[i])+",";
  }
  ystr=ystr.Left(ystr.GetLength()-1)+")";
  gofile=dirpath+headstr+padstrcisu(Cstr(yi),4,"0",0)+mingstr+ystr+real+qihao[0]+".txt";

  if (blk>=1){CopyFile(tmpfile,gofile,0);}
  DeleteFile(tmpfile);

  


}





















void CMy115backDlg::checksschccode(CString dirpath,CString qihao[],CString datas[],int ubound,CString buyfile,int yimax[]) 
{

  CStdioFile fin,out;
  int i,j,pos,bl,bqinum,qinum,m;
  CString c,s,t,wr,b[14],bqi,nowqi,gofile,zhong,his;
  int yis[14];
  for (i=0;i<14;i++){yis[i]=0;}  
  
//////////////////////////////////////////////
  pos=buyfile.ReverseFind('\\');
  CString nake=buyfile.Mid(pos+1);

  CString mingstr="he",headstr="h";
  if (nake.Find("ahe")>0){mingstr="ahe";}

  CString myqi=nake;
  pos=nake.ReverseFind(']');  
  myqi=myqi.Mid(pos+1);
  myqi=myqi.Left(9);


  if (myqi>qihao[0]){return;}

////////////////////////////////////////
  int yi;
  CString real;
  
  pos=nake.Find("[");
  real=nake.Mid(pos);
  pos=real.Find("]");
  real=real.Left(pos+1);
  pos=nake.Find("(");
  if (pos>=0){
    s=nake.Mid(pos+1);
    pos=s.Find(")");
    s=s.Left(pos);
    Split(s,b,bl,",");
    for (i=0;i<14;i++){yis[i]=atoi(b[i]);} 
  }
  qinum=yis[13];
///////////////////////////////////////////////
  int yisu[5];
  bool weiflag[5];
  for (i=0;i<5;i++){
    yisu[i]=0;
    weiflag[i]=false;
  }
  if (dirpath.Find("\\1\\")>=0){weiflag[0]=true;}
  else  if (dirpath.Find("\\2\\")>=0){weiflag[1]=true;}
  else  if (dirpath.Find("\\3\\")>=0){weiflag[2]=true;}
  else  if (dirpath.Find("\\4\\")>=0){weiflag[3]=true;}
  else  {weiflag[4]=true;}
  pos=nake.Find(")(");
  if (pos>0){
    s=nake.Mid(pos+2);
    pos=s.Find(")");
    s=s.Left(pos);
    Split(s,b,bl,",");
    for (i=0;i<5;i++){
      if (weiflag[i]){
        yisu[i]=atoi(b[0]);
        yimax[i]=atoi(b[1]);
        break;
      }
    }

  }

///////////////////////////////////////////////




  CString tmpfile=dirpath+"tmp.txt";
  out.Open(tmpfile,CFile::modeCreate|CFile::modeWrite);



  fin.Open(buyfile, CFile::modeRead);
  fin.ReadString(s);s=delern(s);
  while (s.Left(1)=="/" || s.Find("[")>=0){
    fin.ReadString(s);s=delern(s);
  }

  CString yuan=s;
  pos=s.Find(':');
  bqi=s.Left(pos);

  fin.Close();


  if (bqi>qihao[0]){return;}
  bool deng=false;
  for (i=0;i<ubound;i++){
    if (qihao[i]==bqi){deng=true;break;}
    if (qihao[i]<bqi){break;}
  }
  if (! deng){MessageBox(buyfile+"\r\n"+bqi+" is not in 29new.txt!");return;}
  bqinum=i;

  nowqi=qihao[bqinum];


  fin.Open(buyfile, CFile::modeRead);

  

  
  int blk=0;
  int znum;
  i=0;
  do{
    fin.ReadString(s);s=delern(s);

    if (s.GetLength()<20){continue;}
    if (s.Find("/")>=0){continue;}
    if (s.Find("[")>=0){continue;}
    m=bqinum-i;
    if (m<0){   
      blk++;
      nowqi=qijia1(nowqi);
      wr=nowqi+":     :";
      Split(s,b,bl,":");
      wr=wr+b[2];
      wr=wr+"\r\n";
      out.Write(wr,wr.GetLength());
      i++;
      continue;
    }

    qinum++;yis[13]++;
    nowqi=qihao[m];
    wr=nowqi+":"+datas[m]+":";


    pos=s.ReverseFind(':');
    s=s.Mid(pos+1);
    
    zhong="";
    wr=wr+s+":";



    znum=0;
    for (j=0;j<5;j++){
      if (datas[m].Mid(j,1)==s.Mid(j,1)){        
        zhong=zhong+Cstr(j+1);        
        yis[j]=0;znum++;
      }
      else {
        zhong+="*";  
        yis[j]++;
      }
      
    }

    
    

    
    wr+=zhong+"["+padstrcisu(Cstr(qinum),4," ",0)+"]";

    if (zhong=="12345"){wr+="!!!!!!!!!!!!!!!!!!!!!!!";}
    wr+="\r\n";
  
   
    out.Write(wr,wr.GetLength());
    i++;   
    
    if (zhong=="12345"){yis[5]++;}
    if (zhong.Right(4)=="2345"){yis[6]++;}
    if (zhong.Right(3)=="345"){yis[7]++;}
    if (zhong.Left(3)=="123"){yis[8]++;}
    if (znum>=3){yis[9]++;}
    if (zhong.Right(2)=="45"){yis[10]++;}
    if (zhong.Left(2)=="12"){yis[11]++;}
    yis[12]+=znum;
    ////////////////////////////////////////////////

   
    for (j=0;j<5;j++){
      if (yisu[0]<yis[j]){yisu[0]=yis[j];}
    }

    if (yisu[1]<yis[0]+yis[1]){yisu[1]=yis[0]+yis[1];}
    if (yisu[1]<yis[3]+yis[4]){yisu[1]=yis[3]+yis[4];}

    if (yisu[2]<yis[0]+yis[1]+yis[2]){yisu[2]=yis[0]+yis[1]+yis[2];}
    if (yisu[2]<yis[2]+yis[3]+yis[4]){yisu[2]=yis[2]+yis[3]+yis[4];}

    if (yisu[3]<yis[1]+yis[2]+yis[3]+yis[4]){yisu[3]=yis[1]+yis[2]+yis[3]+yis[4];}

    if (yisu[4]<yis[0]+yis[1]+yis[2]+yis[3]+yis[4]){yisu[4]=yis[0]+yis[1]+yis[2]+yis[3]+yis[4];}

    
    for (j=0;j<5;j++){
      if (yimax[j]<yisu[j]){yimax[j]=yisu[j];}
    }

    ///////////////////////////////////////////////////

  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();out.Close();


  DeleteFile(buyfile);
  CString ystr="(";yi=0;
  for (i=0;i<14;i++){
    if (i<5){yi+=yis[i];}
    ystr+=Cstr(yis[i])+",";
  }
  ystr=ystr.Left(ystr.GetLength()-1)+")";
  CString nfile;

  if (weiflag[4]){

    his="("+Cstr(yisu[4])+","+Cstr(yimax[4])+")";
    //gofile=dirpath+"h"+padstrcisu(Cstr(yi),4,"0",0)+mingstr+ystr+his+real+qihao[0]+".txt";
    gofile=dirpath+headstr+padstrcisu(Cstr(yi),4,"0",0)+mingstr+ystr+real+qihao[0]+".txt";
 
  
    if (blk>=120){CopyFile(tmpfile,gofile,0);}
    DeleteFile(tmpfile);
    if (blk<120){return;}
  /////////////////////////////////////////
    CString d1path=dirpath+"1\\";
    if(_access(d1path, 0) == -1){_mkdir(d1path);} 
    CString d2path=dirpath+"2\\";
    if(_access(d2path, 0) == -1){_mkdir(d2path);} 
    CString d3path=dirpath+"3\\";
    if(_access(d3path, 0) == -1){_mkdir(d3path);} 
    CString d4path=dirpath+"4\\";
    if(_access(d4path, 0) == -1){_mkdir(d4path);} 
    
    for (i=0;i<5;i++){
      his="("+Cstr(yisu[0])+","+Cstr(yimax[0])+")";
      nfile=d1path+padstrcisu(Cstr(yis[i]),4,"0",0)+mingstr+"a"+Cstr(i+1)+ystr+his+real+qihao[0]+".txt";
      CopyFile(gofile,nfile,0);
    }

    his="("+Cstr(yisu[1])+","+Cstr(yimax[1])+")";
    nfile=d2path+padstrcisu(Cstr(yis[0]+yis[1]),4,"0",0)+mingstr+"L2"+ystr+his+real+qihao[0]+".txt";
    CopyFile(gofile,nfile,0);
    nfile=d2path+padstrcisu(Cstr(yis[3]+yis[4]),4,"0",0)+mingstr+"R2"+ystr+his+real+qihao[0]+".txt";

    his="("+Cstr(yisu[2])+","+Cstr(yimax[2])+")";
    CopyFile(gofile,nfile,0);
    nfile=d3path+padstrcisu(Cstr(yis[0]+yis[1]+yis[2]),4,"0",0)+mingstr+"L3"+ystr+his+real+qihao[0]+".txt";
    CopyFile(gofile,nfile,0);
    nfile=d3path+padstrcisu(Cstr(yis[2]+yis[3]+yis[4]),4,"0",0)+mingstr+"R3"+ystr+his+real+qihao[0]+".txt";
    CopyFile(gofile,nfile,0);

    his="("+Cstr(yisu[3])+","+Cstr(yimax[3])+")";
    nfile=d4path+padstrcisu(Cstr(yis[1]+yis[2]+yis[3]+yis[4]),4,"0",0)+mingstr+"R4"+ystr+his+real+qihao[0]+".txt";
    CopyFile(gofile,nfile,0);
  }
  /////////////////////////////////////////


  if (weiflag[0]){
    his="("+Cstr(yisu[0])+","+Cstr(yimax[0])+")";
    int wei=0;
    pos=nake.Find("a");
    wei=atoi(nake.Mid(pos+1,1))-1;
    if (wei<0){wei=0;}
    nfile=dirpath+padstrcisu(Cstr(yis[wei]),4,"0",0)+mingstr+"a"+Cstr(wei+1)+ystr+his+real+qihao[0]+".txt";  


    if (blk>=120){CopyFile(tmpfile,nfile,0);}
    DeleteFile(tmpfile);
  }

  if (weiflag[1]){    
    his="("+Cstr(yisu[1])+","+Cstr(yimax[1])+")";
    pos=nake.Find("L2");
    if (pos>0){
      nfile=dirpath+padstrcisu(Cstr(yis[0]+yis[1]),4,"0",0)+mingstr+"L2"+ystr+his+real+qihao[0]+".txt";
    }
    else {
      nfile=dirpath+padstrcisu(Cstr(yis[3]+yis[4]),4,"0",0)+mingstr+"R2"+ystr+his+real+qihao[0]+".txt";
    } 
    if (blk>=120){CopyFile(tmpfile,nfile,0);}
    DeleteFile(tmpfile);
  }


  if (weiflag[2]){    
    his="("+Cstr(yisu[2])+","+Cstr(yimax[2])+")";
    pos=nake.Find("L3");
    if (pos>0){
      nfile=dirpath+padstrcisu(Cstr(yis[0]+yis[1]+yis[2]),4,"0",0)+mingstr+"L3"+ystr+his+real+qihao[0]+".txt";
    }
    else {
      nfile=dirpath+padstrcisu(Cstr(yis[2]+yis[3]+yis[4]),4,"0",0)+mingstr+"R3"+ystr+his+real+qihao[0]+".txt";
    } 
    if (blk>=120){CopyFile(tmpfile,nfile,0);}
    DeleteFile(tmpfile);
  }


  if (weiflag[3]){    
    his="("+Cstr(yisu[3])+","+Cstr(yimax[3])+")";
    nfile=dirpath+padstrcisu(Cstr(yis[1]+yis[2]+yis[3]+yis[4]),4,"0",0)+mingstr+"R4"+ystr+his+real+qihao[0]+".txt";
    if (blk>=120){CopyFile(tmpfile,nfile,0);}
    DeleteFile(tmpfile);
  }

}





void CMy115backDlg::getssche(CString dirpath) 
{

  int filenum=0,i,j,k,bl,pos;
  CString outfile,s,t,b[14],wr;
  CString strDir=dirpath;
  CString szDir = strDir,buyfile,nake; 
  CFileFind ff; 
  szDir += "*.*"; 
  CStdioFile fin,out;


  bool res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)=="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")<0){continue;}
       if (nake.Find("(")<0){continue;}
       if (nake.Left(1)!="h"){if (atoi(nake.Left(4))==0){continue;}}
       else {if (atoi(nake.Mid(1,4))==0){continue;}}
       filenum++;
     }
  }
  ff.Close(); 

  if (filenum==0){return;}
  CString * filename=new CString [filenum];  
/////////////////////////////////////

////////////////////////////////////////////
  res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)=="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")<0){continue;}
       if (nake.Find("(")<0){continue;}
       if (nake.Left(1)!="h"){if (atoi(nake.Left(4))==0){continue;}}
       else {if (atoi(nake.Mid(1,4))==0){continue;}}
       filename[i]=nake;
       i++;
     }
  }
  ff.Close(); 
//////////////////////////////////////////  

  CString *qi=new CString [m_wb+1];
  i=0;
  fin.Open(dirpath+filename[0], CFile::modeRead);
  do{
    fin.ReadString(s);s=delern(s); 
    if (s.Find(":     :")<0){continue;}
    qi[i]=s.Left(9);
    i++;
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();
//////////////////////////////////////////
  int ***ma=new int **[5];
  for (i=0;i<5;i++){
    ma[i]=new int *[filenum];
    for (j=0;j<filenum;j++){
      ma[i][j]=new int [m_wb+1];
      for (k=0;k<=m_wb;k++){ma[i][j][k]=-1;}
    }
  } 
///////////////////////////////////////////


  for (i=0;i<filenum;i++){    
    nake=filename[i];

    pos=nake.Find("(");
    s=nake.Mid(pos+1);

    pos=s.Find(")");
    s=s.Left(pos);
    Split(s,b,bl,",");

    for (j=0;j<5;j++){ma[j][i][0]=atoi(b[j]);}
    fin.Open(dirpath+filename[i], CFile::modeRead);

    k=1;

    do{

      fin.ReadString(s);s=delern(s); 

      if (s.Find(":     :")<0){continue;}

      pos=s.ReverseFind(':');
      s=s.Mid(pos+1);

      for (j=0;j<5;j++){

        ma[j][i][k]=atoi(s.Mid(j,1));

      }
      k++;

    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();

  }
  

  int bound=m_wb+1;
  for (i=0;i<5;i++){
  for (j=0;j<filenum;j++){
  for (k=0;k<=m_wb;k++){
    if (ma[i][j][k]==-1){k=bound;}
  }}}
  if (bound<=1){return;}
  
  for (i=0;i<5;i++){
    paimasubiao(ma[i],0,filenum-1,0,bound);
  }

  int yisum=ma[0][0][0]+ma[1][0][0]+ma[2][0][0]+ma[3][0][0]+ma[4][0][0];
  CString ming="h"+padstrcisu(Cstr(yisum),4,"0",0)+"ahe(";
  for (i=0;i<5;i++){
    ming+=Cstr(ma[i][0][0])+",";
  }
  ming=ming.Left(ming.GetLength()-1)+")[$]"+qi[0]+".txt";
  s=padstrcisu(Cstr(rand()%100000),5,"0",0)+"-"+Cstr(yisum);

  CString name=ming;
  name.Replace("$",s);
  outfile=dirpath+name;
  DWORD dwAttr;
  while (true){
    dwAttr  = ::GetFileAttributes(outfile); 
    if (dwAttr == 0xffffffff){break;}
    name=ming;
    s=padstrcisu(Cstr(rand()%100000),5,"0",0)+"-"+Cstr(yisum);
    name.Replace("$",s);
    outfile=dirpath+name;
  }
    
  out.Open(outfile,CFile::modeCreate|CFile::modeWrite);  
  
  for (i=1;i<bound;i++){
    if (qi[i-1].GetLength()==0){break;}
    if (ma[0][0][i]==-1){break;}
    if (ma[1][0][i]==-1){break;}
    if (ma[2][0][i]==-1){break;}
    if (ma[3][0][i]==-1){break;}
    if (ma[4][0][i]==-1){break;}
    wr=qi[i-1]+":     :";
    for (j=0;j<5;j++){      
      wr+=Cstr(ma[j][0][i]);
    }
    wr+="\r\n";
    out.Write(wr,wr.GetLength());
  }
  out.Close();
  for (i=0;i<5;i++){
    for (j=0;j<filenum;j++){
      delete[] ma[i][j];
    }
    delete[] ma[i];
  }
  delete[] ma;
  delete[] qi;

  delete[] filename;
}










void CMy115backDlg::getqxcbuyfile(CString dirpath) 
{


  int filenum=0,i,j,k,pos;
  int buynum=m_we;
  if (m_bfile.GetLength()>=13){buynum++;}
  CString *buyzu=new CString [buynum];
  CString outfile,s,t;
  CString strDir=dirpath;
  CString szDir = strDir,buyfile,nake; 
  CFileFind ff; 
  szDir += "*.*"; 
  CStdioFile fin,out;


  bool res = ff.FindFile(szDir);  
  bool you; 
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)=="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")<0){continue;}    
       if (nake.Find("head")>=0){continue;}   
       filenum++;
     }
  }
  ff.Close(); 

  if (filenum==0){return;}
  CString * filename=new CString [filenum];  
/////////////////////////////////////

////////////////////////////////////////////
  res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)=="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")<0){continue;}       
       if (nake.Find("head")>=0){continue;}   
       filename[i]=nake;
       i++;
     }
  }
  ff.Close(); 
//////////////////////////////////////////  
  paixuztoa(filename,filenum);


  CString qi; 
  fin.Open(dirpath+filename[0], CFile::modeRead);
  do{
    fin.ReadString(s);s=delern(s); 
    if (s.Find(":       :")<0){continue;}
    qi=s.Left(5);
    break;
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();

//////////////////////////////////////////
  outfile=dirpath+"buy"+qi+".txt";
  out.Open(outfile,CFile::modeCreate|CFile::modeWrite);

////////////////////////////////////////////
  k=0;
  if (m_bfile.GetLength()>=13){
    buyzu[0]=m_bfile;
    s=m_bfile;
    out.Write(s+"\r\n",s.GetLength()+2); 
    k=1;
  }
  for (i=0;i<filenum;i++){
    fin.Open(dirpath+filename[i], CFile::modeRead);
    do{
      fin.ReadString(s);s=delern(s); 
      if (s.Find(":       :")<0){continue;}
      pos=s.ReverseFind(':');
      s=s.Mid(pos+1);      
      break;
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
    you=false;
    if (k>0){      
      for (j=0;j<k;j++){
        if (s==buyzu[j]){you=true;break;}           
      }
    } 
    if (! you){
      buyzu[k]=s;  
      t="";
      for (j=0;j<7;j++){
        t=t+s.Mid(j,1)+",";
      }
      t=t.Left(13);
      out.Write(t+"\r\n",t.GetLength()+2);  
      k++;
      if (k>=buynum){break;}
    }
  }
  out.Close();
  delete[] filename;
  delete[] buyzu;
}




void CMy115backDlg::getcjsscdata(int pages,CString jigo,CString urlmode){
  CInternetSession session;
  CHttpFile *file = NULL;
  CStdioFile out;  
  
  
  CString wr,ma,qi,strUrl,strHtml,strLine;
  int i,j,pos,k;

  CString qibe="<td class=\"qihao\">",qiend="期</td>";
  int qibe_len=qibe.GetLength();
  CString haobe="<input type=\"button\" value=\"";
  int haobe_len=haobe.GetLength();
  out.Open(jigo,CFile::modeCreate|CFile::modeWrite);  
  k=1;

  for (i=m_btui;i<=m_btui+pages-1;i++){

    if (tuichu>0){return;}
    DoEvents();GetDlgItem(idc_jingdu)->SetWindowText("处理页数="+Cstr(i-m_btui+1));
    strUrl=urlmode+Cstr(i);
    //MessageBox(strUrl);
    strHtml = "";
    try{
      file = (CHttpFile*)session.OpenURL(strUrl);
    }catch(CInternetException * m_pException){
      file = NULL;
      m_pException->m_dwError;
      m_pException->Delete();
      session.Close();
      MessageBox("CInternetException");
    }    
    if(file != NULL){while(file->ReadString(strLine) != NULL){strHtml += strLine;}}

    //out.Write(strHtml,strHtml.GetLength());
//MessageBox("程序结束！");setbutton(TRUE);return;
    pos=strHtml.Find("号码<");
    if (pos<0){continue;}
    strHtml=strHtml.Mid(pos+1);

    pos=strHtml.Find("</table>");
    if (pos<0){continue;}
    strHtml=strHtml.Left(pos);


    pos=strHtml.Find("<tr");
    while (pos>=0){
      strHtml=strHtml.Mid(pos+4);
      pos=strHtml.Find(qibe);
      strHtml=strHtml.Mid(pos+qibe_len);
     // MessageBox(strHtml);

      pos=strHtml.Find(qiend);
      qi=strHtml.Left(pos);
      qi=qi.Mid(2);

      strHtml=strHtml.Mid(pos+10);


      pos=strHtml.Find("</td>");  
      strHtml=strHtml.Mid(pos+5);

      ma="";
      for (j=0;j<5;j++){

        pos=strHtml.Find(haobe);
        strHtml=strHtml.Mid(pos+haobe_len);

        ma=ma+strHtml.Left(1)+",";
        strHtml=strHtml.Mid(10);
      }
      ma=ma.Left(ma.GetLength()-1);
     
//MessageBox("ma="+ma);

      strHtml=strHtml.Mid(pos+5);
      pos=strHtml.Find("<tr");

     
      wr=Cstr(k)+"\t"+qi+"\t"+ma+"\r\n";
//MessageBox(wr);
      out.Write(wr,wr.GetLength());  
      k++;    
    }//while (pos>=0){

  }//for (i=1;i<=pages;i++){

}


int CMy115backDlg::myrand() 
{
  srand( (unsigned)time( NULL ) );
  int susu[10];
  susu[0]=2;
  susu[1]=3;
  susu[2]=5;
  susu[3]=7;
  susu[4]=11;
  susu[5]=13;
  susu[6]=17;
  susu[7]=19;
  susu[8]=23;
  susu[9]=29; 
  int n=(rand()*susu[(int) (10.0 * (rand() / (RAND_MAX + 1.0)))])%RAND_MAX;
  MessageBox(Cstr(n));
  return n ;
}


CString CMy115backDlg::qijia1(CString qistr) 
{
  //MessageBox("jin "+qistr);
  int year,month,day,qi,chang,lei;
  chang=qistr.GetLength();
  year=atoi(qistr.Left(2));
  if (chang>=8){    
    month=atoi(qistr.Mid(2,2));
    day=atoi(qistr.Mid(4,2));
    qi=atoi(qistr.Mid(6));
    if (qistr.Mid(6).GetLength()==2){lei=1;}
    else {lei=2;}
  }
  else {
    qi=atoi(qistr.Mid(2));
    lei=3;
  } 
  qi++;
  int jia=0,ye;
  switch(lei){
    case 1:
      if (qi>78){qi=1;jia=1;}
      break;
    case 2:
      if (qi>120){qi=1;jia=1;}
      break;
  }
  day=day+jia;
  jia=0;
  switch (month){
    case 1:
      if (day>31){jia=1;day=1;}
      break;
    case 2:
      ye=2000+year;
      if (ye%4==0){
        if (day>29){jia=1;day=1;}
      }
      else {
        if (day>28){jia=1;day=1;}
      }
      break;
    case 3:
      if (day>31){jia=1;day=1;}
      break;
    case 4:
      if (day>30){jia=1;day=1;}
      break;
    case 5:
      if (day>31){jia=1;day=1;}
      break;
    case 6:
      if (day>30){jia=1;day=1;}
      break;
    case 7:
      if (day>31){jia=1;day=1;}
      break;
    case 8:
      if (day>31){jia=1;day=1;}
      break;
    case 9:
      if (day>30){jia=1;day=1;}
      break;
    case 10:
      if (day>31){jia=1;day=1;}
      break;
    case 11:
      if (day>30){jia=1;day=1;}
      break;
    case 12:
      if (day>31){jia=1;day=1;}
      break;
  }
  month=month+jia;
  if (month>12 && lei<3){month=1;year++;}
  if (lei<3){qistr=padstrcisu(Cstr(year),2,"0",0)+padstrcisu(Cstr(month),2,"0",0)+padstrcisu(Cstr(day),2,"0",0);}
  else {
    qistr=padstrcisu(Cstr(year),2,"0",0);
  } 
  if (lei==1){qistr=qistr+padstrcisu(Cstr(qi),2,"0",0);}
  if (lei==2 || lei==3){qistr=qistr+padstrcisu(Cstr(qi),3,"0",0);}  
  //MessageBox("lei="+Cstr(lei)+"\r\nchu "+qistr);
  return qistr;
}


///////////////////////////////////////

//////////////////
void CMy115backDlg::getklcdata(CString jigo,CString url){
  CInternetSession session;
  CHttpFile *file = NULL; 


  CStdioFile out;  
  CString be1="<td align=\"center\">";
  CString be2="<td align=\"center\" class=\"boldred\">";
  CString en="</td>";
  int be1_l=be1.GetLength(),be2_l=be2.GetLength(),en_l=5;

  CString wr,ma,qi,strHtml,strLine,s,b[5];
  int i,pos,k,bl;


  out.Open(jigo,CFile::modeCreate|CFile::modeWrite);  
  k=1;

  
  strHtml = "";
  try{
    file = (CHttpFile*)session.OpenURL(url);
  }catch(CInternetException * m_pException){
    file = NULL;
    m_pException->m_dwError;
    m_pException->Delete();
    session.Close();
    MessageBox("CInternetException");
  }    
  if(file != NULL){while(file->ReadString(strLine) != NULL){strHtml += strLine;}}
//MessageBox(strHtml);
    //out.Write(strHtml,strHtml.GetLength());
//MessageBox("程序结束！");setbutton(TRUE);return;
    pos=strHtml.Find(be1);
    if (pos<0){return;}
    


    while (pos>=0){
      strHtml=strHtml.Mid(pos+be1_l);
      pos=strHtml.Find(en);
      qi=strHtml.Left(pos);
      strHtml=strHtml.Mid(pos+en_l);
     // MessageBox(strHtml);

      pos=strHtml.Find(be2);
      strHtml=strHtml.Mid(pos+be2_l);   
//MessageBox(strHtml);   
      pos=strHtml.Find(en);
      ma=strHtml.Left(pos);
//MessageBox(ma);   

      ma.Replace(" ","");
      ma.Replace("\r","");
      ma.Replace("\n","");
      ma.Replace("\t",",");
//MessageBox(ma);
      ma.Replace(",,,,,,,",",");
      ma.Replace(",,,,,,",",");
//MessageBox(ma);
      ma=ma.Mid(1);
      ma=ma.Left(ma.GetLength()-1);
//MessageBox(ma);
      Split(ma,b,bl,",");

      ma="";
      for (i=0;i<5;i++){
        s=b[i];
        s=padstrcisu(s,2,"0",0);
        ma=ma+s+",";
      }
      ma=ma.Left(ma.GetLength()-1);
//MessageBox(ma);
      strHtml=strHtml.Mid(pos+en_l);
//MessageBox(strHtml);

      pos=strHtml.Find(be1);
      if (pos<0){return;}
      strHtml=strHtml.Mid(pos+be1_l);
      pos=strHtml.Find(be1);

      qi=qi.Mid(2);
      wr=Cstr(k)+"\t"+qi+"\t"+ma+"\r\n";
      out.Write(wr,wr.GetLength());  
      k++;    
    }//while (pos>=0){

}



///////////////////////////////////////////
bool CMy115backDlg::multicompareGreater(int **pData,int col,int n,int m )
{
  bool re=false;
  for (int i=0;i<col;i++){
    if (pData[n][i]>pData[m][i]){re=true;break;}
    else {
      if (pData[n][i]<pData[m][i]){re=false;break;}
    }
  }
  return re;
}

bool CMy115backDlg::multicompareSmaller(int **pData,int col,int n,int m )
{
  bool re=false;
  for (int i=0;i<col;i++){
    if (pData[n][i]<pData[m][i]){re=true;break;}
    else {
      if (pData[n][i]>pData[m][i]){re=false;break;}
    }
  }
  return re;
}


/////////////////////////////////////////////
////////////////////////////
void CMy115backDlg::multpaixu_recur(int **pData,int col,int *gesu,CString *ming,int left,int right)
{ 
  int i,j,k,r;
  int iTemp;
  CString sTemp;
  i=left;
  j=right;
  r=(left+right)/2;
  


  //i=left;
  do {
    while(multicompareGreater(pData,col,i,r ) && (i<right))//从左扫描大于中值的数 
    i++;
    while(multicompareSmaller(pData,col,j,r ) && (j>left))//从右扫描大于中值的数 　

    j--;
    if(i<=j){//找到了一对值交换
      for (k=0;k<col;k++){
        iTemp = pData[i][k];
        pData[i][k] = pData[j][k];
        pData[j][k] = iTemp; 
      }

      iTemp = gesu[i];
      gesu[i] = gesu[j];
      gesu[j] = iTemp; 

      sTemp = ming[i];
      ming[i] = ming[j];
      ming[j] = sTemp; 


      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）

  //当左边部分有值(left<j),递归左半边
  if(left<j) multpaixu_recur(pData,col,gesu,ming,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) multpaixu_recur(pData,col,gesu,ming,i,right);
}


////////////////////////////////////
void CMy115backDlg::paixu_status(CString statusfile) 
{
  int i,j,k,linesu=0,pos,col=0;
  CString s,wr;
  CStdioFile fin;
  fin.Open(statusfile, CFile::modeRead);
  do{
    fin.ReadString(s);s=delern(s);
    k=0;
    pos=s.Find(",");
    while (pos>=0){
      k++;
      //MessageBox(s);
      s=s.Mid(pos+1);
      //MessageBox(s);
      pos=s.Find(",");
    }
    k++;
    if (k>col){col=k;}              
    linesu++;
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();
  //MessageBox(Cstr(col));

  CString *ming=new CString[linesu];
  int *gesu=new int[linesu];
  
  int  **pData=new int *[linesu];
  for (i=0;i<linesu;i++){
    *(pData+i)=new int[col];
  } 

////////////////////////////////////////////////////////
  i=0;
  fin.Open(statusfile, CFile::modeRead);
  do{
    fin.ReadString(s);s=delern(s);
    pos=s.ReverseFind(':');
    ming[i]=s.Mid(pos+1);
    s=s.Left(pos);
    pos=s.Find(':');
    s=s.Left(pos);
    pos=s.ReverseFind(',');
    k=0;
    while (pos>=0){
      pData[i][k]=atoi(s.Mid(pos+1));
      s=s.Left(pos);
      pos=s.ReverseFind(',');
      k++;
    }
    pData[i][k]=atoi(s);
    gesu[i]=k+1;
    for (j=k+1;j<col;j++){pData[i][j]=0;}
    i++;    
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();

  for (i=1;i<=12;i++){multpaixu_recur(pData,col,gesu,ming,0,linesu-1);}
  int kuan=2;
  pos=statusfile.ReverseFind('\\');
  CString nake=statusfile.Mid(pos+1);
  if (nake.Find("dlc3h1")>=0){kuan=2;}
  if (nake.Find("dlc3h2")>=0){kuan=3;}
  if (nake.Find("dlc3h3")>=0){kuan=4;}
  if (nake.Find("ssczx31")>=0){kuan=2;}
  if (nake.Find("ssczx41")>=0){kuan=2;}
  if (nake.Find("ssczx1")>=0){kuan=3;}
  if (nake.Find("ssczx2")>=0){kuan=4;}
  if (nake.Find("ssczx3")>=0 && nake.Find("ssczx31")<0){kuan=5;}
  if (nake.Find("ssczx5")>=0){kuan=5;}

  fin.Open(statusfile,CFile::modeCreate|CFile::modeWrite);   
  for (i=0;i<linesu;i++){
    wr="";

    for (j=gesu[i]-1;j>=0;j--){
      wr=wr+padstrcisu(Cstr(pData[i][j]),kuan," ",0)+",";
    }

    wr=wr.Left(wr.GetLength()-1);
    wr=padstrcisu(wr,col*(kuan+1)," ",0);
////////////////////////////////////////////////    
      pos=wr.ReverseFind(',');
      wr=wr.Left(pos)+"|"+wr.Mid(pos+1);
      pos=wr.ReverseFind(',');
      wr=wr.Left(pos)+"|"+wr.Mid(pos+1);   
////////////////////////////////////////////////
    wr=wr+"::::::"+ming[i]+"\r\n";
    fin.Write(wr,wr.GetLength());
  }

  fin.Close();
  for (i=0;i<linesu;i++){delete[] pData[i];}
  delete[] pData;delete[] ming;delete[] gesu;
}




///////////////////
///////////////////////////////////////////
void CMy115backDlg::mactowindow(CString filename)
{
    CString s;
    int pos,ch;
    
    FILE *fpinPtr,*fpoutPtr;
    if ((fpinPtr=fopen(filename,"rb"))==NULL){return;}

    pos=filename.ReverseFind('.');
    CString newfilename=filename.Left(pos)+"_window"+filename.Mid(pos);

    if ((fpoutPtr=fopen(newfilename,"wb"))==NULL){return;}

    while(!feof(fpinPtr))
    {
        ch=fgetc(fpinPtr);
        if(ch>-1 && ch != '\n')
        {
            fputc(ch,fpoutPtr);
        }
        else if(ch>-1)
        {
            fputc('\r',fpoutPtr);
            fputc(ch,fpoutPtr);
        }

    }

    fclose(fpinPtr);
    fclose(fpoutPtr);
    CopyFile(newfilename,filename,0);
    DeleteFile(newfilename);




}


void CMy115backDlg::OnButton25() 
{
  if (JieMian!=43){jiemian(43);return;} 
   setbutton(FALSE);	
   UpdateData(TRUE); 
   MessageBox("程序结束!");setbutton(TRUE);
}


////////////////////////////
void CMy115backDlg::paimasu3_5(int **pData,int left,int right)
{ 
  int i,j,r;
  int middle1,middle5,middle6,middle7,middle11,iTemp;

  i=left;
  j=right;
  r=(left+right)/2;//left+rand()%(right-left+1);
  middle1=pData[r][1];middle5=pData[r][5];middle6=pData[r][6];middle7=pData[r][7];middle11=pData[r][11];
 

  
  do {
    

    //while((pData[i][1]>middle1 || pData[i][1]==middle1 && pData[i][5]>middle5) && (i<right))//从左扫描大于中值的数 
    //从左扫描大于中值的数 
    while((pData[i][1]>middle1 ||  pData[i][1]==middle1 && pData[i][11]>middle11) && (i<right)){   
      i++;
    }

    //while((pData[j][1]<middle1 || pData[j][1]==middle1 && pData[j][5]<middle5) && (j>left))//从右扫描大于中值的数 　
    while((pData[j][1]<middle1 || pData[j][1]==middle1 && pData[j][11]<middle11) && (j>left)){//从右扫描大于中值的数 　
      j--;
    }
    if(i<=j){//找到了一对值交换
      iTemp = pData[i][0];
      pData[i][0] = pData[j][0];
      pData[j][0] = iTemp;

      iTemp = pData[i][1];
      pData[i][1] = pData[j][1];
      pData[j][1] = iTemp;

      iTemp = pData[i][2];
      pData[i][2] = pData[j][2];
      pData[j][2] = iTemp;

      iTemp = pData[i][3];
      pData[i][3] = pData[j][3];
      pData[j][3] = iTemp;

      iTemp = pData[i][4];
      pData[i][4] = pData[j][4];
      pData[j][4] = iTemp;

      iTemp = pData[i][5];
      pData[i][5] = pData[j][5];
      pData[j][5] = iTemp;

      iTemp = pData[i][6];
      pData[i][6] = pData[j][6];
      pData[j][6] = iTemp;

      iTemp = pData[i][7];
      pData[i][7] = pData[j][7];
      pData[j][7] = iTemp;

      iTemp = pData[i][8];
      pData[i][8] = pData[j][8];
      pData[j][8] = iTemp;

      iTemp = pData[i][9];
      pData[i][9] = pData[j][9];
      pData[j][9] = iTemp;

      iTemp = pData[i][10];
      pData[i][10] = pData[j][10];
      pData[j][10] = iTemp;

      iTemp = pData[i][11];
      pData[i][11] = pData[j][11];
      pData[j][11] = iTemp;

      iTemp = pData[i][12];
      pData[i][12] = pData[j][12];
      pData[j][12] = iTemp;

      iTemp = pData[i][13];
      pData[i][13] = pData[j][13];
      pData[j][13] = iTemp;

      iTemp = pData[i][14];
      pData[i][14] = pData[j][14];
      pData[j][14] = iTemp;

      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) paimasu3_5(pData,left,j);
  //当右边部分有值(right>i),递归右半边
  if(right>i) paimasu3_5(pData,i,right);
}


///////////////////////////
CString CMy115backDlg::binaryatoz(unsigned int x)
{
   unsigned small y;
  
   CString s;
   if (x==0){return "00000000000000000000000000000000";}
   while (x>0){

     y=x%2;
     s=s+Cstr(y);
     x=x/2;
   }
   s=padstrcisu(s,32,"0",1);

   return s;
}


//////////////////////////

//////////////////////////
//////////////////////////////////



////////////////////////////
void CMy115backDlg::paimasubiao(int **pData,int left,int right,int biao,int bound)
{ 
  int i,j,r;
  int middle,iTemp;
  i=left;
  j=right;
  r=(left+right)/2;//left+rand()%(right-left+1);
  middle=pData[r][biao];


  //i=left;
  do {
    while((pData[i][biao]>middle) && (i<right))//从左扫描大于中值的数 
    i++;
    while((pData[j][biao]<middle) && (j>left))//从右扫描大于中值的数 　
    j--;
    if(i<=j){//找到了一对值交换
      for (int k=0;k<bound;k++){
        iTemp = pData[i][k];
        pData[i][k] = pData[j][k];
        pData[j][k] = iTemp;
      }

      

      i++;
      j--;
    }
  }while(i<=j);//如果两边扫描的下标交错,就停止（完成一次）
  //当左边部分有值(left<j),递归左半边
  if(left<j) paimasubiao(pData,left,j,biao,bound);
  //当右边部分有值(right>i),递归右半边
  if(right>i) paimasubiao(pData,i,right,biao,bound);
}



////////////////////////////

void CMy115backDlg::OnButton15() 
{
   if (JieMian!=23){jiemian(23);return;}  
   setbutton(FALSE);
   UpdateData(TRUE);
   if (m_dfile.GetLength()==0){setbutton(TRUE);return;} 
   int pos,i,j,ubound,ai;
   CString s,t,dirpath,datafile;
   CStdioFile out;


   pos=m_dfile.ReverseFind('\\');
   dirpath=m_dfile.Left(pos+1);
   datafile=dirpath+"29new.txt";

   if (m_mo=="2"){
     getsscbuycode(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }
   //dis="类型:1 求预测单码 2 由单码求合成码 3 核对合成码 4 清理重复合成 5 由合成码求合成码 6 生成文件 \r\n";

   if (m_mo=="5"){
     getssche(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }


   if (m_mo=="4"){
     deletehe(dirpath);
     MessageBox("程序结束！");setbutton(TRUE);	return;
   }




   if (m_mo=="1" || m_mo=="3"){////////////////////////////////

   DWORD dwAttr = ::GetFileAttributes(datafile); 
   if (dwAttr == 0xffffffff){MessageBox("没有数据文件");setbutton(TRUE);return;}

   out.Open(datafile, CFile::modeRead);
   
   
   i=0;   
   do{
     out.ReadString(s);
     i=i+1;    
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
   ubound=i;


   CString *datas=new CString[ubound];
   CString *qihao=new CString[ubound];
   small  **data=new small *[ubound];
   for (i=0;i<ubound;i++){
     *(data+i)=new small[5];
   } 


   out.Open(datafile, CFile::modeRead);
   
  
   i=0;   
   do{
     out.ReadString(s);s=delern(s);    
     pos=s.Find('\t');
     s=s.Mid(pos+1);
     pos=s.Find('\t');	 
     qihao[i]=s.Left(pos);
     s=s.Mid(pos+1);	 
     t="";
     for (j=0;j<10;j=j+2){t=t+s.Mid(j,1);}     	 
     datas[i]=t;	
     data[i][0]=atoi(t.Mid(0,1));
     data[i][1]=atoi(t.Mid(1,1));
     data[i][2]=atoi(t.Mid(2,1));
     data[i][3]=atoi(t.Mid(3,1));
     data[i][4]=atoi(t.Mid(4,1));
     i=i+1;
     
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
   
/////////////////////////////////////////////////////


   if (m_mo=="1"){  
     if (m_dfile.Find("29new.txt")>=0){       
       m_wb=m_wb+m_e;
       sscfindtong3(qihao,datas,data,dirpath,ubound); 
       m_wb=m_wb-m_e; 
     }
     else {
       ssc3allrefresh(dirpath,qihao,datas,ubound);
     }

     
   }

///////////////////////////////////////
   if (m_mo=="3"){
//////////////////////////////////////////////////////////
     int yimax[5];
     for (i=0;i<5;i++){yimax[i]=0;}
     CString strDir=dirpath;
     CString szDir = strDir,buyfile,nake; 
     CFileFind ff; 
     szDir += "*.*"; 
     CStdioFile fin;   
     bool res = ff.FindFile(szDir);   
    
     while( res ) 
     { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 

       if(!ff.IsDirectory() && !ff.IsDots()){
         pos=buyfile.ReverseFind('\\'); 
         nake=buyfile.Mid(pos+1);          
         if (nake.Find("he")<0){continue;}        

         checksschccode(dirpath,qihao,datas,ubound,buyfile,yimax);
       }        
       
     }
     ff.Close(); 
     //MessageBox("程序结束！");setbutton(TRUE);	return;
   }



//////////////////////////////////////







   
///////////////////////////////////////////////////////
   delete[] datas;delete[] qihao;
   for (ai=0;ai<ubound;ai++){delete[] data[ai];}
   delete[] data;
   }///if (m_mo=="1" || m_mo=="3"){////////////////////////////////

   MessageBox("程序结束！");setbutton(TRUE);	
}





int CMy115backDlg::sscgorefresh3(CString gofile,CString qihao[],CString datas[],int ubound,CStdioFile &outgosta,bool duo,int &zuida)
{


  CStdioFile fin,out;
  int i,k,pos,bl,bqinum,m;
  CString c,s,t,wr,twr,b[10],bqi,nowqi,zhong,dirpath,tmpfile;
  
  pos=gofile.ReverseFind('\\');
  dirpath=gofile.Left(pos+1);
  int hit,yilou,yiloumax,yzuida,qinum;
 
//////////////////////////////////////////////
  
  CString nake=gofile.Mid(pos+1);
  CString myqi=nake;
  pos=nake.ReverseFind('-');
  if (pos>=0){myqi=nake.Mid(pos+1).Left(9);}
  else {
    pos=nake.ReverseFind(')');
    if (pos>=0){myqi=nake.Mid(pos+1);}  
    myqi=myqi.Left(9);
  }
  if (myqi>qihao[0]){return 0;}
///////////////////////////////////////////////
//////////////////////////////////////
  ////////////////////////////////////////
  int wei=atoi(nake.Left(1));

  ////////////////////////////////////////
  for (i=0;i<5;i++){b[i]="0";}
  s=nake.Mid(2);
  pos=s.Find(")");
  s=s.Left(pos);
  Split(s,b,bl,",");
  yilou=atoi(b[0]);qinum=atoi(b[1]);yiloumax=atoi(b[2]);yzuida=atoi(b[3]);hit=atoi(b[4]);
  if (hit>qinum){
     yilou=atoi(b[0]);yiloumax=atoi(b[1]);yzuida=atoi(b[2]);hit=atoi(b[3]);qinum=atoi(b[4]);
  }
  
  if (yzuida>zuida){zuida=yzuida;}
///////////////////////////////////////////////
  
  //tmpfile=dirpath+"tmp.txt";

  //out.Open(tmpfile,CFile::modeCreate|CFile::modeWrite);



  fin.Open(gofile, CFile::modeRead);
  fin.ReadString(s);s=delern(s);
  k=0;
  while (s.Find(":     :")<0 || s.Left(1)=="/"){
    fin.ReadString(s);s=delern(s);k++;
  }

  CString yuan=s;
  pos=s.ReverseFind('#');
  if (pos>=0){s=s.Left(pos);}
  pos=s.Find(':');
  bqi=s.Left(pos);


  fin.Close();
  if (bqi>qihao[0]){return 0;}

  bool deng=false;
  for (i=0;i<ubound;i++){
    if (qihao[i]==bqi){deng=true;break;}
    if (qihao[i]<bqi){break;}
  }
  if (! deng){MessageBox(gofile+"\r\n"+bqi+" is not in 29new.txt!");return 0;}
  bqinum=i;

  nowqi=qihao[bqinum];



  fin.Open(gofile, CFile::modeRead);
  
  int blk=0;
  
  
  CString jiangstr,bi100str,dstr;
  CString *filezu=new CString[m_wb+50];
  int zuxu=0;  
 
  
  
  
  
  


  if (k>0){
    for (i=0;i<k;i++){fin.ReadString(s);}
  }
  i=0;

  do{
    fin.ReadString(s);s=delern(s);

    if (s.GetLength()<10){continue;}
    if (s.Find("/")>=0){continue;}
    if (s.Find(":     :")<0){i++;continue;}

    m=bqinum-i;
    if (m<0){ 
      blk++;
      nowqi=qijia1(nowqi);
      wr=nowqi+":     :";
      pos=s.ReverseFind(':');      
      wr=wr+s.Mid(pos+1);
      //wr=wr+"\r\n";
      //out.Write(wr,wr.GetLength());
      filezu[zuxu]=wr;
      i++;zuxu++;
      continue;
    }

    qinum++;
    nowqi=qihao[m];
    wr=nowqi+":"+datas[m]+":";
    pos=s.ReverseFind(':');
    s=s.Mid(pos+1);
    
    wr=wr+s+":";
    if (datas[m].Mid(wei-1,1)==s){zhong="!";}    
    else {zhong="*";}



///////////////////////////////////////////

///////////////////////////////////////////
    if (zhong=="!"){
      
      
      ////////////////////////////////////////
      if (duo){        
        twr="after";
        twr+=padstrcisu(Cstr(yilou),3," ",0)+"\t$\r\n";
        outgosta.Write(twr,twr.GetLength());
      }
      
     
      ///////////////////////////////////////
      hit++;
      yilou-=m_mas;
//////////////////////////////////////////////////////////
      
    }
    else {
      ///////////////////////////////////////////
      yilou++;

      if (yilou>yiloumax){
        yiloumax=yilou;      
      }
      
      if (zuida<yiloumax){zuida=yiloumax;}      
    }

//MessageBox("tail="+Cstr(tail));   
//////////////////////////////////////////////////////////////////////////
    if (yilou<qinum*m_num/m_e/2){break;}
  
 
 

///////////////////////////////////////////
    dstr="("+padstrcisu(Cstr(yilou),3,"0",0)+",";
    dstr+=padstrcisu(Cstr(qinum),4,"0",0)+",";      
    dstr+=padstrcisu(Cstr(yiloumax),3,"0",0)+",";   
    dstr+=padstrcisu(Cstr(zuida),3,"0",0)+",";   
    dstr+=padstrcisu(Cstr(hit),3,"0",0)+")";  
    
/////////////////////////////////////////////
    wr=wr+"#"+zhong+dstr+"["+padstrcisu(Cstr(qinum),4," ",0)+"]["+padstrcisu(Cstr(yilou),4," ",0)+"]";
    filezu[zuxu]=wr;
    //out.Write(wr,wr.GetLength());
    i++;zuxu++;   
 
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();//out.Close();
///////////////////////////////////////



  
  if (blk<120 || yilou<m_num/2 ){
    if (duo){   
      twr="after"+padstrcisu(Cstr(yilou),3," ",0)+"\tXXXXXX\r\n";
      outgosta.Write(twr,twr.GetLength());
    }
    DeleteFile(gofile);
    return 0;
  }//没有预期，删除
///////////////////////////////////////////  
///////////////////////////////////////////  

  pos=gofile.ReverseFind('\\');
  s=gofile.Mid(pos+1);
  pos=s.ReverseFind(']');
  if (pos>=0){
    s=s.Left(pos+1);
  }
  else {
    s=s.Left(9);
  }
  pos=s.ReverseFind('@');
  if (pos>=0){s=s.Mid(pos+1);}

  t=Cstr(wei);
  t+=dstr;
  

  s=t+"@"+s;
//MessageBox(s);
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////

  DeleteFile(gofile);
  gofile=dirpath+s+"-"+qihao[0]+"r1go.txt";
  DWORD dwAttr= ::GetFileAttributes(gofile);
  if (dwAttr == 0xffffffff){
    out.Open(gofile,CFile::modeCreate|CFile::modeWrite);
    for (i=0;i<zuxu;i++){
       wr=filezu[i]+"\r\n";
       out.Write(wr,wr.GetLength());
    }
    out.Close();
  }
  //DeleteFile(tmpfile);
  delete[] filezu;
///////////////////////////////////////////////

///////////////////////////////////////////////
  

  
  

}


void CMy115backDlg::qxcfindtong(CString qihao[],CString datas[],small **data,CString dirpath,int ubound)
{

  int disp3=0,nowyi=0,hit,yilou,yiloumax;
  int m,allsu,wei=rand()%7+1;
  
  DWORD dwAttr;
  int allyi=0,i,k,zsu;
  GetDlgItem(idc_jingdu)->SetWindowText("");
  small btzu[10],btzu2[10],btzu3[10],btzu4[10]; 
  int fromwei,back;
  
  CString c,qi,wr,gofile,s,real,dirstr;   
  CStdioFile out; 
  bool goflag,realflag;

  dirstr=dirpath.Right(2);
  dirstr=dirstr.Left(dirstr.GetLength()-1);
  dirstr=dirstr.Right(1);
  if (dirstr<"0" || dirstr>"9"){dirstr=Cstr(rand()%10);}

  int n;


  unsigned small *ma=new unsigned small [m_wb];
  int *yi=new int[m_e];
  for (i=0;i<m_e;i++){
    yi[i]=(i+1)*m_num/m_e;
  }

  zsu=0;
  



  clock_t begin=clock(),end,t1=clock(),t2=clock(),hitbegin=clock();
  double duration,dur,dur1,hitdur=-1,lastdur;
  if (m_b<=0){m_b=1;}
  int max_mnum=280,min_mnum=160,checktime=360;

  int onedur=3600/m_b,beidur=2*onedur,halfdur=onedur/4;
  int shijian,hour,min,sec;
  while (true){


    qxcbtzu(btzu,btzu2,btzu3,btzu4,back,fromwei);  
    real="";realflag=true;


    dur=(double)(clock()-t1) / CLOCKS_PER_SEC;
    dur1=(double)(clock()-t2) / CLOCKS_PER_SEC;
    if (dur>=5){
      t1=clock();
      end=clock();
      if (dur1>checktime){
        t2=clock();
        duration=(double)(end-begin) / CLOCKS_PER_SEC/onedur;
        lastdur=(clock()-hitbegin)/ CLOCKS_PER_SEC;
        if (zsu>duration && m_num<max_mnum && zsu>=1 && (hitdur<=onedur || hitdur==-1)){m_num++;}
        if (zsu<duration && m_num>min_mnum && zsu>=1 && (hitdur>=onedur || hitdur==-1)){m_num--;}
        if (lastdur>beidur && m_num>min_mnum ){m_num--;}
        if (hitdur<halfdur && lastdur<halfdur && m_num<max_mnum ){m_num++;}
      }
      
      if (tuichu==1){
        delete[] ma;delete[] yi;     
        tuichu=0;
        return;
      }
    }
    for (i=0;i<m_wb;i++){ 
      ma[i]=btzu[btzu2[btzu3[btzu4[data[i+back][fromwei]]]]];   
      if (realflag && i>=m_e){
        real+=Cstr(ma[i]);
        if (real.GetLength()>=8){realflag=false;}
      }

    }    

//////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
    allsu=0;yilou=0;yiloumax=0;hit=0;
    k=m_e-1;
    
    for (i=0;i<m_e;i++){
      //if (qi>=qihao[0]){n=i;break;}
      //qi=qijia1(qi);
      qi=qihao[k];
      k--;       
      m=m_e-1-i;
      

      /////////////////////////////////////////
      //if (datas[m].Mid(wei-1,1)==Cstr(ma[i])){
      if (data[m][wei-1]==ma[i]){
        yilou-=m_mas;hit++;
      }
      else {
        yilou++;        
        if (yilou>yiloumax){yiloumax=yilou;}
      }
      ////////////////////////////////////////      
      if (yilou<yi[i]){break;}

      ////////////////////////////////////////
         
      ////////////////////////////////////////

    }
    DoEvents();

    goflag=(yilou>=m_num);
    
    if (! goflag){continue;}
    n=i;      
    

    
/////////////////////////////////////////////////////////////////////

    i=1;
    s=Cstr(wei);
    s+="("+padstrcisu(Cstr(yilou),3,"0",0)+","
          +padstrcisu(Cstr(m_e),3,"0",0)+","   
          +padstrcisu(Cstr(yiloumax),3,"0",0)+","
          +padstrcisu(Cstr(yiloumax),3,"0",0)+","
          +padstrcisu(Cstr(hit),3,"0",0)+")";


    CString head=dirpath+s+qi+"["+real+"]";
    gofile=head+"go.txt";  
    dwAttr= ::GetFileAttributes(gofile);
    if (dwAttr != 0xffffffff){continue;}
    
    out.Open(gofile,CFile::modeCreate|CFile::modeWrite);

///////////////////////////////////////////////////////////

    for (i=n;i<m_wb;i++){      
      qi=qijia1(qi);       
      wr=qi+":       :";


      ////////////////////////////////////////
      wr=wr+Cstr(ma[i]);

      wr=wr+"\r\n";
      out.Write(wr,wr.GetLength());
      
      
    }

    out.Close();
    wei++; 
    if (wei==8){wei=1;}


    zsu++;
/////////////////////////////////////////////////////
    if (disp3<yiloumax){disp3=yiloumax;}
    DoEvents();
    shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
    hour=shijian/3600;
    n=shijian-hour*3600;
    min=n/60;
    sec=n-60*min;
    s="["+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec)+"]";
    GetDlgItem(idc_jingdu)->SetWindowText("find "+Cstr(zsu)+" now="+Cstr(yilou)
                  +" max="+Cstr(disp3)+" should="+Cstr((int)duration)+" standard="+Cstr(m_num)
                  +" time="+Cstr(shijian)+s );

    
    if (tuichu==1){
      delete[] ma; delete[] yi;          
      tuichu=0;
      return;
    }


  }

}


int CMy115backDlg::qxcgorefresh3(CString gofile,CString qihao[],CString datas[],int ubound,CStdioFile &outgosta,bool duo,int &zuida)
{


  CStdioFile fin,out;
  int i,k,pos,bl,bqinum,m,qinum;
  CString c,s,t,wr,twr,b[10],bqi,nowqi,zhong,dirpath,tmpfile;
  
  pos=gofile.ReverseFind('\\');
  dirpath=gofile.Left(pos+1);
  int hit,yilou,yiloumax,yzuida;

//////////////////////////////////////////////
  
  CString nake=gofile.Mid(pos+1);
  CString myqi=nake;
  pos=nake.ReverseFind('-');
  if (pos>=0){myqi=nake.Mid(pos+1).Left(5);}
  else {
    pos=nake.ReverseFind(')');
    if (pos>=0){myqi=nake.Mid(pos+1);}
    myqi=myqi.Left(5);
  }
//MessageBox("myqi="+myqi+"\r\nqihao[0]="+qihao[0]);
  if (myqi>qihao[0]){return 0;}
///////////////////////////////////////////////
//MessageBox("myqi="+myqi+"\r\nqihao[0]="+qihao[0]);
//////////////////////////////////////
  ////////////////////////////////////////
  int wei=atoi(nake.Left(1));

  ////////////////////////////////////////
  for (i=0;i<4;i++){b[i]="0";}
  s=nake.Mid(2);
  pos=s.Find(")");
  s=s.Left(pos);
  Split(s,b,bl,",");
  yilou=atoi(b[0]);qinum=atoi(b[1]);yiloumax=atoi(b[2]);yzuida=atoi(b[3]);hit=atoi(b[4]);
  if (hit>qinum){
     yilou=atoi(b[0]);yiloumax=atoi(b[1]);yzuida=atoi(b[2]);hit=atoi(b[3]);qinum=atoi(b[4]);
  }


  if (yzuida>zuida){zuida=yzuida;}
///////////////////////////////////////////////

  tmpfile=dirpath+"tmp.txt";

  //out.Open(tmpfile,CFile::modeCreate|CFile::modeWrite);



  fin.Open(gofile, CFile::modeRead);
  fin.ReadString(s);s=delern(s);
  k=0;
  while (s.Find(":       :")<0 || s.Left(1)=="/"){
    fin.ReadString(s);s=delern(s);k++;
  }

  CString yuan=s;
  pos=s.ReverseFind('#');
  if (pos>=0){s=s.Left(pos);}
  pos=s.Find(':');
  bqi=s.Left(pos);


  fin.Close();

  if (bqi>qihao[0]){return 0;}

  bool deng=false;
  for (i=0;i<ubound;i++){
    if (qihao[i]==bqi){deng=true;break;}
    if (qihao[i]<bqi){break;}
  }
  if (! deng){MessageBox(gofile+"\r\n"+bqi+" is not in qxcdata.txt!");return 0;}
  bqinum=i;

  nowqi=qihao[bqinum];


//MessageBox("bqinum="+Cstr(bqinum)+"\r\nnowqi="+nowqi+"\r\nnake="+nake);
  fin.Open(gofile, CFile::modeRead);
 
  int blk=0;
  
  
  CString jiangstr,bi100str,dstr;
  CString *filezu=new CString[m_wb+50];
  int zuxu=0;  
  
  
 
  

  
  
  
  if (k>0){
    for (i=0;i<k;i++){fin.ReadString(s);}
  }
  i=0;

  do{
    fin.ReadString(s);s=delern(s);

    if (s.GetLength()<10){continue;}
    if (s.Find("/")>=0){continue;}
    if (s.Find(":       :")<0){i++;continue;}

    m=bqinum-i;
    if (m<0){ 
      blk++;
      nowqi=qijia1(nowqi);
      wr=nowqi+":       :";
      pos=s.ReverseFind(':');      
      wr=wr+s.Mid(pos+1);
      filezu[zuxu]=wr;
      i++;zuxu++;
      continue;
    }

    qinum++;
    nowqi=qihao[m];
    wr=nowqi+":"+datas[m]+":";
    pos=s.ReverseFind(':');
    s=s.Mid(pos+1);
    
    wr=wr+s+":";
 
    if (datas[m].Mid(wei-1,1)==s){zhong="!";}    
    else {zhong="*";}

//MessageBox(datas[m]+"\r\nxma"+s+"\r\nzhong="+zhong);       


///////////////////////////////////////////

///////////////////////////////////////////
    if (zhong=="!"){
      if (duo){        
        twr="after";
        twr+=padstrcisu(Cstr(yilou),3," ",0)+"\t$\r\n";
        outgosta.Write(twr,twr.GetLength());
      }
      
     
      ///////////////////////////////////////
      hit++;
      yilou-=m_mas;
//////////////////////////////////////////////////////////
     
    }
    else {
      yilou++;

      if (yilou>yiloumax){
        yiloumax=yilou;      
      }
      
      if (zuida<yiloumax){zuida=yiloumax;}     
    }

//MessageBox("tail="+Cstr(tail));   
//////////////////////////////////////////////////////////////////////////
    if (yilou<qinum*m_num/m_e/2){break;}




///////////////////////////////////////////
    dstr="("+padstrcisu(Cstr(yilou),3,"0",0)+",";
    dstr+=padstrcisu(Cstr(qinum),3,"0",0)+",";      
    dstr+=padstrcisu(Cstr(yiloumax),3,"0",0)+",";   
    dstr+=padstrcisu(Cstr(zuida),3,"0",0)+",";   
    dstr+=padstrcisu(Cstr(hit),3,"0",0)+")";  
    
/////////////////////////////////////////////
    wr=wr+"#"+zhong+dstr+"["+padstrcisu(Cstr(qinum),4," ",0)+"]["+padstrcisu(Cstr(yilou),4," ",0)+"]\r\n";
    filezu[zuxu]=wr;
    i++;zuxu++;   
   
 
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();//out.Close();
//MessageBox("3\r\nblk="+Cstr(blk));  
///////////////////////////////////////

  
  if (blk<1  || yilou<m_num/2 ){
    if (duo){   
      twr="after"+padstrcisu(Cstr(yilou),3," ",0)+"\tXXXXXX\r\n";
      outgosta.Write(twr,twr.GetLength());
    }
    DeleteFile(gofile);
    return 0;
  }//没有预期，删除
///////////////////////////////////////////  
///////////////////////////////////////////  

  pos=gofile.ReverseFind('\\');
  s=gofile.Mid(pos+1);
  pos=s.ReverseFind(']');
  if (pos>=0){
    s=s.Left(pos+1);
  }
  else {
    s=s.Left(5);
  }
  pos=s.ReverseFind('@');
  if (pos>=0){s=s.Mid(pos+1);}













//////////////////////////////////////
/////////////////////////////////////////






  t=Cstr(wei);
  t+=dstr;
  

  s=t+"@"+s;
//MessageBox(s);
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
  DeleteFile(gofile);
  gofile=dirpath+s+"-"+qihao[0]+"r1go.txt";
  DWORD dwAttr= ::GetFileAttributes(gofile);
  if (dwAttr == 0xffffffff){
    out.Open(gofile,CFile::modeCreate|CFile::modeWrite);
    for (i=0;i<zuxu;i++){
       wr=filezu[i]+"\r\n";
       out.Write(wr,wr.GetLength());
    }
    out.Close();
  }
  //DeleteFile(tmpfile);
  delete[] filezu;


}














void CMy115backDlg::getsscbuycode(CString dirpath) 
{
  int filenum=0,i,j,k,pos;
  CString outfile,s,t,wr;
  CString strDir=dirpath;
  CString szDir = strDir,buyfile,nake; 
  CFileFind ff; 
  szDir += "*.*"; 
  int jie=m_qmas;


  bool res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)!="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")>=0){continue;}

       s=nake.Mid(2);
       pos=s.Find(",");
       //if (atoi(s.Left(pos))<jie){continue;}

       filenum++;
     }
  }
  ff.Close(); 
  if (filenum<5){return;}
  CString * filename=new CString [filenum];
//MessageBox(Cstr(filenum));
  res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)!="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")>=0){continue;}

       s=nake.Mid(2);
       pos=s.Find(",");
       //if (atoi(s.Left(pos))<jie){continue;}

       filename[i]=nake;
       i++;
     }
  }
  ff.Close(); 
  paixuztoa(filename,filenum);
  bool zuflag[5];
  for (i=0;i<5;i++){zuflag[i]=false;}
  CString zu[5];

  k=0;
  for (i=0;i<filenum;i++){
    buyfile=filename[i];
    pos=buyfile.ReverseFind('\\');
    nake=buyfile.Mid(pos+1);
    j=atoi(nake.Left(1))-1;
    if (!zuflag[j]){
      zu[j]=nake;zuflag[j]=true;
      k++;
      if (k>=5){break;}      
    }    
  }

  if (k<5){return;}
  delete[] filename;
  getonessczu(zu,dirpath);


}

void CMy115backDlg::getonessczu(CString zu[],CString dirpath)
{

  int i,yisum,fromsu,bl,pos,j;
  CString outfile,rd[5],b[4],wr,s;
  yisum=0;
  for (i=0;i<5;i++){
    yisum+=atoi(zu[i].Mid(2,3));
  }

  if (yisum<m_qmas){return;}

  CStdioFile fin[5],out;
  outfile=dirpath+"h0000he[";
  fromsu=0;
  for (i=0;i<5;i++){
    fin[i].Open(dirpath+zu[i], CFile::modeRead);
    while (true){
      fin[i].ReadString(rd[i]);rd[i]=delern(rd[i]);
      if (rd[i].Find(":     :")>0){break;}  
    }
    s=zu[i];
    pos=s.Find("[");
    s=s.Mid(pos+1);
    pos=s.Find("]");
    s=s.Left(pos);
    fromsu+=atoi(s);
    s=rd[i].Left(9);    
  }
  outfile+=padstrcisu(Cstr(fromsu),8,"0",0)+"-"+Cstr(yisum);
  outfile+="]"+s+".txt";
  out.Open(outfile,CFile::modeCreate|CFile::modeWrite);  
  while (rd[0]!="0" && rd[1]!="0" && rd[2]!="0" && rd[3]!="0" && rd[4]!="0"){
    Split(rd[0],b,bl,":");
    wr=b[0]+":     :"+b[2];

    Split(rd[1],b,bl,":");
    wr+=b[2];
      
    Split(rd[2],b,bl,":");
    wr+=b[2];

    Split(rd[3],b,bl,":");
    wr+=b[2];

    Split(rd[4],b,bl,":");
    wr+=b[2]+"\r\n";
   
    out.Write(wr,wr.GetLength());
    ////////////////////////////////////////////////////
    for (j=0;j<5;j++){
      if (fin[j].GetPosition()!=fin[j].GetLength()){
        fin[j].ReadString(rd[j]);rd[j]=delern(rd[j]);
      }
      else {rd[j]="0";}
    }
    ///////////////////////////////////////////////////
  }  
    

  out.Close();
  for (j=0;j<5;j++){fin[j].Close();}
  
}






void CMy115backDlg::deletehe(CString dirpath){
   int i,j,ubound,pos;
   CString strDir=dirpath;
   CString szDir = strDir,buyfile,nake,s,t; 
   CFileFind ff; 
   szDir += "*.*"; 




   bool res = ff.FindFile(szDir);   
   ubound=0;
   while( res ) 
   { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 

     if(!ff.IsDirectory() && !ff.IsDots()){
       pos=buyfile.ReverseFind('\\'); 
       nake=buyfile.Mid(pos+1);          
       if (nake.Find("he")<0){continue;}    
       if (nake.Find("ahe")>=0){continue;} 
       ubound++;       
     }        
       
   }
   ff.Close(); 

   if (ubound<2){return;}
   CString *myzu=new CString [ubound];

   res = ff.FindFile(szDir);   
   i=0;
   while( res ) 
   { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 

     if(!ff.IsDirectory() && !ff.IsDots()){
       pos=buyfile.ReverseFind('\\'); 
       nake=buyfile.Mid(pos+1);          
       if (nake.Find("he")<0){continue;}        
       if (nake.Find("ahe")>=0){continue;} 
       pos=nake.Find("[");
       s=nake.Mid(pos+1);
       pos=s.Find("]");
       s=s.Left(pos);
       s=s+"#"+buyfile;
       myzu[i]=s;i++;      
     }        
       
   }
   ff.Close(); 
   paixuztoa(myzu,ubound);
   for (i=0;i<ubound-1;i++){
     s=myzu[i];
     pos=s.Find("#");     
     s=s.Left(pos);
     pos=s.Find("-");
     s=s.Left(pos);
     for (j=i+1;j<ubound;j++){
       t=myzu[j];
       pos=t.Find("#");
       buyfile=t.Mid(pos+1);
       t=t.Left(pos);
       pos=t.Find("-");
       t=t.Left(pos);
       if (s==t){
        DWORD dwAttr= ::GetFileAttributes(buyfile);
        if (dwAttr != 0xffffffff){DeleteFile(buyfile);}
       }
     }
   }


}



void CMy115backDlg::sscfindtong3(CString qihao[],CString datas[],small **data,CString dirpath,int ubound)
{


  int disp3=0,nowyi=0,hit,yilou,yiloumax;
  int m,allsu,wei,pos,yisum;
  
  
  DWORD dwAttr;
  int allyi=0,i,j,k,zsu,old;
  GetDlgItem(idc_jingdu)->SetWindowText("");
  small btzu[10],btzu2[10],btzu3[10],btzu4[10]; 
  int fromwei,back;
  
  CString c,qi,wr,gofile,s,real,dirstr;   
  CStdioFile out; 
  bool goflag,realflag;

  dirstr=dirpath.Right(2);
  dirstr=dirstr.Left(dirstr.GetLength()-1);
  dirstr=dirstr.Right(1);
  if (dirstr<"0" || dirstr>"9"){dirstr=Cstr(rand()%10);}
  int n;

//////////////////////////////////////////////////
  CString zu[5][30],myzu[5];
  for (i=0;i<5;i++){
  for (j=0;j<30;j++){
    zu[i][j]="0(000";
  }}

  CString strDir=dirpath;
  CString szDir = strDir,nake; 
  CFileFind ff; 
  szDir += "*.*"; 



  bool res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     gofile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (gofile.Right(6)!="go.txt"){continue;}
       pos=gofile.ReverseFind('\\');
       nake=gofile.Mid(pos+1);
       if (nake.Find("he")>=0){continue;}

       wei=atoi(nake.Left(1));
       
       s=nake.Mid(2);
       pos=s.Find(",");
       yilou=atoi(s.Left(pos));

       for (i=0;i<30;i++){
         if (yilou<=atoi(zu[wei-1][i].Mid(2,3))){continue;}
         break;
       }
       if (i<29){
         for (j=28;j>=i;j--){zu[wei-1][j+1]=zu[wei-1][j];}
       }
       if (i<30){zu[wei-1][i]=nake;}
                 
     }
  }
  ff.Close(); 
  wei=1;
  for (i=1;i<5;i++){
    if (zu[i][0]<zu[wei-1][0]){wei=i+1;} 
  }
//////////////////////////////////////////////////

  unsigned small *ma=new unsigned small [m_wb];
  int *yi=new int[m_e];
  for (i=0;i<m_e;i++){
    yi[i]=(i+1)*m_num/m_e;
  }
  zsu=0;


  clock_t begin=clock(),end,t1=clock(),t2=clock(),hitbegin=clock();
  double duration,dur,dur1,hitdur=-1,lastdur;
  if (m_b<=30){m_b=30;}
  int max_mnum=200,min_mnum=100,checktime=60;
  int onedur=3600/m_b,beidur=2*onedur,halfdur=onedur/4;
  int shijian,hour,min,sec;

  while (true){
    sscbtzu(btzu,btzu2,btzu3,btzu4,back,fromwei);  
    real="";realflag=true;

    dur=(double)(clock()-t1) / CLOCKS_PER_SEC;
    dur1=(double)(clock()-t2) / CLOCKS_PER_SEC;
    if (dur>=5){
      t1=clock();
      end=clock();
      if (dur1>checktime){
        t2=clock();
        duration=(double)(end-begin) / CLOCKS_PER_SEC/onedur;
        lastdur=(clock()-hitbegin)/ CLOCKS_PER_SEC;
        if (zsu>duration && m_num<max_mnum && zsu>=1 && (hitdur<=onedur || hitdur==-1)){m_num++;}
        if (zsu<duration && m_num>min_mnum && zsu>=1 && (hitdur>=onedur || hitdur==-1)){m_num--;}
        if (lastdur>beidur && m_num>min_mnum ){m_num--;}
        if (hitdur<halfdur && lastdur<halfdur && m_num<max_mnum ){m_num++;}
      }
      
      if (tuichu==1){
        delete[] ma; delete[] yi;     
        tuichu=0;
        return;
      }
    }
    
    for (i=0;i<m_wb;i++){   
      if (i%m_ql==0){
        ma[i]=btzu[btzu2[btzu3[btzu4[data[i+back][fromwei]]]]];
        old=ma[i];
        if (realflag && i>=m_e){
          real+=Cstr(ma[i]);
          if (real.GetLength()>=8){realflag=false;}
        }
        
      }
      else {ma[i]=old;}  
    }    
//////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
    allsu=0;yilou=0;yiloumax=0;hit=0;
    
    
    k=m_e-1;
    
    
    for (i=0;i<m_e;i++){
      qi=qihao[k];
      k--;       
   
      m=m_e-1-i;

      

      /////////////////////////////////////////
      if (data[m][wei-1]==ma[i]){ 
        yilou-=m_mas;hit++;
      }
      else {
        
        yilou++;
        
        if (yilou>yiloumax){yiloumax=yilou;}
      }
      ////////////////////////////////////////      
      if (yilou<yi[i]){break;}
      ////////////////////////////////////////
         
      ////////////////////////////////////////

    }
    
    DoEvents();
    goflag=(yilou>=m_num);
    //GetDlgItem(idc_jingdu)->SetWindowText("find "+Cstr(zsu)+" now="+Cstr(yilou)+" max="+Cstr(disp3));
    
    if (! goflag){continue;}
    n=i;      
    
    
/////////////////////////////////////////////////////////////////////

    i=1;
    s=Cstr(wei);

    s+="("+padstrcisu(Cstr(yilou),3,"0",0)+","
          +padstrcisu(Cstr(m_e),3,"0",0)+","   
          +padstrcisu(Cstr(yiloumax),3,"0",0)+","
          +padstrcisu(Cstr(yiloumax),3,"0",0)+","
          +padstrcisu(Cstr(hit),3,"0",0)+")";
     
    //real=padstrcisu(Cstr(rand()%10003),3,"0",0)+padstrcisu(Cstr(rand()%1000),3,"0",0)+dirstr;
    //real=padstrcisu(Cstr(masum)+Cstr(masum3),8,"0",0);//+Cstr(masum7)
    
    CString head=dirpath+s+qi+"["+real+"]";
    gofile=head+"go.txt";  
    dwAttr= ::GetFileAttributes(gofile);
    if (dwAttr != 0xffffffff){continue;}

    //if (tail>nowyi){nowyi=tail;}
    out.Open(gofile,CFile::modeCreate|CFile::modeWrite);

///////////////////////////////////////////////////////////

    for (i=n;i<m_wb;i++){      
      qi=qijia1(qi);       
      wr=qi+":     :";


      ////////////////////////////////////////
      wr=wr+Cstr(ma[i]);

      wr=wr+"\r\n";
      out.Write(wr,wr.GetLength());
      
      
    }

    out.Close();


    zsu++;
/////////////////////////////////////////////////////
    if (disp3<yiloumax){disp3=yiloumax;}
    DoEvents();
    shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
    hour=shijian/3600;
    n=shijian-hour*3600;
    min=n/60;
    sec=n-60*min;
    s="["+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec)+"]";

    GetDlgItem(idc_jingdu)->SetWindowText("find "+Cstr(zsu)+" now="+Cstr(yilou)
                    +" max="+Cstr(disp3)+" should="+Cstr((int)duration)+" standard="+Cstr(m_num)
                    +" time="+Cstr(shijian)+s );

////////////////////////////////////////////////////////////////////////////////////////
    pos=gofile.ReverseFind('\\');
    nake=gofile.Mid(pos+1);    
    for (i=0;i<30;i++){
      if (yilou<=atoi(zu[wei-1][i].Mid(2,3))){continue;}
      break;
    }
    if (i<29){
      for (j=28;j>=i;j--){zu[wei-1][j+1]=zu[wei-1][j];}
    }
    if (i<30){zu[wei-1][i]=nake;}
       
    yisum=0;k=0;
    for (i=0;i<5;i++){
      s=zu[i][0];
      n=atoi(s.Mid(2,3));
      if (n>=m_num){yisum+=n;k++;}
    }
    if (yisum>=m_qmas && k>=5){
      for (i=0;i<5;i++){myzu[i]=zu[i][0];}
      getonessczu(myzu,dirpath);
      for (i=0;i<5;i++){
        for (j=1;j<30;j++){
          zu[i][j-1]=zu[i][j];
        }
        zu[i][29]="0(000";
      }
    }
///////////////////////////////////////////////////////////////////////////////////////////////////


    if (tuichu==1){
      delete[] ma; delete[] yi;     
      tuichu=0;
      return;
    }

    wei++; 
    if (wei==6){wei=1;}


  }

}



///////////////////////////////////
/////////////////////////////////////////////////
void CMy115backDlg::megabtzu(small btzu[],small btzu2[],int &back,int &fromwei)
{
  

  int i,h_i,k;
  small rdsn[75],h_n,m; 

  fromwei=rand()%5;
  i=m_wb+m_tuib;
  back=i+rand()%50;
 

  for (i=0;i<75;i++){rdsn[i]=i;}
  for (h_i=75;h_i>1;h_i--) {  
      //h_n=myrnd()%h_i;  
      h_n=rand()%h_i;
      btzu[75-h_i]=rdsn[h_n];
      if (h_n<h_i-1){
         m=rdsn[h_n];
         for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
	 rdsn[h_i-1]=m;
      }		  
  }  
  btzu[74]=rdsn[0];


  for (i=0;i<75;i++){rdsn[i]=i;}
  for (h_i=75;h_i>1;h_i--) {  
      //h_n=myrnd()%h_i;  
      h_n=rand()%h_i;
      btzu2[75-h_i]=rdsn[h_n];
      if (h_n<h_i-1){
         m=rdsn[h_n];
         for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
	 rdsn[h_i-1]=m;
      }		  
  }
  btzu2[74]=rdsn[0];
}


void CMy115backDlg::megaendbtzu(small btzu[],small btzu2[],int &back,int &fromwei)
{
  

  int i,h_i,k;
  small rdsn[15],h_n,m; 

  fromwei=5;
  i=m_wb-m_e;
  back=i+rand()%30;
 

  for (i=0;i<15;i++){rdsn[i]=i;}
  for (h_i=15;h_i>1;h_i--) {  
      //h_n=myrnd()%h_i;  
      h_n=rand()%h_i;
      btzu[15-h_i]=rdsn[h_n];
      if (h_n<h_i-1){
         m=rdsn[h_n];
         for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
	 rdsn[h_i-1]=m;
      }		  
  }  
  btzu[14]=rdsn[0];


  for (i=0;i<15;i++){rdsn[i]=i;}
  for (h_i=15;h_i>1;h_i--) {  
      //h_n=myrnd()%h_i; 
      h_n=rand()%h_i; 
      btzu2[15-h_i]=rdsn[h_n];
      if (h_n<h_i-1){
         m=rdsn[h_n];
         for (k=h_n;k<h_i-1;k++){rdsn[k]=rdsn[k+1];}
	 rdsn[h_i-1]=m;
      }		  
  }
  btzu2[14]=rdsn[0];
}


void CMy115backDlg::megaallrefresh(CString dirpath,CString qihao[],CString datas[],int ubound) 
{
    CString strDir=dirpath,nake;
    CString szDir = strDir,buyfile; 
    
    CString bqi,s,s1,s2,s3,wr,t;

    CFileFind ff; 
    szDir += "*.*"; 
    int i,bl,n;
    bool res = ff.FindFile(szDir);   
    CStdioFile fin,out,outall;
    CString gostafile=dirpath+"gosta.txt",b[10],bb[3];
    out.Open(gostafile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate); 
    out.SeekToEnd(); 

    i=0;
    while( res ) 
    { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 

       if(!ff.IsDirectory() && !ff.IsDots()){

         if (buyfile.Right(6)!="go.txt"){continue;}    
         i++;
                  
       }
          
    } 
    ff.Close();
    if (i==0){return;}


    n=i;
    CString *filename=new CString [n];
///////////////////////////////////////////////////
    res = ff.FindFile(szDir);  
    i=0;


    while( res ) 
    { 
       res = ff.FindNextFile(); 
       buyfile = ff.GetFilePath(); 

       if(!ff.IsDirectory() && !ff.IsDots()){

         if (buyfile.Right(6)!="go.txt"){continue;}    
         filename[i]=buyfile;
         i++;                 
       }
          
    } 
    ff.Close();




///////////////////////////////////////////////
///////////////////////////////////////////////////
    int zuida=0,zuidae=0;
    for (i=0;i<n;i++){
      megagorefresh3(filename[i],qihao,datas,ubound,out,true,zuida,zuidae); 
    }
    delete[] filename;   
    out.Close();

    sortafileatoz(gostafile);
    DWORD dwAttr= ::GetFileAttributes(gostafile);
    if (dwAttr == 0xffffffff){return;}


    
///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

    const SU=800;
    int zhongsu[SU],allsu[SU],chasu[SU],sum,jian;
    CString sufile;
    
    for (i=0;i<SU;i++){zhongsu[i]=0;allsu[i]=0;}
    fin.Open(gostafile, CFile::modeRead);
    do{
      fin.ReadString(s);s=delern(s);
      if (s.Left(5)!="after"){continue;}

      s=s.Mid(5);
      Split(s,b,bl,"\t");
      if (b[1]!="head"){continue;}
      i=atoi(b[0]);

      if (i>=SU-1){i=SU-1;}   
      allsu[i]++;
      if (b[2]=="$"){zhongsu[i]++;}
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();

    sum=0;jian=0;
    for (i=0;i<SU;i++){sum+=allsu[i];}
    for (i=0;i<SU;i++){
      chasu[i]=sum-jian;
      jian+=allsu[i];
    }

    sufile=dirpath+"head.txt";
    out.Open(sufile,CFile::modeCreate|CFile::modeWrite);
    for (i=m_num;i<SU;i++){
      if (chasu[i]==0){break;}
      wr=padstrcisu(Cstr(i),4," ",0)+"  ";
      wr+=padstrcisu(Cstr(zhongsu[i]),6," ",0)+"  ";
      wr+=padstrcisu(Cstr(chasu[i]),6," ",0)+"  ";
      wr+=padstrcisu(Cstr(zhongsu[i]*10000/chasu[i]),6," ",0)+"\r\n";
      out.Write(wr,wr.GetLength());
    }
    out.Close();
    /////////////////////////////////////////////////
    ////////////////////////////////////////////////
    for (i=0;i<SU;i++){zhongsu[i]=0;allsu[i]=0;}
    fin.Open(gostafile, CFile::modeRead);
    do{
      fin.ReadString(s);s=delern(s);
      if (s.Left(5)!="after"){continue;}

      s=s.Mid(5);
      Split(s,b,bl,"\t");
      if (b[1]!="tail"){continue;}
      i=atoi(b[0]);

      if (i>=SU-1){i=SU-1;}   
      allsu[i]++;
      if (b[2]=="$"){zhongsu[i]++;}
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();

    sum=0;jian=0;
    for (i=0;i<SU;i++){sum+=allsu[i];}
    for (i=0;i<SU;i++){
      chasu[i]=sum-jian;
      jian+=allsu[i];
    }

    sufile=dirpath+"tail.txt";
    out.Open(sufile,CFile::modeCreate|CFile::modeWrite);
    for (i=m_num;i<SU;i++){
      if (chasu[i]==0){break;}
      wr=padstrcisu(Cstr(i),4," ",0)+"  ";
      wr+=padstrcisu(Cstr(zhongsu[i]),6," ",0)+"  ";
      wr+=padstrcisu(Cstr(chasu[i]),6," ",0)+"  ";
      wr+=padstrcisu(Cstr(zhongsu[i]*10000/chasu[i]),6," ",0)+"\r\n";
      out.Write(wr,wr.GetLength());
    }
    out.Close();

}




int CMy115backDlg::megagorefresh3(CString gofile,CString qihao[],CString datas[],int ubound,CStdioFile &outgosta,bool duo,int &zuida,int &zuidae)
{

  CStdioFile fin,out;
  int i,k,pos,bl,bqinum,m,qinum;
  CString c,s,t,wr,twr,b[15],bqi,nowqi,zhong,dirpath,tmpfile;
  
  pos=gofile.ReverseFind('\\');
  dirpath=gofile.Left(pos+1);
  int hit,yilou,yiloumax,yzuida;
  


 

  
  CString nake=gofile.Mid(pos+1);
  CString myqi=nake;
  pos=nake.ReverseFind('-');
  if (pos>=0){
    myqi=nake.Mid(pos+1);
    pos=myqi.Find("r");
    myqi=myqi.Left(pos);
  }
  else {
    pos=nake.ReverseFind(')');
    myqi=nake.Mid(pos+1);
    pos=myqi.Find("[");
    myqi=myqi.Left(pos);
  }
  if (atoi(myqi)>atoi(qihao[0])){return 0;}
///////////////////////////////////////////////
  int wei=atoi(nake.Left(1));
//////////////////////////////////////
  ////////////////////////////////////////
//MessageBox("2");  
  ////////////////////////////////////////
  for (i=0;i<5;i++){b[i]="0";}
  s=nake.Mid(2);
  pos=s.Find(")");
  s=s.Left(pos);
  Split(s,b,bl,",");

  yilou=atoi(b[0]);qinum=atoi(b[1]);yiloumax=atoi(b[2]);yzuida=atoi(b[3]);hit=atoi(b[4]);

  if (wei==1){
    if (yzuida>zuida){zuida=yzuida;}
  }
  else {zuidae=yzuida;}
///////////////////////////////////////////////



  tmpfile=dirpath+"tmp.txt";

  //out.Open(tmpfile,CFile::modeCreate|CFile::modeWrite);

//MessageBox("3");

  fin.Open(gofile, CFile::modeRead);
  fin.ReadString(s);s=delern(s);
  k=0;
  while (s.Find(":                 :")<0 || s.Left(1)=="/"){
    fin.ReadString(s);s=delern(s);k++;
  }

  CString yuan=s;
  pos=s.ReverseFind('#');
  if (pos>=0){s=s.Left(pos);}
  pos=s.Find(':');
  bqi=s.Left(pos);

//MessageBox("4");
  fin.Close();
  if (atoi(bqi)>atoi(qihao[0])){return 0;}

  bool deng=false;
  for (i=0;i<ubound;i++){
    if (qihao[i]==bqi){deng=true;break;}
    if (atoi(qihao[i])<atoi(bqi)){break;}
  }
  if (! deng){MessageBox(gofile+"\r\n"+bqi+" is not in mega.txt!");return 0;}
  bqinum=i;

  nowqi=qihao[bqinum];





  fin.Open(gofile, CFile::modeRead);
  
  int blk=0;
  
  
  CString jiangstr,bi100str,dstr;
  CString *filezu=new CString[m_wb+150];
  int zuxu=0;  
  
  
 
  


  if (k>0){
    for (i=0;i<k;i++){fin.ReadString(s);}
  }
  i=0;



  do{
    fin.ReadString(s);s=delern(s);

    if (s.GetLength()<10){continue;}
    if (s.Find("/")>=0){continue;}
    if (s.Find(":                 :")<0){i++;continue;}

    m=bqinum-i;

    if (m<0){ 


      blk++;
      nowqi=Cstr(atoi(nowqi)+1);
      wr=nowqi+":                 :";
      pos=s.ReverseFind(':');      
      wr=wr+s.Mid(pos+1);
      filezu[zuxu]=wr;
      i++;zuxu++;
      continue;

    }

    qinum++;
    nowqi=qihao[m];
    wr=nowqi+":"+datas[m]+":";
    pos=s.ReverseFind(':');
    s=s.Mid(pos+1);
    
    wr=wr+s+":";
    
    if (datas[m].Left(14).Find(s)>=0 && wei==1 || datas[m].Right(2)==s && wei==6){zhong="!";}    
    else {zhong="*";}

//MessageBox(datas[m]+"\r\nxma"+s+"\r\nzhong="+zhong);       


///////////////////////////////////////////

///////////////////////////////////////////
    if (zhong=="!"){
      if (duo){        
        twr="after";
        if (wei==1){
          twr+=padstrcisu(Cstr(yilou),3," ",0)+"\thead\t$\r\n";
        }
        else {
          twr+=padstrcisu(Cstr(yilou),3," ",0)+"\ttail\t$\r\n";
        }
        outgosta.Write(twr,twr.GetLength());
      }
     
      hit++;
      yilou-=m_mas;
     
    }
    else {
      yilou++;
      if (yilou>yiloumax){
        yiloumax=yilou;      
      }
      if (wei==1){
        if (zuida<yiloumax){zuida=yiloumax;}  
      }
      else {if (zuidae<yiloumax){zuidae=yiloumax;}}  
    }

   
    if (yilou<qinum*m_num/m_e/2){break;}

//////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////


    dstr="("+padstrcisu(Cstr(yilou),3,"0",0)+",";
    dstr+=padstrcisu(Cstr(qinum),3,"0",0)+","; 
    dstr+=padstrcisu(Cstr(yiloumax),3,"0",0)+",";   
    if (wei==1){
      dstr+=padstrcisu(Cstr(zuida),3,"0",0)+",";  
    }
    else {
      dstr+=padstrcisu(Cstr(zuidae),3,"0",0)+",";  
    } 
    dstr+=padstrcisu(Cstr(hit),3,"0",0)+")";  
  
/////////////////////////////////////////////
/////////////////////////////////////////////
    wr=wr+"#"+zhong+dstr+"["+padstrcisu(Cstr(qinum),4," ",0)+"]["+padstrcisu(Cstr(yilou),4," ",0)+"]\r\n";
    filezu[zuxu]=wr;
    i++;zuxu++;   

  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();//out.Close();
//MessageBox("3\r\nblk="+Cstr(blk));  
///////////////////////////////////////
//MessageBox("7");

  
  if (blk<1 || yilou<m_num/2){
    if (duo){   
      if (wei==1){
        twr="after"+padstrcisu(Cstr(yilou),3," ",0)+"\thead\tXXXXXX\r\n";
      }
      else {
        twr="after"+padstrcisu(Cstr(yilou),3," ",0)+"\ttail\tXXXXXX\r\n";
      }
      outgosta.Write(twr,twr.GetLength());
    }
    DeleteFile(gofile);
    return 0;
  }//没有预期，删除
///////////////////////////////////////////  
///////////////////////////////////////////  

  pos=gofile.ReverseFind('\\');
  s=gofile.Mid(pos+1);
  pos=s.ReverseFind(']');
  s=s.Left(pos+1);

  pos=s.ReverseFind('@');
  if (pos>=0){s=s.Mid(pos+1);}













//////////////////////////////////////
/////////////////////////////////////////






  t=Cstr(wei);
  t+=dstr;
  
  s=t+"@"+s;
//MessageBox(s);
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////

  DeleteFile(gofile);
  gofile=dirpath+s+"-"+qihao[0]+"r1go.txt";
  DWORD dwAttr= ::GetFileAttributes(gofile);
  if (dwAttr == 0xffffffff){
    out.Open(gofile,CFile::modeCreate|CFile::modeWrite);
    for (i=0;i<zuxu;i++){
       wr=filezu[i]+"\r\n";
       out.Write(wr,wr.GetLength());
    }
    out.Close();
  }
  //DeleteFile(tmpfile);
  delete[] filezu;

}


void CMy115backDlg::getmegabuycode(CString dirpath) 
{

  int filenum1=0,filenum6=0,i,j,k,bl,pos,i1,i6;
  bool success=true;
  CString outfile,s,t,rd1[33],rd7[1],b[4],wr,c;
  CString strDir=dirpath;
  CString szDir = strDir,buyfile,nake; 
  CFileFind ff; 
  szDir += "*.*"; 



  bool res = ff.FindFile(szDir);   
    
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)!="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")>=0){continue;}
       if (nake.Left(1)=="1"){filenum1++;}
       else {filenum6++;}
     }
  }
  ff.Close(); 
  if (filenum1<6 || filenum6==0){return;}
  
  CString * filename1=new CString [filenum1];
  CString * filename6=new CString [filenum6];
  res = ff.FindFile(szDir);   
  i1=0;i6=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)!="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")>=0){continue;}       
       if (nake.Left(1)=="1"){filename1[i1]=nake;i1++;}
       else {filename6[i6]=nake;i6++;}
     }
  }
  ff.Close(); 
  paixuztoa(filename1,filenum1);paixuztoa(filename6,filenum6);
 
  CString *zu;
  if (filenum1<33){zu=new CString [filenum1+1];}
  else {zu=new CString [34];filenum1=33;}
  int filenum=filenum1+1;
  k=0;
  for (i=0;i<filenum1;i++){
    zu[i]=filename1[i];
  }
  zu[filenum1]=filename6[0];


  CString *rd=new CString [filenum];
  CStdioFile *fin=new CStdioFile[filenum];
  CStdioFile out;
  outfile=dirpath+"h0000he[";
  t="";
  int fromsu=0;

  int yisum=0;
  for (i=0;i<filenum;i++){
    if (i<9 || i==filenum-1){yisum+=atoi(zu[i].Mid(2,3));}
  }
  if (yisum<m_qmas){return;}

  for (i=0;i<filenum;i++){
    fin[i].Open(dirpath+zu[i], CFile::modeRead);

    while (true){
      fin[i].ReadString(rd[i]);rd[i]=delern(rd[i]);
      if (rd[i].Find(":                 :")>0){break;}  
    }
    s=zu[i];
    pos=s.Find("[");
    s=s.Mid(pos+1);
    pos=s.Find("]");
    s=s.Left(pos);
    if (i<9 || i==filenum-1){fromsu+=atoi(s);}
    pos=rd[i].Find(":");
    s=rd[i].Left(pos);    
  }
  outfile+=padstrcisu(Cstr(fromsu),8,"0",0)+"-"+Cstr(yisum);
  outfile+="]"+s+".txt";

  out.Open(outfile,CFile::modeCreate|CFile::modeWrite);  
  bool rdflag=true;
  for (i=0;i<filenum;i++){rdflag=rdflag && (rd[i]!="0");}
  CString ma;
  while (rdflag){
    Split(rd[0],b,bl,":");
    wr=b[0]+":                 :";
    ma="";k=0;
    for (i=0;i<filenum1;i++){
      Split(rd[i],b,bl,":");
      c=b[2];
      if (ma.Find(c)<0){ma=ma+c+",";k++;}
      if (k>=5){break;}
    }
    if (k<5){
      success=false;
      break;
    }
    ma=ma.Left(ma.GetLength()-1);
    ma=padstrcisu(ma,14," ",1);
    ma=ma+"|";
    Split(rd[filenum1],b,bl,":");
    ma=ma+b[2]+"\r\n";
    wr+=ma;
    out.Write(wr,wr.GetLength());
    ////////////////////////////////////////////////////
    for (j=0;j<filenum;j++){
      if (fin[j].GetPosition()!=fin[j].GetLength()){
        fin[j].ReadString(rd[j]);rd[j]=delern(rd[j]);
      }
      else {rd[j]="0";}
    }
    rdflag=true;
    for (i=0;i<filenum;i++){rdflag=rdflag && (rd[i]!="0");}

    ///////////////////////////////////////////////////
  }  
    

  out.Close();
  for (j=0;j<filenum;j++){fin[j].Close();}
  delete[] filename1;delete[] filename6;delete[] zu;delete[] fin;;delete[] rd;
  if (! success){DeleteFile(outfile);} 
}


void CMy115backDlg::checkmegahccode(CString dirpath,CString qihao[],CString datas[],int ubound,CString buyfile) 
{

  CStdioFile fin,out;
  int i,j,pos,bl,bqinum,qinum,m;
  CString c,s,t,wr,b[13],bqi,nowqi,gofile,zhong;
  int yis[13];
  for (i=0;i<13;i++){yis[i]=0;}  
  
//////////////////////////////////////////////
  pos=buyfile.ReverseFind('\\');
  CString nake=buyfile.Mid(pos+1);
  CString mingstr="he",headstr="h";
  if (nake.Find("ahe")>0){mingstr="ahe";}
  CString myqi=nake;
  pos=nake.ReverseFind(']');  
  myqi=myqi.Mid(pos+1);
  pos=myqi.Find(".");
  myqi=myqi.Left(pos);



  if (myqi>qihao[0]){return;}


////////////////////////////////////////
  int yi;
  CString real;
  
  pos=nake.Find("[");
  real=nake.Mid(pos);
  pos=real.Find("]");
  real=real.Left(pos+1);
  pos=nake.Find("(");


  if (pos>=0){
    s=nake.Mid(pos+1);
    pos=s.Find(")");
    s=s.Left(pos);
    Split(s,b,bl,",");
    for (i=0;i<13;i++){yis[i]=atoi(b[i]);} 
  }
  qinum=yis[12];
///////////////////////////////////////////////





  CString tmpfile=dirpath+"tmp.txt";
  out.Open(tmpfile,CFile::modeCreate|CFile::modeWrite);



  fin.Open(buyfile, CFile::modeRead);
  fin.ReadString(s);s=delern(s);
  while (s.Left(1)=="/" || s.Find("[")>=0){
    fin.ReadString(s);s=delern(s);
  }



  CString yuan=s;
  pos=s.Find(':');
  bqi=s.Left(pos);

  fin.Close();


  if (atoi(bqi)>atoi(qihao[0])){return;}


  bool deng=false;
  for (i=0;i<ubound;i++){
    if (qihao[i]==bqi){deng=true;break;}
    if (atoi(qihao[i])<atoi(bqi)){break;}
  }
  if (! deng){MessageBox(buyfile+"\r\n"+bqi+" is not in mega.txt!");return;}
  bqinum=i;

  nowqi=qihao[bqinum];



  fin.Open(buyfile, CFile::modeRead);

  



  
  int blk=0;
  CString head,tail,xhead,xtail;
  i=0;
  int hnum;
  do{
    fin.ReadString(s);s=delern(s);

    if (s.GetLength()<10){continue;}
    if (s.Find("/")>=0){continue;}
    if (s.Find("[")>=0){continue;}
    m=bqinum-i;
    if (m<0){   
      blk++;
      nowqi=Cstr(atoi(nowqi)+1);
      wr=nowqi+":                 :";
      Split(s,b,bl,":");
      wr=wr+b[2];
      wr=wr+"\r\n";
      out.Write(wr,wr.GetLength());
      i++;
      continue;
    }

    qinum++;yis[12]++;
    nowqi=qihao[m];
    wr=nowqi+":"+datas[m]+":";



    pos=s.ReverseFind(':');
    s=s.Mid(pos+1);
    
    zhong="";
    wr=wr+s+":";



    head=datas[m].Left(14);tail=datas[m].Right(2);
    pos=s.Find("|");
    xhead=s.Left(pos);xtail=s.Mid(pos+1);
    Split(xhead,b,bl,",");

    hnum=0;
    for (j=0;j<=bl;j++){
      if (head.Find(b[j])>=0){        
        zhong=zhong+Cstr(j+1);        
        yis[j]=0;
        hnum++;
      }
      else {
        zhong+="*";  
        yis[j]++;
      }

      
    }
    if (bl<4){
      for (j=bl+1;j<5;j++){zhong+="#";yis[j]++;}
    }
    zhong+="|";
    if (tail==xtail){zhong+="!";yis[5]=0;yis[11]++;}
    else {zhong+="*";yis[5]++;}
    


    
    wr+=zhong+"["+padstrcisu(Cstr(qinum),4," ",0)+"]";
//MessageBox("wr="+wr);
    if (zhong.Left(5)=="12345"){wr+="!!!!!!!!!!!!!!!!!!!!!!!";}
    wr+="\r\n";
  
//MessageBox("wr="+wr);
    out.Write(wr,wr.GetLength());
    i++;   
    if (hnum==5){yis[6]++;}
    if (hnum>=4){yis[7]++;}
    if (hnum>=3){yis[8]++;}
    if (hnum>=2){yis[9]++;}
    if (hnum>=1){yis[10]++;}


  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();out.Close();




  DeleteFile(buyfile);
  CString ystr="(";yi=0;
  for (i=0;i<13;i++){
    if (i<6){yi+=yis[i];}
    ystr+=Cstr(yis[i])+",";
  }
  ystr=ystr.Left(ystr.GetLength()-1)+")";
  //gofile=dirpath+"h"+padstrcisu(Cstr(yi),4,"0",0)+mingstr+ystr+real+qihao[0]+".txt";
  gofile=dirpath+headstr+padstrcisu(Cstr(yi),4,"0",0)+mingstr+ystr+real+qihao[0]+".txt";

  if (blk>=1){CopyFile(tmpfile,gofile,0);}
  DeleteFile(tmpfile);


}




void CMy115backDlg::getmmdata(CString jigo,CString urlmode){
  CInternetSession session;
  CHttpFile *file = NULL;
  CStdioFile out;  
  //http://www.usamega.com/mega-millions-history.asp?p=1
  
  CString wr,strUrl,strHtml,strLine,c,s,timestr;
  int i,pos,k,n,ubound=m_num*26;
  CString  *ma=new CString [ubound];

  CString haobe="<td align=center nowrap><b>";
  CString timebe="drawing.asp?d=";
  int haobe_len=haobe.GetLength();
  int timebe_len=timebe.GetLength();

  out.Open(jigo,CFile::modeCreate|CFile::modeWrite);  
  k=0;

  for (i=1;i<=m_num;i++){

    if (tuichu>0){return;}
    DoEvents();GetDlgItem(idc_jingdu)->SetWindowText("处理页数="+Cstr(i-m_btui+1));
    strUrl=urlmode+Cstr(i);
    //MessageBox(strUrl);
    strHtml = "";
    try{
      file = (CHttpFile*)session.OpenURL(strUrl);
    }catch(CInternetException * m_pException){
      file = NULL;
      m_pException->m_dwError;
      m_pException->Delete();
      session.Close();
      MessageBox("CInternetException");
    }    
    if(file != NULL){while(file->ReadString(strLine) != NULL){strHtml += strLine;}}
    ////////////////////////////////////////////////
    if (i==1){
      pos=strHtml.Find("Last");
      s=strHtml.Mid(pos-10);
      pos=s.Find("=");
      s=s.Mid(pos+1);
      pos=s.Find("\"");
      n=atoi(s.Left(pos));
      if (m_num>n || m_num<1){m_num=n;}
    }
    ///////////////////////////////////////////////

    pos=strHtml.Find(">Jackpot<");
    if (pos<0){break;}
    strHtml=strHtml.Mid(pos+9);
    pos=strHtml.Find(">Search<");
    strHtml=strHtml.Left(pos);
    pos=strHtml.Find(timebe);

    while (pos>=0){
/////////////////////////////////////////
      strHtml=strHtml.Mid(pos+timebe_len);
      pos=strHtml.Find("\"");
      timestr=strHtml.Left(pos);
      strHtml=strHtml.Mid(pos+1);
      pos=strHtml.Find(haobe);
//////////////////////////////////////////
      strHtml=strHtml.Mid(pos+haobe_len);

      pos=strHtml.Find("<");
      c=strHtml.Left(pos);
      strHtml=strHtml.Mid(pos+1);
      c.Replace("&middot;",",");
      c.Replace(" ","");

      pos=strHtml.Find("<strong>");
      strHtml=strHtml.Mid(pos+8);
      pos=strHtml.Find("<");
      c=c+","+strHtml.Left(pos); 
       
      ma[k]=c+"\t"+timestr; 

      k++;    
      
      pos=strHtml.Find(timebe);      

    }//while (pos>=0){

  }//for (i=1;i<=m_num;i++){
  if (k==0){return;}
  for (i=0;i<k;i++){
    wr=Cstr(k-i-1+m_mas)+"\t"+ma[i]+"\r\n";
    out.Write(wr,wr.GetLength()); 
  }
  out.Close();
  delete[] ma;
}

void CMy115backDlg::OnButton40() 
{
  if (JieMian!=36){jiemian(36);return;} 
  setbutton(FALSE);
  UpdateData(TRUE); 

  DWORD dwAttr = ::GetFileAttributes(m_dfile); 
  if (dwAttr == 0xffffffff){
    setbutton(TRUE);MessageBox("请指定目录"); 
    return;
  }
   
  CString urlmode="http://www.usamega.com/mega-millions-history.asp?p=";
                 
  int pos=m_dfile.ReverseFind('\\');
  CString dirpath=m_dfile.Left(pos+1);
  CString jigo=dirpath+"mega.txt";
  getmmdata(jigo,urlmode);  
  MessageBox("程序结束!");setbutton(TRUE);
}



void CMy115backDlg::megafindtong(CString qihao[],CString datas[],small **data,CString dirpath,int ubound)
{
  

  
  int dispb=0,dispe=0,nowyi=0,hit,yilou,yiloumax;
  int m,allsu,wei=1;
  DWORD dwAttr;
  int allyi=0,i,k,zsu;
  GetDlgItem(idc_jingdu)->SetWindowText("");
  small btzu[75],btzu2[75];
  small btzue[15],btzu2e[15]; 
  int fromwei,back;
  
  CString c,qi,wr,gofile,s,real,dirstr;   
  CStdioFile out; 
  bool goflag,notgoflag,zhongflag,realflag;

  dirstr=dirpath.Right(2);
  dirstr=dirstr.Left(dirstr.GetLength()-1);
  dirstr=dirstr.Right(1);
  if (dirstr<"0" || dirstr>"9"){dirstr=Cstr(rand()%10);}

  int n;


  unsigned small *ma=new unsigned small [m_wb];
  
  unsigned small *maend=new unsigned small [m_wb];
  int *yi=new int[m_e];
  for (i=0;i<m_e;i++){
    yi[i]=(i+1)*m_num/m_e;
  }




  zsu=0;
  


  clock_t begin=clock(),end,t1=clock(),t2=clock(),hitbegin=clock();
  double duration,dur,dur1,hitdur=-1,lastdur;
  if (m_b<=0){m_b=1;}
  int max_mnum=500,min_mnum=360,checktime=360;
  int onedur=3600/m_b,beidur=2*onedur,halfdur=onedur/4;

  int shijian,hour,min,sec;

  while (true){

    if (wei<6){
      megabtzu(btzu,btzu2,back,fromwei);      
      
    }
    else {
      megaendbtzu(btzue,btzu2e,back,fromwei);   
    }
    real="";realflag=true;

//MessageBox("wei="+Cstr(wei)+"\r\nm_wb="+Cstr(m_wb)+"\r\nm_e="+Cstr(m_e)+"\r\nmwb="+Cstr(mwb)+"\r\nme="+Cstr(me)+"\r\nback="+Cstr(back)
//+"\r\nubound="+Cstr(ubound)

//);
    
    

    dur=(double)(clock()-t1) / CLOCKS_PER_SEC;
    dur1=(double)(clock()-t2) / CLOCKS_PER_SEC;
    if (dur>=5){
      t1=clock();
      end=clock();
      if (dur1>checktime){
        t2=clock();
        duration=(double)(end-begin) / CLOCKS_PER_SEC/onedur;
        lastdur=(clock()-hitbegin)/ CLOCKS_PER_SEC;
        if (zsu>duration && m_num<max_mnum && zsu>=1 && (hitdur<=onedur || hitdur==-1)){m_num++;}
        if (zsu<duration && m_num>min_mnum && zsu>=1 && (hitdur>=onedur || hitdur==-1)){m_num--;}
        if (lastdur>beidur && m_num>min_mnum ){m_num--;}
        if (hitdur<halfdur && lastdur<halfdur && m_num<max_mnum ){m_num++;}
      }
      
      if (tuichu==1){
        delete[] ma;delete[] maend;delete[] yi;              
        tuichu=0;
        return;
      }
    }
  
    if (wei<6){
      for (i=0;i<m_wb;i++){ 
        ma[i]=btzu[btzu2[data[i+back+rand()%20][fromwei]-1]]+1;     
        if (realflag && i>=m_e){
          real+=padstrcisu(Cstr(ma[i]),2,"0",0);
          if (real.GetLength()>=8){realflag=false;}
        }     
      } 
    } 
    else {
      for (i=0;i<m_wb;i++){ 
        maend[i]=btzue[btzu2e[data[i+back+rand()%20][fromwei]%15]]+1;  
        if (realflag && i>=m_e){
          real+=padstrcisu(Cstr(maend[i]),2,"0",0);
          if (real.GetLength()>=8){realflag=false;}
        }
        
      } 
    }  

//////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
    allsu=0;yilou=0;yiloumax=0;hit=0;   notgoflag=false;
    k=m_e-1;
    
    for (i=0;i<m_e;i++){      
      qi=qihao[k];
      k--;       
      m=m_e-1-i;
      if (wei<6){
        zhongflag=(data[m][0]==ma[i]);
        zhongflag=zhongflag || (data[m][1]==ma[i]);
        zhongflag=zhongflag || (data[m][2]==ma[i]);
        zhongflag=zhongflag || (data[m][3]==ma[i]);
        zhongflag=zhongflag || (data[m][4]==ma[i]);
      }
      else {
        zhongflag=(data[m][5]==maend[i]);
         
      }
      /////////////////////////////////////////
      if (zhongflag){
        yilou-=m_mas;hit++;
      }
      else {
        yilou++;        
        if (yilou>yiloumax){yiloumax=yilou;}
      }
      if (yilou<yi[i]){break;}
 
    

    }

  
    DoEvents();
    goflag=(yilou>=m_num);
    
    if (! goflag){continue;}
    n=i;      
    
/////////////////////////////////////////////////////////////////////

    i=1;
    if (wei<6){s="1";}
    else {s="6";}   
    s+="("+padstrcisu(Cstr(yilou),3,"0",0)+","
          +padstrcisu(Cstr(m_e),3,"0",0)+","   
          +padstrcisu(Cstr(yiloumax),3,"0",0)+","
          +padstrcisu(Cstr(yiloumax),3,"0",0)+","
          +padstrcisu(Cstr(hit),3,"0",0)+")";
         

    //real=padstrcisu(Cstr(rand()%1000),3,"0",0)+padstrcisu(Cstr(rand()%1000),3,"0",0)+dirstr;
    //real=Cstr(masum11)+Cstr(masum13);
    CString head=dirpath+s+qi+"["+real+"]";
    gofile=head+"go.txt";  
    dwAttr= ::GetFileAttributes(gofile);
    if (dwAttr != 0xffffffff){continue;}
 

 
    
    out.Open(gofile,CFile::modeCreate|CFile::modeWrite);

///////////////////////////////////////////////////////////
//MessageBox("n="+Cstr(n)+"\r\nme="+Cstr(me)+"\r\nmwb="+Cstr(mwb));
    for (i=n;i<m_wb;i++){      
      qi=Cstr(atoi(qi)+1);       
      wr=qi+":                 :";


      ////////////////////////////////////////
      if (wei<6){wr=wr+padstrcisu(Cstr(ma[i]),2,"0",0);}
      else {wr=wr+padstrcisu(Cstr(maend[i]),2,"0",0);}

      wr=wr+"\r\n";
      out.Write(wr,wr.GetLength());
      
      
    }

    out.Close();


    zsu++;
/////////////////////////////////////////////////////
    if (wei<6){if (dispb<yiloumax){dispb=yiloumax;}}
    else {if (dispe<yiloumax){dispe=yiloumax;}}
    DoEvents();
    shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
    hour=shijian/3600;
    n=shijian-hour*3600;
    min=n/60;
    sec=n-60*min;
    s="["+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec)+"]";

    GetDlgItem(idc_jingdu)->SetWindowText("find "+Cstr(zsu)+" now="+Cstr(yilou)
                  +" head="+Cstr(dispb)+" tail="+Cstr(dispe)+" should="+Cstr((int)duration)+" standard="+Cstr(m_num)+" time="+Cstr(shijian)+s );

    //GetDlgItem(idc_jingdu)->SetWindowText("find "+Cstr(zsu)+" nowyimax="+Cstr(yilou)+" head="+Cstr(dispb)+" tail="+Cstr(dispe));
    if (tuichu==1){
      delete[] ma; delete[] maend; delete[] yi;   
      tuichu=0;
      return;
    }
//MessageBox("wei="+Cstr(wei)+"\r\nme="+Cstr(me)+"\r\nbound1m="+Cstr(bound1m)+"\r\nbound2m="+Cstr(bound2m)+"\r\nmnum="+Cstr(mnum));
   
    wei++; 
    if (wei==7){wei=1;}
 

  }

}











void CMy115backDlg::getmegahe(CString dirpath) 
{


  int filenum=0,i,j,k,bl,pos;
  CString outfile,s,t,b[13],wr;
  CString strDir=dirpath;
  CString szDir = strDir,buyfile,nake; 
  CFileFind ff; 
  szDir += "*.*"; 
  CStdioFile fin,out;


  bool res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)=="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")<0){continue;}
       if (nake.Find("(")<0){continue;}
       if (atoi(nake.Mid(1,4))==0){continue;}
       filenum++;
     }
  }
  ff.Close(); 

  if (filenum==0){return;}
  CString * filename=new CString [filenum];  
/////////////////////////////////////

////////////////////////////////////////////
  res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)=="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")<0){continue;}
       if (nake.Find("(")<0){continue;}
       if (atoi(nake.Mid(1,4))==0){continue;}
       filename[i]=nake;
       i++;
     }
  }
  ff.Close(); 
//////////////////////////////////////////  


  int mwb=m_wb+501;
  CString *qi=new CString [mwb];
  i=0;
  fin.Open(dirpath+filename[0], CFile::modeRead);
  do{
    fin.ReadString(s);s=delern(s); 
    if (s.Find(":                 :")<0){continue;}
    pos=s.Find(":");
    qi[i]=s.Left(pos);
    i++;
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();

//////////////////////////////////////////
  int qiannum=filenum*5,hounum=filenum;
  int **ma=new int *[qiannum];
  for (i=0;i<qiannum;i++){
    ma[i]=new int [mwb];
    for (j=0;j<mwb;j++){
      ma[i][j]=-1;
    }
  } 

  int **maend=new int *[hounum];
  for (i=0;i<hounum;i++){
    maend[i]=new int [mwb];
    for (j=0;j<mwb;j++){
      maend[i][j]=-1;
    }
  } 
  
///////////////////////////////////////////
//MessageBox("4");



  for (i=0;i<filenum;i++){    
    nake=filename[i];

    pos=nake.Find("(");
    s=nake.Mid(pos+1);

    pos=s.Find(")");
    s=s.Left(pos);
    Split(s,b,bl,",");


    for (j=0;j<5;j++){ma[i*5+j][0]=atoi(b[j]);}
    maend[i][0]=atoi(b[5]);
    fin.Open(dirpath+filename[i], CFile::modeRead);

    k=1;

    do{

      fin.ReadString(s);s=delern(s); 

      if (s.Find(":                 :")<0){continue;}

      pos=s.ReverseFind(':');
      s=s.Mid(pos+1);

      for (j=0;j<5;j++){
        ma[i*5+j][k]=atoi(s.Mid(3*j,2));
      }
      
      maend[i][k]=atoi(s.Right(2));
      k++;

    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();

  }
  

  int bound=mwb;

//MessageBox("5");

  
  for (i=0;i<qiannum;i++){
  for (j=0;j<mwb;j++){
    if (ma[i][j]==-1){k=bound;}
  }}
  for (i=0;i<hounum;i++){
  for (j=0;j<mwb;j++){
    if (maend[i][j]==-1){k=bound;}
  }}


  if (bound<=1){return;}
  
  
  paimasubiao(ma,0,qiannum-1,0,bound);
  paimasubiao(maend,0,hounum-1,0,bound);


  int yisum=ma[0][0];
  k=1;
  CString ystr=Cstr(ma[0][0])+",";
  bool you;
  for (i=1;i<qiannum;i++){
    you=false;
    for (j=0;j<i;j++){
      if (ma[j][1]==ma[i][1]){you=true;break;}
    }
    if (! you){yisum+=ma[j][0];k++;ystr+=Cstr(ma[j][0])+",";}
    if (k>=5){break;}
  }
  yisum+=maend[0][0];
  ystr+=Cstr(maend[0][0]);

  CString ming="h"+padstrcisu(Cstr(yisum),4,"0",0)+"ahe("+ystr+")[$]"+qi[0]+".txt";;



  s=padstrcisu(Cstr(rand()%100000),5,"0",0)+"-"+Cstr(yisum);

  CString name=ming;
  name.Replace("$",s);
  outfile=dirpath+name;
  DWORD dwAttr;
  while (true){
    dwAttr  = ::GetFileAttributes(outfile); 
    if (dwAttr == 0xffffffff){break;}
    name=ming;
    s=padstrcisu(Cstr(rand()%100000),5,"0",0)+"-"+Cstr(yisum);
    name.Replace("$",s);
    outfile=dirpath+name;
  }



    
  out.Open(outfile,CFile::modeCreate|CFile::modeWrite);  
  CString mastr;
  bool brflag;

  for (i=1;i<bound;i++){
    if (qi[i-1].GetLength()==0){break;}
    wr=qi[i-1]+":                 :";
    mastr="";
/////////////////////////////////////////////
    brflag=false;k=0;
    for (j=0;j<qiannum;j++){
      if (ma[j][i]==-1){
        brflag=true;
        break;
      }
      s=padstrcisu(Cstr(ma[j][i]),2,"0",0);
      if (mastr.Find(s)<0){
        mastr+=s+",";
        k++;
        if (k>=5){break;}
      }      
    }
    if (brflag){break;}
    mastr=mastr.Left(mastr.GetLength()-1)+"|"+padstrcisu(Cstr(maend[0][i]),2,"0",0)+"\r\n";
    wr+=mastr;
    out.Write(wr,wr.GetLength());
  }
  out.Close();
  for (i=0;i<qiannum;i++){   
    delete[] ma[i];
  }
  for (i=0;i<hounum;i++){   
    delete[] maend[i];
  }
  delete[] ma;delete[] maend;
  delete[] qi;

  delete[] filename;
}



void CMy115backDlg::getqxche(CString dirpath) 
{

  int filenum=0,i,j,k,bl,pos;
  CString outfile,s,t,b[10],wr;
  CString strDir=dirpath;
  CString szDir = strDir,buyfile,nake; 
  CFileFind ff; 
  szDir += "*.*"; 
  CStdioFile fin,out;


  bool res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)=="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")<0){continue;}
       if (nake.Find("(")<0){continue;}
       if (nake.Left(1)!="h"){if (atoi(nake.Left(4))==0){continue;}}
       else {if (atoi(nake.Mid(1,4))==0){continue;}}
       filenum++;
     }
  }
  ff.Close(); 

  if (filenum==0){return;}
  CString * filename=new CString [filenum];  
/////////////////////////////////////

////////////////////////////////////////////
  res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)=="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")<0){continue;}
       if (nake.Find("(")<0){continue;}
       if (nake.Left(1)!="h"){if (atoi(nake.Left(4))==0){continue;}}
       else {if (atoi(nake.Mid(1,4))==0){continue;}}
       filename[i]=nake;
       i++;
     }
  }
  ff.Close(); 
//////////////////////////////////////////  
  int mwb=m_wb+501;
  CString *qi=new CString [mwb];
  i=0;
  fin.Open(dirpath+filename[0], CFile::modeRead);
  do{
    fin.ReadString(s);s=delern(s); 
    if (s.Find(":       :")<0){continue;}
    qi[i]=s.Left(5);
    i++;
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();
//MessageBox(qi[0]);
//////////////////////////////////////////
  int ***ma=new int **[7];
  for (i=0;i<7;i++){
    ma[i]=new int *[filenum];
    for (j=0;j<filenum;j++){
      ma[i][j]=new int [mwb];
      for (k=0;k<mwb;k++){ma[i][j][k]=-1;}
    }
  } 
///////////////////////////////////////////


  for (i=0;i<filenum;i++){    
    nake=filename[i];

    pos=nake.Find("(");
    s=nake.Mid(pos+1);

    pos=s.Find(")");
    s=s.Left(pos);
    Split(s,b,bl,",");

    for (j=0;j<7;j++){ma[j][i][0]=atoi(b[j]);}
    fin.Open(dirpath+filename[i], CFile::modeRead);

    k=1;

    do{

      fin.ReadString(s);s=delern(s); 

      if (s.Find(":       :")<0){continue;}

      pos=s.ReverseFind(':');
      s=s.Mid(pos+1);

      for (j=0;j<7;j++){

        ma[j][i][k]=atoi(s.Mid(j,1));

      }
      k++;

    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();

  }
  

  int bound=mwb;
  for (i=0;i<7;i++){
  for (j=0;j<filenum;j++){
  for (k=0;k<mwb;k++){
    if (ma[i][j][k]==-1){k=bound;}
  }}}
  if (bound<=1){return;}
  
  for (i=0;i<7;i++){
    paimasubiao(ma[i],0,filenum-1,0,bound);
  }

  int yisum=ma[0][0][0]+ma[1][0][0]+ma[2][0][0]+ma[3][0][0]+ma[4][0][0]+ma[5][0][0]+ma[6][0][0];
  CString ming="h"+padstrcisu(Cstr(yisum),4,"0",0)+"ahe(";
  for (i=0;i<7;i++){
    ming+=Cstr(ma[i][0][0])+",";
  }
  ming=ming.Left(ming.GetLength()-1)+")[$]"+qi[0]+".txt";
  s=padstrcisu(Cstr(rand()%100000),5,"0",0)+"-"+Cstr(yisum);

  CString name=ming;
  name.Replace("$",s);
  outfile=dirpath+name;
  DWORD dwAttr;
  while (true){
    dwAttr  = ::GetFileAttributes(outfile); 
    if (dwAttr == 0xffffffff){break;}
    name=ming;
    s=padstrcisu(Cstr(rand()%100000),5,"0",0)+"-"+Cstr(yisum);
    name.Replace("$",s);
    outfile=dirpath+name;
  }
    
  out.Open(outfile,CFile::modeCreate|CFile::modeWrite);  
//MessageBox("bound="+Cstr(bound));  
  for (i=1;i<bound;i++){
    if (qi[i-1].GetLength()==0){break;}
    if (ma[0][0][i]==-1){break;}
    if (ma[1][0][i]==-1){break;}
    if (ma[2][0][i]==-1){break;}
    if (ma[3][0][i]==-1){break;}
    if (ma[4][0][i]==-1){break;}
    if (ma[5][0][i]==-1){break;}
    if (ma[6][0][i]==-1){break;}

    wr=qi[i-1]+":       :";
//MessageBox("wr="+wr);
    for (j=0;j<7;j++){      
      wr+=Cstr(ma[j][0][i]);
    }
    wr+="\r\n";
//MessageBox("wr="+wr);
    out.Write(wr,wr.GetLength());
  }
  out.Close();
  for (i=0;i<7;i++){
    for (j=0;j<filenum;j++){
      delete[] ma[i][j];
    }
    delete[] ma[i];
  }
  delete[] ma;
  delete[] qi;

  delete[] filename;
}





















int CMy115backDlg::getcansu(CString dirpath,int type) 
{
   CStdioFile fin;
   CString s;
   DWORD dwAttr= ::GetFileAttributes(dirpath+"zcansu.txt"); 
   if (dwAttr != 0xffffffff){
     fin.Open(dirpath+"zcansu.txt", CFile::modeRead);
     fin.ReadString(s);s=delern(s);
     return atoi(s);
   }
   switch(type){
     case 1:
       return 999;//dlc
       break;
     case 2:
       return 12000;//ssq
       break;
     case 3:
       return 3000;//mega       
   }
}













void CMy115backDlg::joindlcsrcdata(CString datafile) 
{
   CStdioFile fin;
   int i,n,bl;
   CString s,old,b[6],wr;
   bool bianflag=false;
   fin.Open(datafile, CFile::modeRead);  
   old="";n=0;
   do{
      fin.ReadString(s);s=delern(s);
      n++;
      s=s.Left(6);
      if (s!=old){old=s;}
      else {bianflag=true;}      
   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   if (! bianflag || n<=1){return;}
   CStdioFile out; 
   
   
   
   CString *line=new CString [n];
   fin.Open(datafile, CFile::modeRead);  
   i=0;   
   do{
      fin.ReadString(s);s=delern(s);
      line[i]=s;
      i++;
   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
//MessageBox(line[0]+"\r\n"+line[1]);
   CString beginqi,endqi,tbeginqi,tendqi;
   int qisu,z5,z4,z3,tqisu,tz5,tz4,tz3;
 
   Split(line[0],b,bl,"\t");
   beginqi=b[0].Left(8);
   endqi=b[0].Right(8);
   z5=atoi(b[1]);
   z4=atoi(b[2]);
   z3=atoi(b[3]);
   out.Open(datafile,CFile::modeCreate|CFile::modeWrite); 
   for (i=1;i<n;i++){
     Split(line[i],b,bl,"\t");
     tbeginqi=b[0].Left(8);
     tendqi=b[0].Right(8);
     tz5=atoi(b[1]);
     tz4=atoi(b[2]);
     tz3=atoi(b[3]);
     if (tbeginqi.Left(6)==beginqi.Left(6)){
       endqi=tendqi;
       //qisu+=tqisu;
       //zsu+=tzsu;
       z5+=tz5;
       z4+=tz4;
       z3+=tz3;       
       if (i==n-1){
         wr=beginqi+"-"+endqi+'\t'+Cstr(z5)+'\t'+Cstr(z4)+'\t'+Cstr(z3)+"\r\n";
         out.Write(wr,wr.GetLength());break;
       }
       else {continue;}
     }
     wr=beginqi+"-"+endqi+'\t'+Cstr(z5)+'\t'+Cstr(z4)+'\t'+Cstr(z3)+"\r\n";
     out.Write(wr,wr.GetLength());
     beginqi=tbeginqi;
     endqi=tendqi;
     qisu=tqisu;
     z5=tz5;z4=tz4;z3=tz3;
     if (i==n-1){
       wr=beginqi+"-"+endqi+'\t'+Cstr(z5)+'\t'+Cstr(z4)+'\t'+Cstr(z3)+"\r\n";
       out.Write(wr,wr.GetLength());break;
     }
   }  
   out.Close(); 
   delete[] line;
}











//////////////////////////////


void CMy115backDlg::checkssqbuyfile(CString dirpath,CString qihao[],CString datas[],int ubound,CString tjsrc)
{


  int filenum=0,i,j,pos,n,m,zi,su[8],mysu;
 
  
  CString outfile,s,c;
  CString strDir=dirpath,head,mahead,real;
  CString szDir = strDir,buyfile,nake,myqi,jigo,ma,zhong,wr,tjfile; 
  CFileFind ff; 
  szDir += "*.*"; 
  CStdioFile fin,out,outtj;


  bool res = ff.FindFile(szDir);  
  bool you,tailflag; 
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("(")>=0){DeleteFile(buyfile);continue;}
       if (nake.Mid(10,5)>qihao[0]){continue;}
       filenum++;
     }
  }
  ff.Close(); 

  if (filenum==0){return;}
  CString * filename=new CString [filenum];  



////////////////////////////////////////////
  res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);   
       if (nake.Mid(10,5)>qihao[0]){continue;}
       filename[i]=nake;
       i++;
     }
  }
  ff.Close(); 


  for (i=0;i<filenum;i++){
    s=filename[i];

    myqi=s.Mid(10,5);head=s.Left(10);
    you=false;
    for (j=0;j<ubound;j++){
      if (myqi==qihao[j]){you=true;break;}
    }
    if (! you){continue;}
    mysu=0;
    ma=datas[j];mahead=ma.Left(17);
    tjfile=tjsrc+s.Mid(4,5)+".txt";
    outtj.Open(tjfile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate); 
    outtj.SeekToEnd(); 

    fin.Open(dirpath+filename[i], CFile::modeRead);    
    n=0;
    do{
      fin.ReadString(s);s=delern(s);
      pos=s.Find("#");
      if (pos>=0){break;}
      n++;
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
    if (n==0){continue;}
    
    CString * zu=new CString [n];
    fin.Open(dirpath+filename[i], CFile::modeRead);    
   
    
    zi=0;
    for (j=0;j<8;j++){su[j]=0;}
    do{
      fin.ReadString(s);s=delern(s);
      m=0;
      zhong="";
      for (j=0;j<17;j=j+3){
        c=s.Mid(j,2);
        if (mahead.Find(c)>=0){
          m++;zhong+=Cstr(j/3+1);
        }
        else {zhong+="*";}
      }
      zhong+="|";
      if (ma.Right(2)==s.Right(2)){
        zhong+="!";su[6]++;tailflag=true;
        if (m==6){su[7]++;zhong+="$$$$$";}
      }
      else {zhong+="*";tailflag=false;}    

      if (m>0){su[m-1]++;} 
      zu[zi]=s+"#"+ma+"#"+zhong;        
      zi++;
      if (m==3 && tailflag || m>=4){mysu+=2;}
      else {
         if (m<3 && tailflag){mysu++;}
      }
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
    DeleteFile(dirpath+filename[i]);
    
    
    real="";
    for (j=0;j<8;j++){real+=Cstr(su[j])+",";}
    real=real.Left(real.GetLength()-1);
    real="("+real+")";
    if (su[7]>0){real+="!!!!!";}
    jigo=dirpath+head+myqi+"-"+Cstr(n)+real+".txt";
    out.Open(jigo,CFile::modeCreate|CFile::modeWrite);
    for (j=0;j<n;j++){
      wr=zu[j]+"\r\n";
      out.Write(wr,wr.GetLength());
    }
    out.Close();delete[] zu;out.Flush();
//MessageBox("stop");
//////////////////////////////////////////////
    
    wr=myqi+"\t"+padstrcisu(Cstr(mysu),3," ",0)+"\r\n";
    outtj.Write(wr,wr.GetLength());outtj.Close();
//////////////////////////////////////////////

  }


  delete[] filename;
}


void CMy115backDlg::ssqmegarecords(CString srcfile,CString **records,CStdioFile &outz) 
{
  const int ZUSU=20;
  CStdioFile fin;
  int pos,i,j,bl,zsu;
  CString s,wr,b[5],qi;

  pos=srcfile.ReverseFind('\\');
  CString zuming=srcfile.Mid(pos+1);
  zuming=zuming.Left(zuming.GetLength()-4); 
  fin.Open(srcfile, CFile::modeRead);  
  i=0;   
  while(fin.ReadString(s)){
    i++;
  }
  fin.Close();
  if (i==0){return;}
  int ubound=i;
  CString *nowrecords=new CString [ubound];
  fin.Open(srcfile, CFile::modeRead);  
  i=0;   
  while(fin.ReadString(s)){
    s=delern(s);
    nowrecords[i]=s;
    i++;
  }
  fin.Close();


  
  bool wrflag=false;
  for (i=ZUSU;i>=1;i--){
    if (ubound<i){continue;}
    zsu=0;
    for (j=ubound-1;j>=ubound-i;j--){
      s=nowrecords[j];
      Split(s,b,bl,"\t");
      zsu+=atoi(b[1]);
    }
   
    if (records[i-1][0]=="0"){
      records[i-1][0]=zuming;
      records[i-1][1]=Cstr(zsu);
    }
    else {
      if (zsu<atoi(records[i-1][1])){
        records[i-1][0]=zuming;
        records[i-1][1]=Cstr(zsu);
      }
    }  
    /////////////////////////////////////////////////
    if (i<m_su){continue;}
    if (wrflag){continue;}
    if (zsu>0){continue;}    
    qi=nowrecords[ubound-1];
    pos=qi.Find("\t");
    qi=qi.Left(pos);    
    wr=qi+"\t"+zuming+"\t"+padstrcisu(Cstr(i),2," ",0)+"\r\n";
    outz.Write(wr,wr.GetLength());
    wrflag=true;
   
    //////////////////////////////////////////////////  
  }

}


void CMy115backDlg::copybuyfile(CString dirpath,int wei) 
{
   CString buypath=dirpath+"buy\\";
   CString copymodefile=dirpath+"copyhao.txt";
   CString haostr,s;
   CStdioFile fin;
   int pos;

   DWORD dwAttr = ::GetFileAttributes(copymodefile); 
   if (dwAttr == 0xffffffff){haostr=",0,";} 
   else {
     haostr=",";
     fin.Open(copymodefile, CFile::modeRead);
     do{
       fin.ReadString(s);s=delern(s);
//////////////////////////////////////
       pos=s.Find("\t");
       if (pos>=0){
         s=s.Mid(pos+1);
         pos=s.Find("\t");
         if (pos>=0){s=s.Left(pos);}
         s=Cstr(atoi(s));
       }
////////////////////////////////////////

       haostr+=s+",";
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();
   }

   CString szDir = buypath,buyfile,nake; 
   CFileFind ff; 
   szDir += "*.*"; 
   
   bool res = ff.FindFile(szDir);   
    
   while( res ) 
   { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 

     if(!ff.IsDirectory() && !ff.IsDots()){
       pos=buyfile.ReverseFind('\\'); 
       nake=buyfile.Mid(pos+1);   
       if (nake.Find("(")>=0){continue;}
       s=","+Cstr(atoi(nake.Mid(4,wei)))+",";
       if (haostr.Find(s)>=0){
         CopyFile(buyfile,dirpath+nake,0);  
       }
     } 
   }
   ff.Close();  
}


//////////////////////////////
void CMy115backDlg::getmegabuyfile(CString dirpath) 
{

  int ZSU=getcansu(dirpath,3);

  int filenum=0,i,i1,j,k,pos,kasc,kdes,znum;

  int buynum=m_we;
  
  CString *buyzuasc=new CString [buynum];
  CString *buyzudes=new CString [buynum];


  CString outfile,s,s1,s2,t1,t2,c;
  CString strDir=dirpath;
  CString szDir = strDir,buyfile,nake,fileasc,filedes,fileasca,filedesa,wr; 
  CFileFind ff; 
  szDir += "*.*"; 
  CStdioFile fin,out;
////////////////////////////////////////////////////
  CString buypath;    
  buypath=dirpath+"buy\\";
  if(_access(buypath, 0) == -1){_mkdir(buypath);} 
  

//////////////////////////////////////////////////////

  bool res = ff.FindFile(szDir);  
  bool you,bflag,eflag; 
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)=="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")<0){continue;}    
       if (nake.Find("head")>=0){continue;}   
       filenum++;
     }
  }
  ff.Close(); 

  if (filenum==0){return;}
  CString * filename=new CString [filenum];  
  CString *ybuyzu=new CString [filenum]; 

/////////////////////////////////////

////////////////////////////////////////////
  res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       if (buyfile.Right(6)=="go.txt"){continue;}
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("he")<0){continue;}       
       if (nake.Find("head")>=0){continue;}   
       filename[i]=nake;
       i++;
     }
  }
  ff.Close(); 
  CString qi;


//////////顺序文件//////////////////////////////
//////////////////////////////////////////  
  paixuatoz(filename,filenum);   
  fin.Open(dirpath+filename[0], CFile::modeRead);
  do{
    fin.ReadString(s);s=delern(s); 
    if (s.Find(":                 :")<0){continue;}
    pos=s.Find(":");
    qi=s.Left(pos);
    break;
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();

//////////////////////////////////////////
  
////////////////////////////////////////////
  kasc=0;
  for (i=0;i<filenum;i++){
    fin.Open(dirpath+filename[i], CFile::modeRead);
    do{
      fin.ReadString(s);s=delern(s); 
      if (s.Find(":                 :")<0){continue;}
      pos=s.ReverseFind(':');
      s=s.Mid(pos+1);
      s.Replace("|",":");
      break;

    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
    you=false;
    if (kasc>0){      
      t1=s.Right(2);
      s1=s.Left(14);
      for (j=0;j<kasc;j++){
        t2=buyzuasc[j].Right(2);
        if (t1==t2){eflag=true;}
        else {eflag=false;}
        s2=buyzuasc[j].Left(14);
        bflag=true;
        for (i1=0;i1<5;i1++){
          c=s1.Mid(i1*3,2);
          if (s2.Find(c)<0){
            bflag=false;break;
          }
        }
        if (bflag && eflag){you=true;break;}            
      }
    } 
    if (! you){
      buyzuasc[kasc]=s; 
      kasc++;
      if (kasc>=buynum){break;}
    }
  }
  out.Close();
//////////////////////////////////////////////////
  if (kasc>0){ 

    fileasc=dirpath+"buyasc-"+Cstr(kasc)+".txt";
    out.Open(fileasc,CFile::modeCreate|CFile::modeWrite);
    for (j=0;j<kasc;j++){
      wr=buyzuasc[j]+"\r\n";
      out.Write(wr,wr.GetLength()); 
    }
    out.Close();
  }////////////////
//////////////////////////////////////////////////


//////////反序文件//////////////////////////////
//////////////////////////////////////////  
  paixuztoa(filename,filenum);  
  fin.Open(dirpath+filename[0], CFile::modeRead);
  do{
    fin.ReadString(s);s=delern(s); 
    if (s.Find(":                 :")<0){continue;}
    pos=s.Find(":");
    qi=s.Left(pos);
    break;
  }
  while (fin.GetPosition()!=fin.GetLength());
  fin.Close();

//////////////////////////////////////////
  
////////////////////////////////////////////
  kdes=0;
  for (i=0;i<filenum;i++){
    fin.Open(dirpath+filename[i], CFile::modeRead);
    do{
      fin.ReadString(s);s=delern(s); 
      if (s.Find(":                 :")<0){continue;}
      pos=s.ReverseFind(':');
      s=s.Mid(pos+1);
      s.Replace("|",":");
      break;

    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
    you=false;
    if (kdes>0){      
      t1=s.Right(2);
      s1=s.Left(14);
      for (j=0;j<kdes;j++){
        t2=buyzudes[j].Right(2);
        if (t1==t2){eflag=true;}
        else {eflag=false;}
        s2=buyzudes[j].Left(14);
        bflag=true;
        for (i1=0;i1<5;i1++){
          c=s1.Mid(i1*3,2);
          if (s2.Find(c)<0){
            bflag=false;break;
          }
        }
        if (bflag && eflag){you=true;break;}            
      }
    } 
    if (! you){
      buyzudes[kdes]=s; 
      kdes++;
      if (kdes>=buynum){break;}
    }
  }
  out.Close();
//////////////////////////////////////////////////
  if (kdes>0){ 

    filedes=dirpath+"buydes-"+Cstr(kdes)+".txt";
    out.Open(filedes,CFile::modeCreate|CFile::modeWrite);
    for (j=0;j<kdes;j++){
      wr=buyzudes[j]+"\r\n";
      out.Write(wr,wr.GetLength()); 
    }
    out.Close();
  }////////////////
//////////////////////////////////////////////////

//////////混合文件//////////////////////////////
////////////////////////////////////////// 
  if (m_btui<=0){m_btui=1;}
  if (m_etui<=0){m_etui=1;}
  if (m_btui>kasc){m_btui=kasc;}
  if (m_etui>kdes){m_etui=kdes;}

  CString *hunhe=new CString [m_btui+m_etui+1];
  for (i=0;i<ZSU;i++){

    znum=0;
    for (j=0;j<m_btui;j++){
      s=buyzuasc[j];
      you=false;
      if (znum>0){
        for (k=0;k<znum-1;k++){
          if (islotterdeng(s,hunhe[k],0)){you=true;break;}
        }
      }
      if (! you){hunhe[znum]=s;znum++;}
    }

    for (j=0;j<m_etui;j++){
      s=buyzudes[j];
      you=false;
      if (znum>0){
        for (k=0;k<znum-1;k++){
          if (islotterdeng(s,hunhe[k],0)){you=true;break;}
        }
      }
      if (! you){hunhe[znum]=s;znum++;}
    }
    if (m_bfile.GetLength()>=17){
      s=m_bfile;
      you=false;
      for (k=0;k<znum-1;k++){
        if (islotterdeng(s,hunhe[k],0)){you=true;break;}
      }
      if (! you){hunhe[znum]=s;znum++;}
    }

    if (i>0){
      megatoubianrand(hunhe,znum);     
    }

    outfile=buypath+"buy["+padstrcisu(Cstr(i),4,"0",0)+"]"+qi+"-"+Cstr(znum)+"["+Cstr(m_tuib)+"-"+Cstr(m_tuie)+"].txt";

    out.Open(outfile,CFile::modeCreate|CFile::modeWrite);
    for (j=0;j<znum;j++){
      s=hunhe[j]+"\r\n"; 
      out.Write(s,s.GetLength()); 
    }

    out.Close();
  
  }



  delete[] filename;
  delete[] buyzuasc;delete[] buyzudes;delete[] hunhe;
}


void CMy115backDlg::checkmegabuyfile(CString dirpath,CString qihao[],CString datas[],int ubound,CString tjsrc)
{


  int filenum=0,i,j,pos,n,m,zi,su[7],mysu;
 
  
  CString outfile,s,c,t;
  CString strDir=dirpath,head,mahead,real;
  CString szDir = strDir,buyfile,nake,myqi,jigo,ma,zhong,wr,tjfile; 
  CFileFind ff; 
  szDir += "*.*"; 
  CStdioFile fin,out,outtj;


  bool res = ff.FindFile(szDir);  
  bool you,tailflag; 
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);
       if (nake.Find("(")>=0){DeleteFile(buyfile);continue;}
       s=nake.Mid(9);
       pos=s.Find("-");

       if (s.Left(pos)>qihao[0]){continue;}
       filenum++;
     }
  }
  ff.Close(); 

  if (filenum==0){return;}
  CString * filename=new CString [filenum];  



////////////////////////////////////////////
  res = ff.FindFile(szDir);   
  i=0;
  while( res )
  { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(!ff.IsDirectory() && !ff.IsDots()){
       pos=buyfile.ReverseFind('\\');
       nake=buyfile.Mid(pos+1);   
       s=nake.Mid(9);
       pos=s.Find("-");
       if (s.Left(pos)>qihao[0]){continue;}
       filename[i]=nake;
       i++;
     }
  }
  ff.Close(); 


  for (i=0;i<filenum;i++){
    s=filename[i];

    t=s.Mid(9);
    pos=t.Find("-");
    myqi=t.Left(pos);   

    head=s.Left(9);
    you=false;
    for (j=0;j<ubound;j++){
      if (myqi==qihao[j]){you=true;break;}
    }
    if (! you){continue;}
    mysu=0;
    ma=datas[j];mahead=ma.Left(14);
    tjfile=tjsrc+s.Mid(4,4)+".txt";
    outtj.Open(tjfile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate); 
    outtj.SeekToEnd(); 

    fin.Open(dirpath+filename[i], CFile::modeRead);    
    n=0;
    do{
      fin.ReadString(s);s=delern(s);
      pos=s.Find("#");
      if (pos>=0){break;}
      n++;
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
    if (n==0){continue;}
    
    CString * zu=new CString [n];
    fin.Open(dirpath+filename[i], CFile::modeRead);    
   
    
    zi=0;
    for (j=0;j<7;j++){su[j]=0;}
    do{
      fin.ReadString(s);s=delern(s);
      m=0;
      zhong="";
      for (j=0;j<14;j=j+3){
        c=s.Mid(j,2);
        if (mahead.Find(c)>=0){
          m++;zhong+=Cstr(j/3+1);
        }
        else {zhong+="*";}
      }
      zhong+="|";
      if (ma.Right(2)==s.Right(2)){
        zhong+="!";su[5]++;tailflag=true;
        if (m==5){su[6]++;zhong+="$$$$$";}
      }
      else {zhong+="*";tailflag=false;}    

      if (m>0){su[m-1]++;} 
      zu[zi]=s+"#"+ma+"#"+zhong;        
      zi++;
      if (m>=1 && tailflag || m>=3){mysu+=2;}
      else {
         if (m==0 && tailflag){mysu++;}
      }
    }
    while (fin.GetPosition()!=fin.GetLength());
    fin.Close();
    DeleteFile(dirpath+filename[i]);
    
    
    real="";
    for (j=0;j<7;j++){real+=Cstr(su[j])+",";}
    real=real.Left(real.GetLength()-1);
    real="("+real+")";
    if (su[6]>0){real+="!!!!!";}
    jigo=dirpath+head+myqi+"-"+Cstr(n)+real+".txt";
    out.Open(jigo,CFile::modeCreate|CFile::modeWrite);
    for (j=0;j<n;j++){
      wr=zu[j]+"\r\n";
      out.Write(wr,wr.GetLength());
    }
    out.Close();delete[] zu;out.Flush();
//MessageBox("stop");
//////////////////////////////////////////////
    
    wr=myqi+"\t"+padstrcisu(Cstr(mysu),3," ",0)+"\r\n";
    outtj.Write(wr,wr.GetLength());outtj.Close();
//////////////////////////////////////////////

  }


  delete[] filename;
}






//////////////////////////////////////

void CMy115backDlg::ssqfufen(CString head,CString tail,CString touzu[],int &k)
{

  CString b[33];  
  int i1,i2,i3,i4,i5,i6,n;     
  Split(head, b, n, ",");  for (i1=0;i1<=n;i1++){
  for (i2=i1+1;i2<=n;i2++){
  for (i3=i2+1;i3<=n;i3++){
  for (i4=i3+1;i4<=n;i4++){
  for (i5=i4+1;i5<=n;i5++){
  for (i6=i5+1;i6<=n;i6++){
    touzu[k]=b[i1]+","+b[i2]+","+b[i3]+","+b[i4]+","+b[i5]+","+b[i6]+tail;
    k++;   
  }}}}}}     
}

void CMy115backDlg::ssqfufen(CString head,CString tail,int qianall,int qianmasu,CString touzu[],int &k)
{

  CString b[33];
  int i[6],j,n,m;
  Split(head, b, n, ",");
  bool goflag=true;  for (i[0]=0;i[0]<=n;i[0]++){    
  for (i[1]=i[0]+1;i[1]<=n;i[1]++){
  for (i[2]=i[1]+1;i[2]<=n;i[2]++){
  for (i[3]=i[2]+1;i[3]<=n;i[3]++){
  for (i[4]=i[3]+1;i[4]<=n;i[4]++){
  for (i[5]=i[4]+1;i[5]<=n;i[5]++){
      m=0;  
      for (j=0;j<6;j++){
        if( (i[j])<qianall){m++;}
      }  
      if (m==qianmasu){
        touzu[k]=b[i[0]]+","+b[i[1]]+","+b[i[2]]+","+b[i[3]]+","+b[i[4]]+","+b[i[5]]+tail;
        k++; 
      }
    
      
  }}}}}}     
}


void CMy115backDlg::ssqfufen(CString head,CString tail,CString wei,CString touzu[],int &k)
{
  int n,nn;
  CString b[33];
  CString bb[33];         
  Split(head, b, n, ",");
  Split(wei, bb, nn, ",");
  touzu[k]=b[atoi(bb[0])-1]+","+b[atoi(bb[1])-1]+","+b[atoi(bb[2])-1]+","+b[atoi(bb[3])-1]+","+b[atoi(bb[4])-1]+","+b[atoi(bb[5])-1]+tail;
  k++;   

}


void CMy115backDlg::jointwolotterfiles(CString file1,CString file2,CString dirpath) 
{
      int i,j,ubound1,ubound2,ubound;
      CString outfile,s,wr;
      CStdioFile fin,out;

      ubound1=0;
      fin.Open(file1,CFile::modeRead);
      do{
        fin.ReadString(s);
        ubound1++;
      }
      while (fin.GetPosition()!=fin.GetLength());
      fin.Close();
      CString *zu1=new CString [ubound1];

      fin.Open(file1,CFile::modeRead);
      i=0;
      do{
        fin.ReadString(s);s=delern(s);
        zu1[i]=s;
        i++;
      }
      while (fin.GetPosition()!=fin.GetLength());
      fin.Close();
//MessageBox(zu1[0]+"\r\n"+zu1[ubound1-1]);
      ubound2=0;
      fin.Open(file2,CFile::modeRead);
      do{
        fin.ReadString(s);
        ubound2++;
      }
      while (fin.GetPosition()!=fin.GetLength());
      fin.Close();
      CString *zu2=new CString [ubound2];

      fin.Open(file2,CFile::modeRead);
      i=0;
      do{
        fin.ReadString(s);s=delern(s);
        zu2[i]=s;
        i++;
      }
      while (fin.GetPosition()!=fin.GetLength());
      fin.Close();
 //MessageBox(zu2[0]+"\r\n"+zu2[ubound1-1]);
     
      ubound=ubound1+ubound2;
      CString *zu=new CString [ubound];
      
      for (i=0;i<ubound1;i++){
        zu[i]=zu1[i];
      }

      
      for (i=0;i<ubound2;i++){
        zu[i+ubound1]=zu2[i];
      }
//MessageBox(zu[0]+"\r\n"+zu[ubound-1]);
      
      delete[] zu1;delete[] zu2;
      bool you; 

      outfile=dirpath+"hebing.txt";     
      out.Open(outfile,CFile::modeCreate|CFile::modeWrite); 
      wr=zu[0]+"\r\n";
      out.Write(wr,wr.GetLength());
      for (i=1;i<ubound;i++){
        you=false;
        for (j=0;j<i;j++){
          if (islotterdeng(zu[i],zu[j],0)){you=true;break;}
        }

        if (! you){
          wr=zu[i]+"\r\n";
          out.Write(wr,wr.GetLength());
        }
      }
      out.Close();
      delete[] zu; 

}




void CMy115backDlg::dlcbuydata(CString dirpath) 
{
////////////////////////////////////////
    CString tjpath=dirpath+"tjsrc\\";
    if(_access(tjpath, 0) == -1){return;}
    CString xfile=dirpath+"buycansu.txt";
    CFileFind ff;
    if (! ff.FindFile(xfile)){return;}
    CStdioFile fin,fins,out3,out4,out5;
    CString buydata3=dirpath+"buydata3.txt";
    CString buydata4=dirpath+"buydata4.txt";
    CString buydata5=dirpath+"buydata5.txt";
    CString srcfile,s,t,wr,hao,b[10];
    int pos,jiang,bl,qisu;
    DWORD dwAttr;
    out3.Open(buydata3,CFile::modeCreate|CFile::modeWrite);    
    out4.Open(buydata4,CFile::modeCreate|CFile::modeWrite);    
    out5.Open(buydata5,CFile::modeCreate|CFile::modeWrite);  
  
    fin.Open(xfile,CFile::modeRead);
    while(fin.ReadString(s)){
      s=delern(s);
      if (s.GetLength()==0){continue;}
      pos=s.Find('\t');
      if (pos>=0){
        s=s.Mid(pos+1);
        pos=s.Find('\t');
        if (pos>=0){s=s.Left(pos);}
      }
      srcfile=tjpath+"tj"+padstrcisu(s,4,"0",0)+".txt";
      hao=padstrcisu(s,4,"0",0);

      dwAttr = ::GetFileAttributes(srcfile); 
      if (dwAttr == 0xffffffff){continue;} 
      fins.Open(srcfile,CFile::modeRead);
      t="";
      while(fins.ReadString(s)){
        s=delern(s);
        t=s;
      }
      fins.Close();
      if (t.GetLength()==0){continue;}
      Split(t,b,bl,"\t");
      qisu=atoi(b[0].Right(2));
      if (qisu<=0){continue;}
      jiang=atoi(b[3])*2970/qisu/2/m_we;
      wr=padstrcisu(Cstr(jiang),4," ",0)+"\t"+b[3]+"\t"+hao+"\r\n";

      out3.Write(wr,wr.GetLength());

      jiang=atoi(b[2])*11800/qisu/2/m_we;

      wr=padstrcisu(Cstr(jiang),4," ",0)+"\t"+b[2]+"\t"+hao+"\r\n";

      out4.Write(wr,wr.GetLength());

      jiang=atoi(b[1])*83100/qisu/2/m_we;

      wr=padstrcisu(Cstr(jiang),4," ",0)+"\t"+b[1]+"\t"+hao+"\r\n";

      out5.Write(wr,wr.GetLength());

    }
    fin.Close();out3.Close();out4.Close();out5.Close(); 
    sortafileatoz(buydata3);sortafileatoz(buydata4);sortafileatoz(buydata5);
    
}







void CMy115backDlg::deletenullfile(CString file) 
{
   DWORD dwAttr = ::GetFileAttributes(file); 
   if (dwAttr == 0xffffffff){return;} 
   CStdioFile fin;
   CString s;
   fin.Open(file,CFile::modeRead);
   int i=0;
   while(fin.ReadString(s)){
     i++;
   }
   fin.Close();
   if (i==0){DeleteFile(file);}
}













void CMy115backDlg::megatoubianrand(CString zu[],int &ubound) 
{
   int i,j,ai,k,m,n;
   CString s,c;
   bool you;
   CString *tzu=new CString [ubound];   
   for (i=0;i<ubound;i++){
     while (true){
       s="";k=0;
       for (ai=0;ai<8;ai++){
         j=rand()%15;
         m=(i+j%3)%ubound;
         n=j/3;
         c=zu[m].Mid(3*n,2);
         if (s.Find(c)<0){
           s=s+c+",";k++;
           if (k>=5){break;}
         }
       }
       while (k<5){
         while(true){
           j=rand()%75;
           if (j==0){j=75;}
           c=padstrcisu(Cstr(j),2,"0",0);
           if (s.Find(c)<0){
             s=s+c+",";
             k++;
             if (k>=5){break;}   
           }
         }   
       }
       s=s.Left(s.GetLength()-1);
    
////////////////////////////////////////////
       m=rand()%3;n=rand()%3;
       m=(i+m)%ubound;
       m=(atoi(zu[m].Right(2))+n)%15;
       if (m==0){m=15;}
       s=s+":"+padstrcisu(Cstr(m),2,"0",0);
       if (i==0){break;}  
       you=false;
       for (j=0;j<i;j++){
         if (islotterdeng(s,tzu[j],0)){you=true;break;}
       }
       if (! you){break;}
     }  
/////////////////////////////////////////////

     tzu[i]=s;
   }   
   for (i=0;i<ubound;i++){zu[i]=tzu[i];}
}


void CMy115backDlg::deletedir(CString dirpath) 
{

   CString szDir = dirpath,buyfile;
   szDir += "*.*"; 
   CFileFind ff;
   bool res = ff.FindFile(szDir);  
   while( res )
   { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if (ff.IsDots()){continue;}
     if(!ff.IsDirectory()){
       DeleteFile(buyfile);
     }
     else {
       CString npath=buyfile+"\\";
       int r=RemoveDirectory(npath);
       if (r==0 ){deletedir(npath);}
     }
   }
   ff.Close(); 
   RemoveDirectory(dirpath);
}

void CMy115backDlg::dlcmanagetjsrc(CString dirpath) 
{
   int pos;
   CString szDir = dirpath,buyfile,nake,zuming,wr,s;
   CStdioFile fin,out;

   CString spath=dirpath.Left(dirpath.GetLength()-1);
   pos=spath.ReverseFind('\\');
   spath=spath.Left(pos+1);
   CString tjall=spath+"tjall.txt";
   out.Open(tjall,CFile::modeCreate|CFile::modeWrite);  
   CFileFind ff;
      
   szDir += "*.*"; 
   bool res = ff.FindFile(szDir);  
   while( res ) 
   { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if(ff.IsDirectory() || ff.IsDots()){continue;}
     pos=buyfile.ReverseFind('\\');
     nake=buyfile.Mid(pos+1);
     zuming=nake.Mid(2,4);  
     wr="******"+zuming+"******\r\n";
     out.Write(wr,wr.GetLength());
     fin.Open(buyfile, CFile::modeRead);
     do{
       fin.ReadString(s);s=delern(s); 
       wr=s+"\r\n";
       out.Write(wr,wr.GetLength());
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();
   }
   ff.Close(); out.Close();
}
















































void CMy115backDlg::yiloufilegenxin(CString dirpath)
{

  if (dirpath.Find("\\abuy")>=0){return;}
  int i,j,pos,n;
  //////////////////
  CStdioFile out[3];
  CString byiloufile[3];
  for (i=0;i<3;i++){
    byiloufile[i]=dirpath+"byilou"+Cstr(i+3)+".txt";
    out[i].Open(byiloufile[i],CFile::modeCreate|CFile::modeWrite); 
  } 
  
  /////////////////

  CString strDir;
  CString szDir,buyfile,nake,wr; 
  CFileFind ff; 
  bool res;
  CString tdir,ydir=dirpath+"yilou\\";
  for (i=0;i<3;i++){
    tdir=dirpath+"yilou"+Cstr(i+3)+"\\";

    strDir=tdir;
    szDir = strDir;
    szDir += "*.*"; 
    res = ff.FindFile(szDir); 
    j=1;
    n=0;
    while( res ) 
    { 
      res = ff.FindNextFile(); 
      buyfile = ff.GetFilePath(); 

      if(!ff.IsDirectory() && !ff.IsDots()){

        pos=buyfile.ReverseFind('\\'); 
        nake=buyfile.Mid(pos+1);   

        CopyFile(ydir+nake,buyfile,0);

        wr=Cstr(j)+"\t"+nake.Mid(1,4)+"\t  \r\n";j++;

        out[i].Write(wr,wr.GetLength());n++;
      }    
    
    }
    ff.Close(); out[i].Close();
    if (n==0){DeleteFile(byiloufile[i]);}
    


  }

  

}


void CMy115backDlg::dlczeroall(CString dirpath)
{
  
  CString zallfile=dirpath+"zeroall.txt",b[10],wr,s;
  CStdioFile fin,out;
  int bl,n;
  DWORD dwAttr;

  out.Open(zallfile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);  
  out.SeekToEnd();
  
   CString zerofile[3];
   zerofile[0]=dirpath+"zero3num.txt";
   zerofile[1]=dirpath+"zero4num.txt";
   zerofile[2]=dirpath+"zeronum.txt";

   for (int i=0;i<3;i++){
     dwAttr = ::GetFileAttributes(zerofile[i]);
     if (dwAttr == 0xffffffff){continue;}
     fin.Open(zerofile[i], CFile::modeRead);

     if (fin.GetPosition()==fin.GetLength()){continue;}
     do{
       fin.ReadString(s);s=delern(s);
       Split(s,b,bl,"\t");
       n=atoi(b[2]);
       if (n>1 && b[0].Right(2)=="78"){
         wr="类别:"+Cstr(i+3)+"\t"+b[0]+"\t"+b[2]+"\t"+b[1]+"\t"+b[3]+"\r\n";
         out.Write(wr,wr.GetLength());
       }
            
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();
   }
   out.Close();
   sortafileztoa(zallfile);
   
}










/////rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr



















void CMy115backDlg::getssqbuyfile(CString dirpath,CString qihao,CString datas[]) 
{

  int ZSU=getcansu(dirpath,2);;

  int filenum=0,i,j;

  int buynum=m_etui;
  


  CString outfile,s,s1,s2,t1,t2,c;
  
  CString wr,qi; 
  CStdioFile fin,out;
////////////////////////////////////////////////////
  CString buypath;    
  buypath=dirpath+"buy\\";
  if(_access(buypath, 0) == -1){_mkdir(buypath);} 
  

//////////////////////////////////////////////////////
  CString *buyzu=new CString [buynum]; 
  CString *ybuyzu=new CString [buynum]; 

  for (i=0;i<buynum;i++){
    buyzu[i]=datas[i];
  }
  
  qi=qijia1(qihao);

  ///////// m_btui(组数),m_etui(个数)
  
  for (i=0;i<ZSU;i++){
    DoEvents();

    ssqtoubianrand(buyzu,ybuyzu,buynum);     
    GetDlgItem(idc_jingdu)->SetWindowText("i="+Cstr(i));
    DoEvents();

    outfile=buypath+"buy["+padstrcisu(Cstr(i),5,"0",0)+"]"+qi+"-"+Cstr(buynum)+"[1-"+Cstr(m_etui)+"].txt";
    out.Open(outfile,CFile::modeCreate|CFile::modeWrite);
    for (j=0;j<buynum;j++){
      s=ybuyzu[j]+"\r\n"; 
      out.Write(s,s.GetLength()); 
    }

    out.Close();
  
  }



  
  delete[] buyzu;delete[] ybuyzu;
}


bool CMy115backDlg::islotterdeng(CString ma1,CString ma2,int wei) 
{
 
   ma1=ma1.Left(ma1.GetLength()-3);
   ma2=ma2.Left(ma2.GetLength()-3);
  
   return (islotterdeng(ma1,ma2));
}

bool CMy115backDlg::islotterdeng(CString ma1,CString ma2) 
{

   int chang=ma1.GetLength();
   if (chang!=ma2.GetLength()){return false;}

   int i;
   CString c;
   for (i=0;i<chang;i=i+3){
     c=ma1.Mid(i,2);

     if (ma2.Find(c)<0){return false;}    
   }

   return true;
}


void CMy115backDlg::ssqtoubianrand(CString zu[],CString *tzu,int ubound) 
{
   int i,j,ai,k,m,n,su=m_etui*6;
   CString s,c;
   bool you;
   
   for (i=0;i<ubound;i++){
     while (true){
       s="";k=0;
       for (ai=0;ai<12;ai++){
         j=rand()%su;
         m=j/6;
         n=j%6;
         c=zu[m].Mid(3*n,2);
         if (s.Find(c)<0){
           s=s+c+",";k++;
           if (k>=6){break;}
         }
       }
       while (k<6){
         while(true){
           j=rand()%33;
           if (j==0){j=33;}
           c=padstrcisu(Cstr(j),2,"0",0);
           if (s.Find(c)<0){
             s=s+c+",";
             k++;
             if (k>=6){break;}   
           }
         }   
       }
       s=s.Left(s.GetLength()-1);
////////////////////////////////////////////
       m=rand()%3;n=rand()%3;

       m=(i+m)%ubound;

       m=(atoi(zu[m].Right(2))+n)%16;

       if (m==0){m=16;}

       s=s+":"+padstrcisu(Cstr(m),2,"0",0);
       if (i==0){break;}  
       you=false;
       for (j=0;j<i;j++){
         if (islotterdeng(s,tzu[j],0)){you=true;break;}
       }
       if (! you){break;}
     }
/////////////////////////////////////////////
     tzu[i]=s;
   }   
   
}





























void CMy115backDlg::deletefileofdir(CString dirpath) 
{

   CString szDir = dirpath,buyfile,npath;
   szDir += "*.*"; 
   CFileFind ff;
   bool res = ff.FindFile(szDir);  
   while( res )
   { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if (ff.IsDots()){continue;}
     if(!ff.IsDirectory()){
       DeleteFile(buyfile);
     }
     else {
       npath=buyfile+"\\";       
       deletefileofdir(npath);
     }
   }
   ff.Close();    
}




void CMy115backDlg::adeletefileofdir_(CString path) 
{
   CString szDir = path,buyfile;
   szDir += "*.*"; 
   CFileFind ff;
   bool res = ff.FindFile(szDir);  
   while( res )
   { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if (ff.IsDots()){continue;}
     if(!ff.IsDirectory()){
       DeleteFile(buyfile);
     }     
   }
   ff.Close(); 
}

void CMy115backDlg::adeletefileofdir(CString apath) 
{

   CString deledir;
   int i;
   for (i=0;i<3;i++){
     deledir=apath+"abuy"+Cstr(i+3)+"\\";
     adeletefileofdir_(deledir);
     deledir=apath+"abuybyilou"+Cstr(i+3)+"\\";
     adeletefileofdir_(deledir);
     deledir=apath+"abuyyilou"+Cstr(i+3)+"\\";
     adeletefileofdir_(deledir);

     deledir=apath+"abuy"+Cstr(i+3)+"\\buy\\";
     adeletefileofdir_(deledir);
     deledir=apath+"abuybyilou"+Cstr(i+3)+"\\buy\\";
     adeletefileofdir_(deledir);
     deledir=apath+"abuyyilou"+Cstr(i+3)+"\\buy\\";
     adeletefileofdir_(deledir);

     deledir=apath+"abuy"+Cstr(i+3)+"\\tjsrc\\";
     adeletefileofdir_(deledir);
     deledir=apath+"abuybyilou"+Cstr(i+3)+"\\tjsrc\\";
     adeletefileofdir_(deledir);
     deledir=apath+"abuyyilou"+Cstr(i+3)+"\\tjsrc\\";
     adeletefileofdir_(deledir);

     deledir=apath+"abuy"+Cstr(i+3)+"\\yilou\\";
     adeletefileofdir_(deledir);
     deledir=apath+"abuybyilou"+Cstr(i+3)+"\\yilou\\";
     adeletefileofdir_(deledir);
     deledir=apath+"abuyyilou"+Cstr(i+3)+"\\yilou\\";
     adeletefileofdir_(deledir);

   }

}


void CMy115backDlg::dlccopybuyfile(CString dirpath,int d78) 
{
   DWORD dwAttr;
   if (m_bfile.GetLength()==0){

     dwAttr = ::GetFileAttributes(dirpath+"yilou3.txt");
     if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"yilou3",d78);}


     dwAttr = ::GetFileAttributes(dirpath+"yilou4.txt");
     if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"yilou4",d78);}


     dwAttr = ::GetFileAttributes(dirpath+"yilou5.txt");
     if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"yilou5",d78);} 


     dwAttr = ::GetFileAttributes(dirpath+"byilou3.txt");
     if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"byilou3",d78);} 


     dwAttr = ::GetFileAttributes(dirpath+"byilou4.txt");
     if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"byilou4",d78);}


     dwAttr = ::GetFileAttributes(dirpath+"byilou5.txt");
     if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"byilou5",d78);}


     return;
   }
   int n=atoi(m_bfile);
   
   switch(n){
     case 0:
       dwAttr = ::GetFileAttributes(dirpath+"yilou4.txt");
       if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"yilou4",d78);}
       break;

     case 4:
       dwAttr = ::GetFileAttributes(dirpath+"yilou3.txt");
       if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"yilou3",d78);}
       break;
     case 5:
       dwAttr = ::GetFileAttributes(dirpath+"yilou4.txt");
       if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"yilou4",d78);}
       break;
     case 6:
       dwAttr = ::GetFileAttributes(dirpath+"yilou5.txt");
       if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"yilou5",d78);}
       break;
     case 7:
       dwAttr = ::GetFileAttributes(dirpath+"byilou3.txt");
       if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"byilou3",d78);}
       break;
     case 8:
       dwAttr = ::GetFileAttributes(dirpath+"byilou4.txt");     
       if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"byilou4",d78);}
       break;
     case 9:
       dwAttr = ::GetFileAttributes(dirpath+"byilou5.txt");
       if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"byilou5",d78);}
       break;


     default:
       dwAttr = ::GetFileAttributes(dirpath+"yilou4.txt");
       if (dwAttr != 0xffffffff){dlccopyabuyfile(dirpath,"yilou4",d78);}
   }
}










void CMy115backDlg::dlczeromanage(CString zerofile,CString qihao) 
{
////////////////////////////////////////
      int n,k;
      int re=sortafileatoz(zerofile);
   

      if (re==-1){
        return;
      }
      int i,pos;
      
      CString dirpath,s,wr;
      CStdioFile fin,out;
      pos=zerofile.ReverseFind('\\');
      dirpath=zerofile.Left(pos+1);
      
      
      CString b[10];
      int bl;
      i=0;
      fin.Open(zerofile,CFile::modeRead);
      while(fin.ReadString(s)){
        i++;
      }
      fin.Close(); 
 

      if (i>0){
        int ubound=i;
        i=0;
        CString *zu=new CString [ubound];
        CString *zuwr=new CString [ubound];
        fin.Open(zerofile,CFile::modeRead);
        while(fin.ReadString(s)){
          s=delern(s);
          zu[i]=s;i++;
        }
        fin.Close();  
        for (i=0;i<ubound;i++){
          Split(zu[i],b,bl,"\t");
          zuwr[i]=b[1]+"#"+zu[i];
        } 
      
        paixuatoz(zuwr,ubound);
        CString zerozu=zerofile.Left(zerofile.GetLength()-4)+"zu.txt";
        out.Open(zerozu,CFile::modeCreate|CFile::modeWrite);
  
        for (i=0;i<ubound;i++){
          wr=zuwr[i];
          pos=wr.Find("#");
          wr=wr.Mid(pos+1)+"\r\n";      
    
          out.Write(wr,wr.GetLength());
        }
        out.Close();
 
        for (i=0;i<ubound;i++){
          Split(zu[i],b,bl,"\t");
          zuwr[i]=b[2]+"#"+zu[i];
        }       
        paixuztoa(zuwr,ubound);
        CString zeronum=zerofile.Left(zerofile.GetLength()-4)+"num.txt";
        out.Open(zeronum,CFile::modeCreate|CFile::modeWrite);       
  
        k=0;
        for (i=0;i<ubound;i++){
          wr=zuwr[i];
          pos=wr.Find("#");
          n=atoi(wr.Left(pos));
          if (n<2 && qihao.Right(2)=="78" || n<3 && qihao.Right(2)<"78"){continue;}
          wr=wr.Mid(pos+1)+"\r\n";          
          out.Write(wr,wr.GetLength());k++;
        }
        out.Close();
        if (k==0){DeleteFile(zeronum);}
        delete[] zu;delete[] zuwr;
      }
////////////////////////////////////////

}

























void CMy115backDlg::dlcrecords(CString srcfile,CString ***records,CStdioFile &outz,CStdioFile &outz3,CStdioFile &outz4) 
{
  CStdioFile fin;
  int pos,i,j,bl,zsu[3];
  CString s,wr,b[6];
  const int ZUSU=20;
  const int N3=5;
  const int N4=1;
  const int N5=0;


  pos=srcfile.ReverseFind('\\');
  CString zuming=srcfile.Mid(pos+1);
  zuming=zuming.Left(zuming.GetLength()-4);
  zuming=zuming.Mid(2);
  zuming.Replace("_0","");
  fin.Open(srcfile, CFile::modeRead);  
  i=0;   
  while(fin.ReadString(s)){
    i++;
  }
  fin.Close();
  if (i==0){return;}
  int ubound=i;
  CString *nowrecords=new CString [ubound];
  fin.Open(srcfile, CFile::modeRead);  
  i=0;   
  while(fin.ReadString(s)){
    s=delern(s);
    nowrecords[i]=s;
    i++;
  }
  fin.Close();

  CString qi;
  
  bool wrflag3=false,wrflag4=false,wrflag5=false,d3flag,d4flag,d5flag;
  int b1,b2,b3;
  for (i=ZUSU;i>=1;i--){    
    if (ubound<i){continue;}  
    d3flag=true;d4flag=true;d5flag=true;
    for (j=0;j<3;j++){zsu[j]=0;}
    for (j=ubound-1;j>=ubound-i;j--){
      s=nowrecords[j];
      Split(s,b,bl,"\t");
      b1=atoi(b[1]);b2=atoi(b[2]);b3=atoi(b[3]);
      zsu[0]+=b3;zsu[1]+=b2;zsu[2]+=b1;
      d3flag=d3flag && (b3<=N3);d4flag=d4flag && (b2<=N4);d5flag=d5flag && (b1<=N5);
      
    }
    ///////////////////////////////    

    ///////////////////////////////
    for (j=0;j<3;j++){
      if (records[j][i-1][0]=="0"){
         records[j][i-1][0]=zuming;
         records[j][i-1][1]=Cstr(zsu[j]);
      }
      else {
        if (zsu[j]<atoi(records[j][i-1][1])){
          records[j][i-1][0]=zuming;
          records[j][i-1][1]=Cstr(zsu[j]);
        }
      }
    }
    /////////////////////////////////////////////////
    if (i<m_su){continue;}
    if (wrflag3 && wrflag4 && wrflag5){continue;}
    if (zsu[0]>i*N3 && zsu[1]>i*N4 && zsu[2]>N5){continue;}    
    if (!d3flag && !d4flag && !d5flag){continue;}
    qi=nowrecords[ubound-1];
    qi=qi.Mid(9,8);
    if (zsu[0]<=i*N3 && !wrflag3 && d3flag){
      wr=qi+"\t"+zuming+"\t"+padstrcisu(Cstr(i),2," ",0)+"\t"+padstrcisu(Cstr(zsu[0]),2," ",0)+"\r\n"; 
      outz3.Write(wr,wr.GetLength());    
      wrflag3=true;
    }
    if (zsu[1]<=i*N4 && !wrflag4 && d4flag){
      wr=qi+"\t"+zuming+"\t"+padstrcisu(Cstr(i),2," ",0)+"\t"+Cstr(zsu[1])+"\r\n"; 
      outz4.Write(wr,wr.GetLength());    
      wrflag4=true;
    }    
    
    if (zsu[2]<=N5 && !wrflag5 && d5flag){
      wr=qi+"\t"+zuming+"\t"+padstrcisu(Cstr(i),2," ",0)+"\t"+Cstr(zsu[2])+"\r\n"; 
      outz.Write(wr,wr.GetLength());    
      wrflag5=true;
    }
   
    //////////////////////////////////////////////////

  }
  delete[] nowrecords;

}







CString CMy115backDlg::checkdlcbuyfile(CString yumafile,CString qihao[],CString datas[],int ubound,CString tjsrc,CString zupath)
{
  int filenum,i,j,pos,m,zsu[5],allsu=0,bl;
  int z5=0,z4=0,z3=0,qsu=0;
  int lei=0;
  const int Y3=20;
  const int Y4=136;
  const int Y5=1200;
  CStdioFile fin,out,outtj;

////将预报码读到数组中////////////////////////
  CString outfile,s,c,cistr,real,fenname,t,b[10],mpath,qi;

  pos=yumafile.ReverseFind('\\');
  CString dirpath=yumafile.Left(pos+1);

  CString hao=yumafile.Mid(pos+1).Left(4);


  fin.Open(yumafile, CFile::modeRead);
  fin.ReadString(s);s=delern(s);

  pos=s.Find("-");
  CString beginqi=s.Left(pos);


  if (beginqi>qihao[0]){fin.Close();return "";}//数据未出，退出。
  int qisu=atoi(s.Mid(pos+1));
 

  CString **yuma=new CString *[qisu];
  for (i=0;i<qisu;i++){
    *(yuma+i)=new CString [m_we];
  }
  
  for (i=0;i<qisu;i++){    
    fin.ReadString(s);s=delern(s);
    Split(s,b,bl,"|");
    for (j=0;j<m_we;j++){
      yuma[i][j]=b[j];
    }    
  }
  fin.Close();

///////////////////////////////////////////

  

  CString myqi3,myqi4,myqi5;
/////////////////////////////////////////
  CString ydir3=zupath+"yilou3\\";
  CString ydir4=zupath+"yilou4\\";
  CString ydir5=zupath+"yilou5\\";
  bool y3flag=false,y4flag=false,y5flag=false;
/////////////////////////////////////////
 
  //CString tjfile=tjsrc+"tj"+hao+".txt";
  //outtj.Open(tjfile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate); 
  //outtj.SeekToEnd(); 

  CString strDir=dirpath,head;
  CString szDir = strDir,buyfile,nake,jigo,ma,zhong,wr; 


  CString nowqi;


 
///////////////////////////////////////
  CString yiloufile;
  DWORD dwAttr;
  int yilou3=0,yilou4=0,yilou5=0,yilou3m=0,yilou4m=0,yilou5m=0;
  CString ystr3="y3:",ystr4="y4:",ystr5="y5:";
  CString ystr3t="",ystr4t="",ystr5t="";
  yiloufile=zupath+"yilou\\y"+hao+".txt";  

  dwAttr = ::GetFileAttributes(yiloufile); 

  if (dwAttr != 0xffffffff){
    i=0;
    fin.Open(yiloufile, CFile::modeRead);
//////////////////////////////////////
    do{
      fin.ReadString(s);s=delern(s);
      if (i==0){
        Split(s,b,bl,"\t");
        yilou3=atoi(b[0]);yilou4=atoi(b[1]);yilou5=atoi(b[2]);       
        i++;
        continue;    
      }

      if (i>0){
         if (s.GetLength()>1003){
           t=s.Left(3);
           s=s.Right(1000);
           pos=s.Find(",");
           if (pos>=0){s=s.Mid(pos+1);}
           s=t+s;
         }
         if (s.Right(1)!="," && s.Right(1)!=":" ){s+=",";}
      }

      if (i==1){
        ystr3=s;i++;continue;
      }
      if (i==2){
        ystr4=s;i++;continue;
      }
      if (i==3){
        ystr5=s;i++;continue;
      }   


    }
    while (fin.GetPosition()!=fin.GetLength());
/////////////////////////////////////
    fin.Close();
  } 




///////////////////////////////////////
  filenum=qisu;
  int xu=0;
  qi=beginqi;
  while (beginqi<qihao[xu]){
    xu++;
  }
  int maj;

  beginqi="0";
  

  for (i=0;i<filenum;i++){      
    ma=datas[xu];
    for (j=0;j<5;j++){zsu[j]=0;}
    nowqi=qi;
    if (beginqi=="0"){beginqi=nowqi;}
    for (maj=0;maj<m_we;maj++){
      s=yuma[i][maj];
      m=0;
      
      for (j=0;j<15;j=j+3){
        c=s.Mid(j,2);
        if (ma.Find(c)>=0){
          m++;
        }
        else {break;}
      }
      if (m==5){zsu[2]++;zsu[3]++;zsu[4]++;}
      else {
        if (m==4){zsu[2]++;zsu[3]++;}
        else {
          if (m==3){zsu[2]++;}
        }        
      }
         
 
//////////////////////////////////////////////////////
      if (m==3){z3++;}
      else if (m==4){z3++;z4++;}
      else if (m==5){z3++;z4++;z5++;}       
       
    }//for (maj=0;maj<m_we;maj++){

    


////////////////////////////////////////////


////////////////////////////////////////////
//////////////////////////////////////////////////////////

    if (zsu[2]>0){
        ystr3t+=Cstr(yilou3)+",";
        if (yilou3>=Y3){y3flag=true;}
        yilou3=0;
    }
    else {yilou3++;if (yilou3>yilou3m){yilou3m=yilou3;myqi3=qi;}}
    if (zsu[3]>0){
         ystr4t+=Cstr(yilou4)+",";
         if (yilou4>=Y4){y4flag=true;}
         yilou4=0;
    }
    else {yilou4++;if (yilou4>yilou4m){yilou4m=yilou4;myqi4=qi;}}
    if (zsu[4]>0){
         ystr5t+=Cstr(yilou5)+",";
         if (yilou5>=Y5){y5flag=true;}
         yilou5=0;
    }
    else {yilou5++;if (yilou5>yilou5m){yilou5m=yilou5;myqi5=qi;}}
    xu--; qisu--;qi=qijia1(qi);

    if (xu<0){break;}

/////////////////////////////////////////////////////////////
  }
////////////////////////////////////////////////////
  DeleteFile(yumafile);
  if (qisu>0){
    wr=qi+"-"+Cstr(qisu)+"\r\n";
    out.Open(yumafile,CFile::modeCreate|CFile::modeWrite);
    out.Write(wr,wr.GetLength());
    for (i=filenum-qisu;i<filenum;i++){
      wr="";
      for (j=0;j<m_we;j++){
        wr+=yuma[i][j]+"|";
      }
      wr=wr.Left(wr.GetLength()-1)+"\r\n";
      out.Write(wr,wr.GetLength());
    }
    out.Close();
  }



////////////////////////////////////////////////////


  out.Open(yiloufile,CFile::modeCreate|CFile::modeWrite);

  wr=Cstr(yilou3)+"\t"+Cstr(yilou4)+"\t"+Cstr(yilou5);  
  wr+="\t"+Cstr(yilou3m)+"-"+myqi3+"-"+hao+"\t"+Cstr(yilou4m)+"-"+myqi4+"-"+hao+"\t"+Cstr(yilou5m)+"-"+myqi5+"-"+hao+"\r\n";
  out.Write(wr,wr.GetLength());
  CString rewr=wr;
  
  ystr3.TrimLeft();
  wr=ystr3+ystr3t+"\r\n";
  out.Write(wr,wr.GetLength());
  
  ystr4.TrimLeft();
  wr=ystr4+ystr4t+"\r\n";
  out.Write(wr,wr.GetLength());

  ystr5.TrimLeft();
  wr=ystr5+ystr5t+"\r\n";
  out.Write(wr,wr.GetLength());




  

  out.Close();  
  CString ytarget;
  if (y3flag){
    ytarget=ydir3+"y"+hao+".txt";
    CopyFile(yiloufile,ytarget,0);
  }
  if (y4flag){
    ytarget=ydir4+"y"+hao+".txt";
    CopyFile(yiloufile,ytarget,0);
  }
  if (y5flag){
    ytarget=ydir5+"y"+hao+".txt";
    CopyFile(yiloufile,ytarget,0);
  }


  for (i=0;i<filenum;i++){delete[] yuma[i];}
  delete[] yuma;
  //joindlcsrcdata(tjfile);




  return rewr;

}















int CMy115backDlg::dlcrefresh(CString dirpath,CString qihao[],CString datas[],int ubound) 
{

      DWORD dwAttr;
      CStdioFile fin,out;
      int i,n,bl;
      bool type=true;
      CString b[10],bb[5],s,wr;
      if (dirpath.Find("abuy\\abuy")>=0){type=false;}
      CString cansufile=dirpath+"buycansu.txt";
      int canum=0;
      int *can;
      if (! type){
        dwAttr = ::GetFileAttributes(cansufile);
        if (dwAttr == 0xffffffff){return -1;}
        else {
          fin.Open(cansufile,CFile::modeRead);
          while (fin.GetPosition()!=fin.GetLength()){
            fin.ReadString(s);
            canum++;
          }
          fin.Close();
          if (canum==0){return -1;}
          can=new int[canum];
          i=0;
          fin.Open(cansufile,CFile::modeRead);
          while (fin.GetPosition()!=fin.GetLength()){
            fin.ReadString(s);s=delern(s);
            Split(s,b,bl,"\t");
            can[i]=atoi(b[1]);
            i++;
          }
          fin.Close();

        }
      }

      const int ZUSU=20;      
      int ZSU=getcansu(dirpath,1);
      
      CString zpath=dirpath+"buy\\";


      //CString tjsrc=dirpath+"tjsrc\\",srcfile;
      //if(_access(tjsrc, 0) == -1){_mkdir(tjsrc);} 
      CString yiloudir=dirpath+"yilou\\";
      if(_access(yiloudir, 0) == -1){_mkdir(yiloudir);} 

      CString yiloudir3=dirpath+"yilou3\\";
      if(_access(yiloudir3, 0) == -1){_mkdir(yiloudir3);} 

      CString yiloudir4=dirpath+"yilou4\\";
      if(_access(yiloudir4, 0) == -1){_mkdir(yiloudir4);} 

      CString yiloudir5=dirpath+"yilou5\\";
      if(_access(yiloudir5, 0) == -1){_mkdir(yiloudir5);} 


      CString yilou3file=dirpath+"yilou3.txt";
      CStdioFile outy3;
      outy3.Open(yilou3file,CFile::modeCreate|CFile::modeWrite);      
      bool y3flag=false;

      CString yilou4file=dirpath+"yilou4.txt";
      CStdioFile outy4;
      outy4.Open(yilou4file,CFile::modeCreate|CFile::modeWrite);      
      bool y4flag=false;

      CString yilou5file=dirpath+"yilou5.txt";
      CStdioFile outy5;
      outy5.Open(yilou5file,CFile::modeCreate|CFile::modeWrite);   
      bool y5flag=false;



      CString ystr;
      int maxyilou3=0,maxyilou4=0,maxyilou5=0;
      CString myqi3,myqi4,myqi5,zuming3,zuming4,zuming5,yilousrc,yiloutarget;
      CString istr;
      
      int mjie=ZSU;
      if (! type){mjie=canum;}
      CString yumafile;
      
      for (i=0;i<mjie;i++){

         n=i;
         if (! type){n=can[i];}
         istr=padstrcisu(Cstr(n),4,"0",0);
       
         yumafile=zpath+istr+".txt";
         dwAttr = ::GetFileAttributes(yumafile);
         if (dwAttr == 0xffffffff){continue;}


         ystr=checkdlcbuyfile(yumafile,qihao,datas,ubound,"",dirpath);

         if (ystr.GetLength()<10){
           continue;
         }
         //zflag=true;
         

         Split(ystr,b,bl,"\t");

         if (atoi(b[0])>0){
           wr=padstrcisu(b[0],4,"0",0)+"\t"+istr+"\t\r\n";


           outy3.Write(wr,wr.GetLength());y3flag=true;
         }

         if (atoi(b[1])>0){
           wr=padstrcisu(b[1],4,"0",0)+"\t"+istr+"\t\r\n";


           outy4.Write(wr,wr.GetLength());y4flag=true;
         }

         if (atoi(b[2])>0){
           wr=padstrcisu(b[2],4,"0",0)+"\t"+istr+"\t\r\n";

           outy5.Write(wr,wr.GetLength());y5flag=true;
         }


         

         Split(b[3],bb,bl,"-");              
         n=atoi(bb[0]);
         if (n>maxyilou3){maxyilou3=n;myqi3=bb[1];zuming3=bb[2];}

         Split(b[4],bb,bl,"-");              
         n=atoi(bb[0]);
         if (n>maxyilou4){maxyilou4=n;myqi4=bb[1];zuming4=bb[2];}

         Split(b[5],bb,bl,"-");              
         n=atoi(bb[0]);
         if (n>maxyilou5){maxyilou5=n;myqi5=bb[1];zuming5=bb[2];}
          



         //srcfile=tjsrc+"tj"+istr+".txt";

         //dlcrecords(srcfile,records,outz,outz3,outz4);
         //deletenullfile(srcfile);




      }
      delete[] can;
      //outz.Close();outz3.Close();outz4.Close();
      outy3.Close();outy4.Close();outy5.Close();
      if (y3flag){
        sortafileztoa(yilou3file);
      }
      else {DeleteFile(yilou3file);}
      if (y4flag){
        sortafileztoa(yilou4file);
      }
      else {DeleteFile(yilou4file);}
      if (y5flag){
        sortafileztoa(yilou5file);
      }
      else {DeleteFile(yilou5file);}
      
      CString head="      qi";
      for (i=0;i<ZUSU;i++){
         head+=";"+padstrcisu(Cstr(i+1),9," ",0);
      }



      


 
      
      dlcbuydata(dirpath);

///////////////////////////////////////
      CString maxyiloufile;

      maxyiloufile=dirpath+"maxyilou3qi.txt";      
      out.Open(maxyiloufile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);      
      out.SeekToEnd();
      wr=myqi3+"\t"+padstrcisu(Cstr(maxyilou3),4,"0",0)+"\t"+zuming3+"\r\n";
      out.Write(wr,wr.GetLength());
      out.Close();

      sortafileztoa(maxyiloufile);

      maxyiloufile=dirpath+"maxyilou3num.txt";      
      out.Open(maxyiloufile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);      
      out.SeekToEnd();
      wr=padstrcisu(Cstr(maxyilou3),4,"0",0)+"\t"+myqi3+"\t"+zuming3+"\r\n";
      out.Write(wr,wr.GetLength());
      out.Close();
      sortafileztoa(maxyiloufile);

      maxyiloufile=dirpath+"maxyilou4qi.txt";      
      out.Open(maxyiloufile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);      
      out.SeekToEnd();
      wr=myqi4+"\t"+padstrcisu(Cstr(maxyilou4),4,"0",0)+"\t"+zuming4+"\r\n";
      out.Write(wr,wr.GetLength());
      out.Close();
      sortafileztoa(maxyiloufile);


      maxyiloufile=dirpath+"maxyilou4num.txt";      
      out.Open(maxyiloufile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);      
      out.SeekToEnd();
      wr=padstrcisu(Cstr(maxyilou4),4,"0",0)+"\t"+myqi4+"\t"+zuming4+"\r\n";
      out.Write(wr,wr.GetLength());
      out.Close();
      sortafileztoa(maxyiloufile);

      maxyiloufile=dirpath+"maxyilou5qi.txt";      
      out.Open(maxyiloufile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);      
      out.SeekToEnd();
      wr=myqi5+"\t"+padstrcisu(Cstr(maxyilou5),4,"0",0)+"\t"+zuming5+"\r\n";
      out.Write(wr,wr.GetLength());
      out.Close();
      sortafileztoa(maxyiloufile);

      maxyiloufile=dirpath+"maxyilou5num.txt";      
      out.Open(maxyiloufile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);      
      out.SeekToEnd();
      wr=padstrcisu(Cstr(maxyilou5),4,"0",0)+"\t"+myqi5+"\t"+zuming5+"\r\n";
      out.Write(wr,wr.GetLength());
      out.Close();
      sortafileztoa(maxyiloufile);

      yiloufilegenxin(dirpath);

      return 0;
////////////////////////////////////////
}



void CMy115backDlg::dlccopyabuyfile(CString dirpath,CString mode,int d78) 
{


   const int Y3=20;
   const int Y4=136;
   const int Y5=1200;

   CString buypath=dirpath+"buy\\";
   CString copymodefile=dirpath+mode+".txt";
//MessageBox(mode+"\r\n"+copymodefile);
   

   DWORD dwAttr = ::GetFileAttributes(copymodefile); 
   if (dwAttr == 0xffffffff){return;} 

   

   CString haostr,s,t,wei,b[10],wr;
   CStdioFile fin,out;
   int bl,i;
///////////////////////////////////////////////
   fin.Open(copymodefile, CFile::modeRead);
   if (fin.GetPosition()==fin.GetLength()){fin.Close();return;}
   fin.Close();
///////////////////////////////////////////////

   CString apath,bpath,ypath;
   CString abuypath=dirpath+"abuy\\";
   if(_access(abuypath, 0) == -1){_mkdir(abuypath);}
//////////5////////////////////////////////////
//////////////////////////////////////////////
   if (mode=="yilou3"){
     fin.Open(copymodefile, CFile::modeRead);
     i=0;
     do{
       fin.ReadString(s);s=delern(s);
       Split(s,b,bl,"\t");
       if (atoi(b[0])>=Y3){i++;}
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();
     if (i==0){return;}
     apath=abuypath+"abuyyilou3\\";wei="3";
     if(_access(apath, 0) == -1){_mkdir(apath);}
     out.Open(apath+"buycansu.txt",CFile::modeCreate|CFile::modeWrite);
     fin.Open(copymodefile, CFile::modeRead);     
     do{
       fin.ReadString(s);s=delern(s);
       Split(s,b,bl,"\t");
       if (atoi(b[0])<Y3){continue;}
       wr=s+"\r\n";
       out.Write(wr,wr.GetLength());
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();out.Close();
   }

   if (mode=="yilou4"){
     fin.Open(copymodefile, CFile::modeRead);
     i=0;
     do{
       fin.ReadString(s);s=delern(s);
       Split(s,b,bl,"\t");
       if (atoi(b[0])>=Y4){i++;}
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();
     if (i==0){return;}
     apath=abuypath+"abuyyilou4\\";wei="4";
     if(_access(apath, 0) == -1){_mkdir(apath);}
     out.Open(apath+"buycansu.txt",CFile::modeCreate|CFile::modeWrite);
     fin.Open(copymodefile, CFile::modeRead);     
     do{
       fin.ReadString(s);s=delern(s);
       Split(s,b,bl,"\t");
       if (atoi(b[0])<Y4){continue;}
       wr=s+"\r\n";
       out.Write(wr,wr.GetLength());
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();out.Close();
   }

   if (mode=="yilou5"){
     fin.Open(copymodefile, CFile::modeRead);
     i=0;
     do{
       fin.ReadString(s);s=delern(s);
       Split(s,b,bl,"\t");
       if (atoi(b[0])>=Y5){i++;}
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();
     if (i==0){return;}
     apath=abuypath+"abuyyilou5\\";wei="5";
     if(_access(apath, 0) == -1){_mkdir(apath);}
     out.Open(apath+"buycansu.txt",CFile::modeCreate|CFile::modeWrite);
     fin.Open(copymodefile, CFile::modeRead);     
     do{
       fin.ReadString(s);s=delern(s);
       Split(s,b,bl,"\t");
       if (atoi(b[0])<Y5){continue;}
       wr=s+"\r\n";
       out.Write(wr,wr.GetLength());
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();out.Close();
   }
/////////////////////////////////////////////////
   if (mode=="byilou3"){
     fin.Open(copymodefile, CFile::modeRead);

     i=0;
     do{
       fin.ReadString(s);s=delern(s);
       i++;
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();

     if (i==0){return;}
     apath=abuypath+"abuybyilou3\\";wei="3";
     if(_access(apath, 0) == -1){_mkdir(apath);}
     out.Open(apath+"buycansu.txt",CFile::modeCreate|CFile::modeWrite);
     fin.Open(copymodefile, CFile::modeRead);     
     do{
       fin.ReadString(s);s=delern(s);       
       wr=s+"\r\n";
       out.Write(wr,wr.GetLength());
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();out.Close();
   }

   if (mode=="byilou4"){
     fin.Open(copymodefile, CFile::modeRead);
     i=0;
     do{
       fin.ReadString(s);s=delern(s);
       i++;
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();
     if (i==0){return;}
     apath=abuypath+"abuybyilou4\\";wei="4";
     if(_access(apath, 0) == -1){_mkdir(apath);}
     out.Open(apath+"buycansu.txt",CFile::modeCreate|CFile::modeWrite);
     fin.Open(copymodefile, CFile::modeRead);     
     do{
       fin.ReadString(s);s=delern(s);       
       wr=s+"\r\n";
       out.Write(wr,wr.GetLength());
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();out.Close();
   }
   if (mode=="byilou5"){
     fin.Open(copymodefile, CFile::modeRead);
     i=0;
     do{
       fin.ReadString(s);s=delern(s);
       i++;
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();
     if (i==0){return;}
     apath=abuypath+"abuybyilou5\\";wei="5";
     if(_access(apath, 0) == -1){_mkdir(apath);}
     out.Open(apath+"buycansu.txt",CFile::modeCreate|CFile::modeWrite);
     fin.Open(copymodefile, CFile::modeRead);     
     do{
       fin.ReadString(s);s=delern(s);       
       wr=s+"\r\n";
       out.Write(wr,wr.GetLength());
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();out.Close();
   }

/////////////////////////////////////////////////   
   bpath=apath+"buy\\";   
   if(_access(bpath, 0) == -1){_mkdir(bpath);}
   //tpath=apath+"tjsrc\\";   
   //if(_access(tpath, 0) == -1){_mkdir(tpath);}
   ypath=apath+"yilou\\";   
   if(_access(ypath, 0) == -1){_mkdir(ypath);}

   CopyFile(dirpath+"tongji3.txt",apath+"tongji3.txt",0); 
   CopyFile(dirpath+"tongji4.txt",apath+"tongji4.txt",0); 
   CopyFile(dirpath+"tongji5.txt",apath+"tongji5.txt",0);
/////////////////////////////////////////////////////
   CString yilou3=apath+"yilou3.txt";
   CString yilou4=apath+"yilou4.txt";
   CString yilou5=apath+"yilou5.txt";
   CStdioFile outy3,outy4,outy5,finy;
   outy3.Open(yilou3,CFile::modeCreate|CFile::modeWrite);
   outy4.Open(yilou4,CFile::modeCreate|CFile::modeWrite);
   outy5.Open(yilou5,CFile::modeCreate|CFile::modeWrite);
 
//////////////////////////////////////////////
   CString srcfile,targetfile,hao;
 

   fin.Open(apath+"buycansu.txt", CFile::modeRead);
   
   
   do{
     fin.ReadString(s);s=delern(s);

     s.TrimLeft();s.TrimRight();
     if (s.GetLength()<4){continue;}


//////////////////////////////////////
     Split(s,b,bl,"\t");

     s=b[1];
     hao=s;
////////////////////////////////////////
     srcfile=buypath+padstrcisu(s,4,"0",0)+".txt";
     dwAttr = ::GetFileAttributes(srcfile); 
     if (dwAttr != 0xffffffff){
       targetfile=bpath+padstrcisu(s,4,"0",0)+".txt";
       CopyFile(srcfile,targetfile,0);
     }

     srcfile=dirpath+"yilou\\y"+padstrcisu(s,4,"0",0)+".txt";
     dwAttr = ::GetFileAttributes(srcfile); 
     if (dwAttr != 0xffffffff){
       targetfile=ypath+"y"+padstrcisu(s,4,"0",0)+".txt";
       CopyFile(srcfile,targetfile,0);
     }


////////////////////////////////////////////////////
     finy.Open(srcfile, CFile::modeRead);
     finy.ReadString(t);t=delern(t);
     finy.Close();
     Split(t,b,bl,"\t");
           
     wr=padstrcisu(b[0],4,"0",0)+"\t"+hao+"\r\n";
     outy3.Write(wr,wr.GetLength());
     wr=padstrcisu(b[1],4,"0",0)+"\t"+hao+"\r\n";
     outy4.Write(wr,wr.GetLength());
     wr=padstrcisu(b[2],4,"0",0)+"\t"+hao+"\r\n";
     outy5.Write(wr,wr.GetLength());



////////////////////////////////////////////////



   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   outy3.Close();outy4.Close();outy5.Close();
   sortafileztoa(yilou3);sortafileztoa(yilou4);sortafileztoa(yilou5);
/////////////////////////////////////////////////////////////////////////////////////////////
 
}






void CMy115backDlg::makebuyfile(CString datafile) 
{
   int i,j,k,pos,qisu,bl;
   CString s,beginqi,qi,dirpath,b[100],wr;
   CStdioFile fin,out;
   fin.Open(datafile, CFile::modeRead);
   fin.ReadString(s);s=delern(s);
   pos=s.Find("-");
   beginqi=s.Left(pos);
   qisu=atoi(s.Mid(pos+1));
   if (qisu==0){return;}
   CString **buyzu=new CString *[qisu];
   for (i=0;i<qisu;i++){
     *(buyzu+i)=new CString [m_we];
   }
   for (i=0;i<qisu;i++){
     fin.ReadString(s);s=delern(s);     
     Split(s,b,bl,"|");
     for (j=0;j<m_we;j++){
       buyzu[i][j]=b[j];
     }
   }
   fin.Close();

   pos=datafile.Find("\\buy\\");
   dirpath=datafile.Left(pos);
   pos=dirpath.ReverseFind('\\');
////////////////////////////////////////
   dirpath=dirpath.Left(pos);
   pos=dirpath.ReverseFind('\\');
////////////////////////////////////////
   dirpath=dirpath.Left(pos+1)+"tz\\";
   if(_access(dirpath, 0) == -1){_mkdir(dirpath);}
   CString mdir=datafile.Left(datafile.GetLength()-4);
   mdir.Replace(":","-");
   mdir.Replace("\\","-");
   mdir+="\\";
   mdir=dirpath+mdir;
   if(_access(mdir, 0) == -1){_mkdir(mdir);}

   CString mydir[3];
   for (i=0;i<3;i++){
      mydir[i]=mdir+Cstr(i+3)+"\\";  
     if(_access(mydir[i], 0) == -1){_mkdir(mydir[i]);}

   }
   
   CString tzfile;
   for (i=0;i<3;i++){
     qi=beginqi;
     for (j=0;j<qisu;j++){
       tzfile=mydir[i]+qi+".txt";
       out.Open(tzfile,CFile::modeCreate|CFile::modeWrite);
       for (k=0;k<m_we;k++){
         wr=buyzu[j][k].Left(3*i+8)+";\r\n";
         out.Write(wr,wr.GetLength());
       }
       out.Close();
       qi=qijia1(qi);
     }
   }
   for (i=0;i<qisu;i++){delete[] buyzu[i];}
   delete[] buyzu;
}





























void CMy115backDlg::OnButton48() 
{
   if (JieMian!=103){jiemian(103);return;}
   setbutton(FALSE);
   UpdateData(TRUE); 
   copydirectory(m_dfile,m_bfile);
  
   MessageBox("程序结束!");setbutton(TRUE);	
}







void CMy115backDlg::getdlcbuydir(CString dirpath,CString new_type,CString new_a_type,int new_num,int new_yilou,int new_x,int new_y,int new_z)
{
   
   CString srcpath,targetpath,srchead;
   targetpath=dirpath+"tonew\\"+new_type+Cstr(new_num)+"_"+Cstr(new_x)+"."+Cstr(new_y)+"."+Cstr(new_z)+"\\";
   srchead=dirpath+Cstr(new_x)+"\\dlc"+Cstr(new_y)+"\\abuy\\";
   if (new_type=="a" && new_num<5){
      srcpath=srchead+"abuyyilou5\\";     
   }

   if (new_type=="a" && new_num==5){
      if (new_a_type=="b3"){srcpath=srchead+"abuybyilou3\\";}  
      if (new_a_type=="b4"){srcpath=srchead+"abuybyilou4\\";}  
      if (new_a_type=="y3"){srcpath=srchead+"abuyyilou3\\";}  
      if (new_a_type=="y4"){srcpath=srchead+"abuyyilou4\\";}  
   }
   if (new_type=="b"){
      switch(new_num){
        case 3:
          srcpath=srchead+"abuybyilou3\\";  
          break;
        case 4:
          srcpath=srchead+"abuybyilou4\\";  
          break;
        case 5:
          srcpath=srchead+"abuybyilou5\\";  
          break; 
      }        
   }

   if (new_type=="y"){
      switch(new_num){
        case 3:
          srcpath=srchead+"abuyyilou3\\";  
          break;
        case 4:
          srcpath=srchead+"abuyyilou4\\";  
          break;
        case 5:
          srcpath=srchead+"abuyyilou5\\";  
          break; 
      }        
   }
   copydirectory_tonew(srcpath,targetpath,new_z);   
   makebuyfilenew(dirpath,new_type,new_num,new_x,new_y,new_z);
}





void CMy115backDlg::OnButton29() 
{

  
  if (JieMian!=27){jiemian(27);return;}  
  setbutton(FALSE);
  UpdateData(TRUE);
  MessageBox("程序结束!");setbutton(TRUE);
}









void CMy115backDlg::makebuyfilenew(CString dirpath,CString new_type,int new_num,int new_x,int new_y,int new_z) 
{
   CString datafile;
   datafile=dirpath+Cstr(new_x)+"\\dlc"+Cstr(new_y)+"\\buy\\"+padstrcisu(Cstr(new_z),4,"0",0)+".txt";

   dirpath=dirpath+"tz\\";
   if(_access(dirpath, 0) == -1){_mkdir(dirpath);}
   
   CString mdir=dirpath+new_type+Cstr(new_num)+"_"+Cstr(new_x)+"."+Cstr(new_y)+"."+Cstr(new_z)+"\\";
   if(_access(mdir, 0) == -1){_mkdir(mdir);}
   else {return;}

   int i,j,k,pos,qisu,bl;
   CString s,beginqi,qi,b[100],wr;
   CStdioFile fin,out;
   fin.Open(datafile, CFile::modeRead);
   fin.ReadString(s);s=delern(s);
   pos=s.Find("-");
   beginqi=s.Left(pos);
   qisu=atoi(s.Mid(pos+1));
   if (qisu==0){return;}
   CString **buyzu=new CString *[qisu];
   for (i=0;i<qisu;i++){
     *(buyzu+i)=new CString [m_we];
   }
   for (i=0;i<qisu;i++){
     fin.ReadString(s);s=delern(s);     
     Split(s,b,bl,"|");
     for (j=0;j<m_we;j++){
       buyzu[i][j]=b[j];
     }
   }
   fin.Close();


////////////////////////////////////////
////////////////////////////////////////

   CString mydir[3];
   for (i=0;i<3;i++){
      mydir[i]=mdir+Cstr(i+3)+"\\";  
     if(_access(mydir[i], 0) == -1){_mkdir(mydir[i]);}

   }
   
   CString tzfile;
   for (i=0;i<3;i++){
     qi=beginqi;
     for (j=0;j<qisu;j++){
       tzfile=mydir[i]+qi+".txt";
       out.Open(tzfile,CFile::modeCreate|CFile::modeWrite);
       for (k=0;k<m_we;k++){
         wr=buyzu[j][k].Left(3*i+8)+";\r\n";
         out.Write(wr,wr.GetLength());
       }
       out.Close();
       qi=qijia1(qi);
     }
   }
   for (i=0;i<qisu;i++){delete[] buyzu[i];}
   delete[] buyzu;
}




void CMy115backDlg::OnButton27() 
{


  if (JieMian!=25){jiemian(25);return;}  
  tuichu=0;
  setbutton(FALSE);
  UpdateData(TRUE);
  DWORD dwAttr;
  int lei=m_num;
  int i,j,pos,n,bl,mql=m_ql,mwe=m_we;
  CString dirpath,s,t,wr;
  pos=m_dfile.ReverseFind('\\');
  dirpath=m_dfile.Left(pos+1);

  if (lei==9){

    backtohistry(dirpath,atoi(m_mo));
    setbutton(TRUE);return;
  }

  if (lei==8){
    dwAttr = ::GetFileAttributes(m_dfile);
    if (dwAttr == 0xffffffff){GetDlgItem(idc_jingdu)->SetWindowText("无数据文件!");setbutton(TRUE);return;}

    if (m_dfile.Find("\\buy\\")<0){GetDlgItem(idc_jingdu)->SetWindowText("不是buy目录!");setbutton(TRUE);return;}
    makebuyfile(m_dfile);
    setbutton(TRUE);return;
  }
  
  CString mpath,tstr,qihao,b[10];
  CString datafile=dirpath+"45.txt",fdatafile,jingdus="",zcansufile=dirpath+"zcansu.txt";
  int dirb=m_mas,dirsu=m_qmas;
  dwAttr = ::GetFileAttributes(datafile);
  if (dwAttr == 0xffffffff){GetDlgItem(idc_jingdu)->SetWindowText("无数据文件!");setbutton(TRUE);return;}
  if (lei==7){
    DoEvents();
    preparefirst(datafile,m_ql,m_qmas);
    DoEvents();

    setbutton(TRUE);return;
  }
  


  CStdioFile fin,out,outb,outc,outy,outa;
  bool canflag=false;
  dwAttr = ::GetFileAttributes(zcansufile);
  if (dwAttr != 0xffffffff){canflag=true;}
  clock_t begin=clock();
  int shijian,hour,min,sec;
  CString abuydir,yfile,tjpath;
  
  if (lei==1 || lei==6){
    fin.Open(datafile, CFile::modeRead);
    fin.ReadString(s);s=delern(s);fin.Close();    
    pos=s.Find("\t");
    s=s.Mid(pos+1);
    pos=s.Find("\t");
    qihao=s.Left(pos);
    if (lei==1){
      tjpath=dirpath+"tj\\";
      if(_access(tjpath, 0) == -1){_mkdir(tjpath);} 
    }
  }




  int yi[3],byi[3],allyi[3];//ci[3],
  for (j=0;j<3;j++){yi[j]=0;byi[j]=0;allyi[j]=0;}//ci[j]=0;
  CString yihao[3],byihao[3],allyihao[3];//cihao[3],
  for (j=0;j<3;j++){yihao[j]="00.0000  ";byihao[j]="00.0000  ";allyihao[j]="00.000000";} //cihao[j]="00.0000";

  int yiall[3],yiallhao[3];
  for (i=0;i<3;i++){yiall[i]=0;yiallhao[i]=0;}

  int yimax[3],yimaxhao[3];
  CString yimaxqi[3];
  for (i=0;i<3;i++){yimax[i]=0;yimaxhao[i]=0;yimaxqi[i]="00000000";}

  if (lei==10){
    adeletefileofdir_(dirpath+"tj\\");
    DeleteFile(dirpath+"mdir.txt");
  }

  for (i=dirb;i<dirb+dirsu;i++){


    mpath=dirpath+"dlc"+Cstr(i)+"\\";
    DoEvents();


    if (lei==4 || lei==10){


      if (lei==4){
        adeletefileofdir(mpath+"abuy\\");
        //adeletefileofdir(mpath+"yilou3\\");
        //adeletefileofdir(mpath+"yilou4\\");
        //adeletefileofdir(mpath+"yilou5\\");
      }
      else {
        adeletefileofdir_(mpath+"yilou\\");
        adeletefileofdir_(mpath+"yilou3\\");
        adeletefileofdir_(mpath+"yilou4\\");
        adeletefileofdir_(mpath+"yilou5\\");
        adeletefileofdir_(mpath+"tjsrc\\");
        adeletefileofdir_(mpath+"buy\\");
        
      }


      continue;
    }
    t=Cstr(i)+"......";

    shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
    hour=shijian/3600;
    n=shijian-hour*3600;
    min=n/60;
    sec=n-60*min;
    tstr="["+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec)+"]";
    
    GetDlgItem(idc_jingdu)->SetWindowText(t+jingdus+tstr);
    
    fdatafile=mpath+"45.txt";
    if(_access(mpath, 0) == -1){
      if (lei==2){ _mkdir(mpath);}
      else {continue;}
    } 
    
    CopyFile(datafile,fdatafile,0);
    if (canflag){CopyFile(zcansufile,mpath+"zcansu.txt",0);}



///////////////////////////////////////////////////////////////
    abuydir=mpath+"abuy\\";

////////////////////////////////////////////////////////////////

    JieMian=-1;
    jiemian(26);
    m_mo=Cstr(lei);
    m_dfile=fdatafile;   
    m_we=mwe;
    if (lei==6){m_mo="1";m_dfile=abuydir+"45.txt";}
    if (lei==2){m_ql=mql;}    
    UpdateData(FALSE);
    DoEvents();
    OnButton28();
    DoEvents();




    if (lei!=1 && lei!=6){continue;}
    ////////////////////////////////////////


    if (lei==6){
      int k;
      for (j=0;j<3;j++){



         /////////yi////////////////////////////
         yfile=abuydir+"abuyyilou"+Cstr(j+3)+"\\yilou"+Cstr(j+3)+".txt";
         dwAttr = ::GetFileAttributes(yfile);
         if (dwAttr != 0xffffffff){
            fin.Open(yfile,CFile::modeRead);
            //if (fin.GetPosition()!=fin.GetLength()){
            if (fin.GetLength()>0){
              fin.ReadString(s);s=delern(s);fin.Close();
              pos=s.Find("\t");
              n=atoi(s.Left(pos));
              if (n>yi[j]){yi[j]=n;yihao[j]=padstrcisu(Cstr(i),2,"0",0)+"."+s.Mid(pos+1,4)+"  ";}
            }
            else {fin.Close();DeleteFile(yfile);}
         }


         for (k=0;k<3;k++){
           if (j==k){continue;}
           if (j<2 && k<2){continue;}
           yfile=abuydir+"abuyyilou"+Cstr(j+3)+"\\yilou"+Cstr(k+3)+".txt";
           dwAttr = ::GetFileAttributes(yfile);
           if (dwAttr != 0xffffffff){
              fin.Open(yfile,CFile::modeRead);              
              if (fin.GetLength()>0){
                fin.ReadString(s);s=delern(s);fin.Close();
                pos=s.Find("\t");
                n=atoi(s.Left(pos));
                if (n>allyi[k]){allyi[k]=n;allyihao[k]=padstrcisu(Cstr(i),2,"0",0)+"."+s.Mid(pos+1,4)+"y"+Cstr(j+3);}
              }
              else {fin.Close();DeleteFile(yfile);}
           }
         }




         /////////byi////////////////////////////
         yfile=abuydir+"abuybyilou"+Cstr(j+3)+"\\yilou"+Cstr(j+3)+".txt";
         dwAttr = ::GetFileAttributes(yfile);
         if (dwAttr != 0xffffffff){
            fin.Open(yfile,CFile::modeRead);
            if (fin.GetLength()>0){
              fin.ReadString(s);s=delern(s);fin.Close();
              pos=s.Find("\t");
              n=atoi(s.Left(pos));
              if (n>byi[j]){byi[j]=n;byihao[j]=padstrcisu(Cstr(i),2,"0",0)+"."+s.Mid(pos+1,4)+"  ";}
            }
            else {fin.Close();DeleteFile(yfile);}
         }


         for (k=0;k<3;k++){
           if (k<2){continue;}
           if (j==k){continue;}           
           yfile=abuydir+"abuybyilou"+Cstr(j+3)+"\\yilou"+Cstr(k+3)+".txt";
           dwAttr = ::GetFileAttributes(yfile);
           if (dwAttr != 0xffffffff){
              fin.Open(yfile,CFile::modeRead);

              if (fin.GetLength()>0){



                fin.ReadString(s);s=delern(s);fin.Close();



                pos=s.Find("\t");
                n=atoi(s.Left(pos));
                if (n>allyi[k]){allyi[k]=n;allyihao[k]=padstrcisu(Cstr(i),2,"0",0)+"."+s.Mid(pos+1,4)+"b"+Cstr(j+3);}
              }
              else {fin.Close();DeleteFile(yfile);}
           }
         }



      }//for (j=0;j<3;j++){
      continue;

     }////////if (lei==6){




    ////////////////////////////////////////
    CString t1="";
    for (j=0;j<3;j++){
      dwAttr = ::GetFileAttributes(mpath+"maxyilou"+Cstr(j+3)+"qi.txt");
      if (dwAttr != 0xffffffff){
        fin.Open(mpath+"maxyilou"+Cstr(j+3)+"qi.txt",CFile::modeRead);
        if (fin.GetLength()>0){
          fin.ReadString(s);s=delern(s);fin.Close();
          Split(s,b,bl,"\t");
          n=atoi(b[1]);
          if (yimax[j]<n){yimax[j]=n;yimaxhao[j]=i*10000+atoi(b[2]);yimaxqi[j]=b[0];}          
        }
        else {fin.Close();DeleteFile(mpath+"maxyilou"+Cstr(j+3)+"qi.txt");}
      }
  
      dwAttr = ::GetFileAttributes(mpath+"yilou"+Cstr(j+3)+".txt");
      if (dwAttr != 0xffffffff){
        fin.Open(mpath+"yilou"+Cstr(j+3)+".txt",CFile::modeRead);
        if (fin.GetLength()>0){
          fin.ReadString(s);s=delern(s);fin.Close();         
          Split(s,b,bl,"\t");
          n=atoi(b[0]);
          if (yiall[j]<n){yiall[j]=n;yiallhao[j]=i*10000+atoi(b[1]);}
        }
        else {fin.Close();DeleteFile(mpath+"yilou"+Cstr(j+3)+".txt");}
      }
      t1+="y"+Cstr(j+3)+"-"+padstrcisu(Cstr(yiall[j]),4,"0",0)+"-";
      t1+=padstrcisu(Cstr(yiallhao[j]/10000),4,"0",0)+"."+padstrcisu(Cstr(yiallhao[j]%10000),4,"0",0)+"  ";
     
//////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

    }

    jingdus=t1;

    DoEvents();
    shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
    hour=shijian/3600;
    n=shijian-hour*3600;
    min=n/60;
    sec=n-60*min;
    tstr="["+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec)+"]";

    GetDlgItem(idc_jingdu)->SetWindowText(t+jingdus+tstr);
    DoEvents();

  }     

  if (lei==1){
    out.Open(dirpath+"mdir.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    out.SeekToEnd(); 
    wr=qihao+":"+jingdus+"\r\n";
    out.Write(wr,wr.GetLength());
    out.Close();

    out.Open(tjpath+"nowyilou.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);  
    out.SeekToEnd(); 
    wr=qihao+":"+jingdus+"\r\n";
    out.Write(wr,wr.GetLength());    
    out.Close();
 
    for (i=0;i<3;i++){
      out.Open(tjpath+"maxyilouqi"+Cstr(i+3)+".txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);  
      out.SeekToEnd(); 
      wr=yimaxqi[i]+"\t"+padstrcisu(Cstr(yimax[i]),4,"0",0)+"\t"+padstrcisu(Cstr(yimaxhao[i]/10000),4,"0",0)+"."+
         padstrcisu(Cstr(yimaxhao[i]%10000),4,"0",0)+"\r\n";
      out.Write(wr,wr.GetLength());
      out.Close();
      sortafileztoa(tjpath+"maxyilouqi"+Cstr(i+3)+".txt");
   }

    for (i=0;i<3;i++){
      CString mfile=tjpath+"maxyilouqi"+Cstr(i+3)+".txt";
      out.Open(mfile,CFile::modeRead);  
      n=0;
      while(out.ReadString(s)){
        n++;
      }       
      out.Close();
      if (n==0){continue;}
      CString *zu=new CString [n];

      out.Open(mfile,CFile::modeRead);  
      j=0;
      while(out.ReadString(s)){
        s=delern(s); 
        Split(s,b,bl,"\t");
        zu[j]=b[1]+"#"+s;
        j++;
      }       
      out.Close();
      paixuztoa(zu,n);
      out.Open(tjpath+"maxyilounum"+Cstr(i+3)+".txt",CFile::modeCreate|CFile::modeWrite);   
      for (j=0;j<n;j++){ 
        s=zu[j];
        pos=s.Find("#");
        s=s.Mid(pos+1)+"\r\n";
        out.Write(s,s.GetLength());
      }
      out.Close();
      delete[] zu;

    }

  }

  if (lei==6){
   
    out.Open(dirpath+"mdir.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    out.SeekToEnd(); 
    CString wr;
    wr="";
    for (i=0;i<3;i++){
      wr+="y"+Cstr(i+3)+"-"+padstrcisu(Cstr(yi[i]),4,"0",0)+"-"+yihao[i]+"   ";
    }
    wr=qihao+":"+wr+"\r\n";
    out.Write(wr,wr.GetLength());
//////////////////////////////////////////////////////////////////////////////////////////////////////
    outy.Open(dirpath+"mdiry.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    outy.SeekToEnd(); 
    outy.Write(wr,wr.GetLength());

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
    wr="";
    for (i=0;i<3;i++){
      wr+="b"+Cstr(i+3)+"-"+padstrcisu(Cstr(byi[i]),4,"0",0)+"-"+byihao[i]+"   ";
    }
    wr=qihao+":"+wr+"\r\n";
    out.Write(wr,wr.GetLength());
///////////////////////////////////////////////////////////////////////////////////////////
    outb.Open(dirpath+"mdirb.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    outb.SeekToEnd(); 
    outb.Write(wr,wr.GetLength());


///////////////////////////////////////////////////////////////////////////
   
    wr="";
    for (i=0;i<3;i++){
      wr+="a"+Cstr(i+3)+"-"+padstrcisu(Cstr(allyi[i]),4,"0",0)+"-"+allyihao[i]+"   ";
    }
    wr=qihao+":"+wr+"\r\n";
    out.Write(wr,wr.GetLength());
///////////////////////////////////////////////////////////////////////////////
    outa.Open(dirpath+"mdira.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    outa.SeekToEnd(); 
    outa.Write(wr,wr.GetLength());
    
    out.Close();outy.Close();outb.Close();outc.Close();outa.Close();
    
    DoEvents();

  }

  JieMian=-1;
  jiemian(25);
  m_dfile=datafile;
  UpdateData(FALSE);

  setbutton(TRUE);return;




  
}






void CMy115backDlg::preparefirst(CString datafile,int tqs,int dirsu) 
{

   clock_t begin=clock();
   int shijian,hour,min,sec;   
   int i,n;
   CString timestr="";


   for (i=1;i<6;i++){


     m_num=i;
     m_dfile=datafile;

     if (i==2){m_ql=tqs;}
     m_qmas=dirsu;
     UpdateData(FALSE);   
     DoEvents();

     OnButton27();



     DoEvents(); 

     shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
     hour=shijian/3600;
     n=shijian-hour*3600;
     min=n/60;
     sec=n-60*min;
     timestr+=Cstr(i)+"["+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec)+"]-";


  }
  GetDlgItem(idc_jingdu)->SetWindowText(timestr);

}


void CMy115backDlg::getdlcbuyfile(CString dirpath,CString qihao,CString datas[],int ubound) 
{

  int ZSU=getcansu(dirpath,1);
  CString ydirpath=dirpath;
  dirpath+="buy\\";
  if(_access(dirpath, 0) == -1){_mkdir(dirpath);} 
  CStdioFile fin,out;
  int filenum=0,i,j1,k,qixu;
  int buynum=m_we;  
  CString outfile,s,s1,s2,c,qi,t,wr;

///////////////////////////////////////////
  for (i=3;i<6;i++){
    DeleteFile(dirpath+"yilou"+Cstr(i)+".txt");
    DeleteFile(dirpath+"byilou"+Cstr(i)+".txt");
    if (i!=5){DeleteFile(dirpath+"zero"+Cstr(i)+"num.txt");}
    else {DeleteFile(dirpath+"zeronum.txt");}
  }


/////////////////////////////////////////////

/////////////////////////////////////
  
  CString strDir=ydirpath,bqi;
  CString szDir = strDir,buyfile,nake; 
  CFileFind ff; 
  szDir += "*.*"; 
  

  small **buyzu=new small *[buynum];
  for (i=0;i<buynum;i++){
    *(buyzu+i)=new small[5];
  } 

  small **tbuyzu=new small *[buynum];
  for (i=0;i<buynum;i++){
    *(tbuyzu+i)=new small[5];
  } 

  int a0[8],a1[8],a2[8],a3[8];
  a0[0]=1;a0[1]=2;a0[2]=3;a0[3]=4;a0[4]=5;a0[5]=6;a0[6]=7;a0[7]=8;
  a1[0]=4;a1[1]=5;a1[2]=6;a1[3]=7;a1[4]=8;a1[5]=9;a1[6]=10;a1[7]=11;
  a2[0]=1;a2[1]=2;a2[2]=3;a2[3]=7;a2[4]=8;a2[5]=9;a2[6]=10;a2[7]=11;
  a3[0]=1;a3[1]=2;a3[2]=3;a3[3]=4;a3[4]=5;a3[5]=6;a3[6]=10;a3[7]=11;



  CString beginqi=qijia1(qihao);
  k=buynum;
  bool uflag=(ubound>1000);
  for (i=0;i<ZSU;i++){
    qi=beginqi;
    outfile=dirpath+padstrcisu(Cstr(i),4,"0",0)+".txt";
    out.Open(outfile,CFile::modeCreate|CFile::modeWrite);
    wr=qi+"-"+Cstr(m_ql)+"\r\n";
    out.Write(wr,wr.GetLength());
    for (qixu=0;qixu<m_ql;qixu++){
      if (uflag){
        for (int ni=0;ni<buynum;ni++){
        for (int nj=0;nj<5;nj++){
          buyzu[ni][nj]=atoi(datas[ni+m_ql-qixu-1].Mid(3*nj,2));          
        }}
      }
      else {
        for (int ni=0;ni<buynum;ni++){
        for (int nj=0;nj<5;nj++){
          buyzu[ni][nj]=rand()%11+1;
        }}
      }
      dlctoubianrand(buyzu,k,tbuyzu,a0,a1,a2,a3);
      if (qixu>0){qi=qijia1(qi);}
      s="";
      for (j1=0;j1<k;j1++){ 
        t.Format("%.2d",tbuyzu[j1][0]);
        for (int ai=1;ai<5;ai++){           
          c.Format("%.2d",tbuyzu[j1][ai]);
          t+=" "+c;            
        }   
          
        t+=";|";
        s+=t;           
      }
      s=s.Left(s.GetLength()-1)+"\r\n";
      out.Write(s,s.GetLength());
    }//for (qixu=0;qixu<m_ql;qixu++){
  
    out.Close();
  }//for (i=0;i<ZSU;i++){
//////////////////////////////////////////

//////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


  
  for(i=0;i<buynum;i++){delete[] buyzu[i];delete[] tbuyzu[i];}
  delete[] buyzu;delete[] tbuyzu;
  
}






void CMy115backDlg::f27(CString qihao[],CString datas[],int ubound) 
{


  if (JieMian!=25){jiemian(25);return;}  
  tuichu=0;
  setbutton(FALSE);
  UpdateData(TRUE);
  DWORD dwAttr;
  int lei=m_num;
  int i,j,pos,n,bl,mql=m_ql,mwe=m_we;
  CString dirpath,s,t,wr;
  pos=m_dfile.ReverseFind('\\');
  dirpath=m_dfile.Left(pos+1);

  if (lei==9){
    backtohistry(dirpath,atoi(m_mo));
    setbutton(TRUE);return;
  }


  
  CString mpath,tstr,nowqihao,b[10];
  CString datafile=dirpath+"45.txt",fdatafile,jingdus="",zcansufile=dirpath+"zcansu.txt";
  int dirb=m_mas,dirsu=m_qmas;
  
  if (lei==7){
    DoEvents();
    preparefirst_b(datafile,m_ql,m_qmas,qihao,datas,ubound);
    DoEvents();

    setbutton(TRUE);return;
  }
  


  CStdioFile fin,out,outb,outc,outy,outa;
  bool canflag=false;
  dwAttr = ::GetFileAttributes(zcansufile);
  if (dwAttr != 0xffffffff){canflag=true;}
  clock_t begin=clock();
  int shijian,hour,min,sec;
  CString abuydir,yfile,tjpath;
  
  if (lei==1 || lei==6){    
    nowqihao=qihao[0];
    if (lei==1){
      tjpath=dirpath+"tj\\";
      if(_access(tjpath, 0) == -1){_mkdir(tjpath);} 
    }
  }




  int yi[3],byi[3],allyi[3];//ci[3],
  for (j=0;j<3;j++){yi[j]=0;byi[j]=0;allyi[j]=0;}//ci[j]=0;
  CString yihao[3],byihao[3],allyihao[3];//cihao[3],
  for (j=0;j<3;j++){yihao[j]="00.0000  ";byihao[j]="00.0000  ";allyihao[j]="00.000000";} //cihao[j]="00.0000";

  int yiall[3],yiallhao[3];
  for (i=0;i<3;i++){yiall[i]=0;yiallhao[i]=0;}

  int yimax[3],yimaxhao[3];
  CString yimaxqi[3];
  for (i=0;i<3;i++){yimax[i]=0;yimaxhao[i]=0;yimaxqi[i]="00000000";}

  if (lei==10){
    adeletefileofdir_(dirpath+"tj\\");
    DeleteFile(dirpath+"mdir.txt");
  }

  for (i=dirb;i<dirb+dirsu;i++){


    mpath=dirpath+"dlc"+Cstr(i)+"\\";
    DoEvents();


    if (lei==4 || lei==10){


      if (lei==4){
        adeletefileofdir(mpath+"abuy\\");
      }
      else {
        adeletefileofdir_(mpath+"yilou\\");
        adeletefileofdir_(mpath+"yilou3\\");
        adeletefileofdir_(mpath+"yilou4\\");
        adeletefileofdir_(mpath+"yilou5\\");
        adeletefileofdir_(mpath+"tjsrc\\");
        adeletefileofdir_(mpath+"buy\\");
        
      }


      continue;
    }
    t=Cstr(i)+"......";

    shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
    hour=shijian/3600;
    n=shijian-hour*3600;
    min=n/60;
    sec=n-60*min;
    tstr="["+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec)+"]";
    
    GetDlgItem(idc_jingdu)->SetWindowText(t+jingdus+tstr);
    
    fdatafile=mpath+"45.txt";
    if(_access(mpath, 0) == -1){
      if (lei==2){ _mkdir(mpath);}
      else {continue;}
    } 
    
    CopyFile(datafile,fdatafile,0);
    if (canflag){CopyFile(zcansufile,mpath+"zcansu.txt",0);}



///////////////////////////////////////////////////////////////
    abuydir=mpath+"abuy\\";

////////////////////////////////////////////////////////////////

    JieMian=-1;
    jiemian(26);
    m_mo=Cstr(lei);
    m_dfile=fdatafile;   
    m_we=mwe;
    if (lei==6){m_mo="1";m_dfile=abuydir+"45.txt";}
    if (lei==2){m_ql=mql;}    
    UpdateData(FALSE);
    DoEvents();
    f28(qihao,datas,ubound);
    DoEvents();




    if (lei!=1 && lei!=6){continue;}
    ////////////////////////////////////////


    if (lei==6){
      int k;
      for (j=0;j<3;j++){



         /////////yi////////////////////////////
         yfile=abuydir+"abuyyilou"+Cstr(j+3)+"\\yilou"+Cstr(j+3)+".txt";
         dwAttr = ::GetFileAttributes(yfile);
         if (dwAttr != 0xffffffff){
            fin.Open(yfile,CFile::modeRead);
            //if (fin.GetPosition()!=fin.GetLength()){
            if (fin.GetLength()>0){
              fin.ReadString(s);s=delern(s);fin.Close();
              pos=s.Find("\t");
              n=atoi(s.Left(pos));
              if (n>yi[j]){yi[j]=n;yihao[j]=padstrcisu(Cstr(i),2,"0",0)+"."+s.Mid(pos+1,4)+"  ";}
            }
            else {fin.Close();DeleteFile(yfile);}
         }


         for (k=0;k<3;k++){
           if (j==k){continue;}
           if (j<2 && k<2){continue;}
           yfile=abuydir+"abuyyilou"+Cstr(j+3)+"\\yilou"+Cstr(k+3)+".txt";
           dwAttr = ::GetFileAttributes(yfile);
           if (dwAttr != 0xffffffff){
              fin.Open(yfile,CFile::modeRead);              
              if (fin.GetLength()>0){
                fin.ReadString(s);s=delern(s);fin.Close();
                pos=s.Find("\t");
                n=atoi(s.Left(pos));
                if (n>allyi[k]){allyi[k]=n;allyihao[k]=padstrcisu(Cstr(i),2,"0",0)+"."+s.Mid(pos+1,4)+"y"+Cstr(j+3);}
              }
              else {fin.Close();DeleteFile(yfile);}
           }
         }




         /////////byi////////////////////////////
         yfile=abuydir+"abuybyilou"+Cstr(j+3)+"\\yilou"+Cstr(j+3)+".txt";
         dwAttr = ::GetFileAttributes(yfile);
         if (dwAttr != 0xffffffff){
            fin.Open(yfile,CFile::modeRead);
            if (fin.GetLength()>0){
              fin.ReadString(s);s=delern(s);fin.Close();
              pos=s.Find("\t");
              n=atoi(s.Left(pos));
              if (n>byi[j]){byi[j]=n;byihao[j]=padstrcisu(Cstr(i),2,"0",0)+"."+s.Mid(pos+1,4)+"  ";}
            }
            else {fin.Close();DeleteFile(yfile);}
         }


         for (k=0;k<3;k++){
           if (k<2){continue;}
           if (j==k){continue;}           
           yfile=abuydir+"abuybyilou"+Cstr(j+3)+"\\yilou"+Cstr(k+3)+".txt";
           dwAttr = ::GetFileAttributes(yfile);
           if (dwAttr != 0xffffffff){
              fin.Open(yfile,CFile::modeRead);

              if (fin.GetLength()>0){



                fin.ReadString(s);s=delern(s);fin.Close();



                pos=s.Find("\t");
                n=atoi(s.Left(pos));
                if (n>allyi[k]){allyi[k]=n;allyihao[k]=padstrcisu(Cstr(i),2,"0",0)+"."+s.Mid(pos+1,4)+"b"+Cstr(j+3);}
              }
              else {fin.Close();DeleteFile(yfile);}
           }
         }



      }//for (j=0;j<3;j++){
      continue;

     }////////if (lei==6){




    ////////////////////////////////////////
    CString t1="";
    for (j=0;j<3;j++){
      dwAttr = ::GetFileAttributes(mpath+"maxyilou"+Cstr(j+3)+"qi.txt");
      if (dwAttr != 0xffffffff){
        fin.Open(mpath+"maxyilou"+Cstr(j+3)+"qi.txt",CFile::modeRead);
        if (fin.GetLength()>0){
          fin.ReadString(s);s=delern(s);fin.Close();
          Split(s,b,bl,"\t");
          n=atoi(b[1]);
          if (yimax[j]<n){yimax[j]=n;yimaxhao[j]=i*10000+atoi(b[2]);yimaxqi[j]=b[0];}          
        }
        else {fin.Close();DeleteFile(mpath+"maxyilou"+Cstr(j+3)+"qi.txt");}
      }
  
      dwAttr = ::GetFileAttributes(mpath+"yilou"+Cstr(j+3)+".txt");
      if (dwAttr != 0xffffffff){
        fin.Open(mpath+"yilou"+Cstr(j+3)+".txt",CFile::modeRead);
        if (fin.GetLength()>0){
          fin.ReadString(s);s=delern(s);fin.Close();         
          Split(s,b,bl,"\t");
          n=atoi(b[0]);
          if (yiall[j]<n){yiall[j]=n;yiallhao[j]=i*10000+atoi(b[1]);}
        }
        else {fin.Close();DeleteFile(mpath+"yilou"+Cstr(j+3)+".txt");}
      }
      t1+="y"+Cstr(j+3)+"-"+padstrcisu(Cstr(yiall[j]),4,"0",0)+"-";
      t1+=padstrcisu(Cstr(yiallhao[j]/10000),4,"0",0)+"."+padstrcisu(Cstr(yiallhao[j]%10000),4,"0",0)+"  ";
     
//////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

    }

    jingdus=t1;

    DoEvents();
    shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
    hour=shijian/3600;
    n=shijian-hour*3600;
    min=n/60;
    sec=n-60*min;
    tstr="["+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec)+"]";

    GetDlgItem(idc_jingdu)->SetWindowText(t+jingdus+tstr);
    DoEvents();

  }     

  if (lei==1){
    out.Open(dirpath+"mdir.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    out.SeekToEnd(); 
    wr=nowqihao+":"+jingdus+"\r\n";
    out.Write(wr,wr.GetLength());
    out.Close();

    out.Open(tjpath+"nowyilou.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);  
    out.SeekToEnd(); 
    wr=nowqihao+":"+jingdus+"\r\n";
    out.Write(wr,wr.GetLength());    
    out.Close();
 
    for (i=0;i<3;i++){
      out.Open(tjpath+"maxyilouqi"+Cstr(i+3)+".txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);  
      out.SeekToEnd(); 
      wr=yimaxqi[i]+"\t"+padstrcisu(Cstr(yimax[i]),4,"0",0)+"\t"+padstrcisu(Cstr(yimaxhao[i]/10000),4,"0",0)+"."+
         padstrcisu(Cstr(yimaxhao[i]%10000),4,"0",0)+"\r\n";
      out.Write(wr,wr.GetLength());
      out.Close();
      sortafileztoa(tjpath+"maxyilouqi"+Cstr(i+3)+".txt");
   }

    for (i=0;i<3;i++){
      CString mfile=tjpath+"maxyilouqi"+Cstr(i+3)+".txt";
      out.Open(mfile,CFile::modeRead);  
      n=0;
      while(out.ReadString(s)){
        n++;
      }       
      out.Close();
      if (n==0){continue;}
      CString *zu=new CString [n];

      out.Open(mfile,CFile::modeRead);  
      j=0;
      while(out.ReadString(s)){
        s=delern(s); 
        Split(s,b,bl,"\t");
        zu[j]=b[1]+"#"+s;
        j++;
      }       
      out.Close();
      paixuztoa(zu,n);
      out.Open(tjpath+"maxyilounum"+Cstr(i+3)+".txt",CFile::modeCreate|CFile::modeWrite);   
      for (j=0;j<n;j++){ 
        s=zu[j];
        pos=s.Find("#");
        s=s.Mid(pos+1)+"\r\n";
        out.Write(s,s.GetLength());
      }
      out.Close();
      delete[] zu;

    }

  }

  if (lei==6){
   
    out.Open(dirpath+"mdir.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    out.SeekToEnd(); 
    CString wr;
    wr="";
    for (i=0;i<3;i++){
      wr+="y"+Cstr(i+3)+"-"+padstrcisu(Cstr(yi[i]),4,"0",0)+"-"+yihao[i]+"   ";
    }
    wr=nowqihao+":"+wr+"\r\n";
    out.Write(wr,wr.GetLength());
//////////////////////////////////////////////////////////////////////////////////////////////////////
    outy.Open(dirpath+"mdiry.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    outy.SeekToEnd(); 
    outy.Write(wr,wr.GetLength());

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
    wr="";
    for (i=0;i<3;i++){
      wr+="b"+Cstr(i+3)+"-"+padstrcisu(Cstr(byi[i]),4,"0",0)+"-"+byihao[i]+"   ";
    }
    wr=nowqihao+":"+wr+"\r\n";
    out.Write(wr,wr.GetLength());
///////////////////////////////////////////////////////////////////////////////////////////
    outb.Open(dirpath+"mdirb.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    outb.SeekToEnd(); 
    outb.Write(wr,wr.GetLength());


///////////////////////////////////////////////////////////////////////////
   
    wr="";
    for (i=0;i<3;i++){
      wr+="a"+Cstr(i+3)+"-"+padstrcisu(Cstr(allyi[i]),4,"0",0)+"-"+allyihao[i]+"   ";
    }
    wr=nowqihao+":"+wr+"\r\n";
    out.Write(wr,wr.GetLength());
///////////////////////////////////////////////////////////////////////////////
    outa.Open(dirpath+"mdira.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    outa.SeekToEnd(); 
    outa.Write(wr,wr.GetLength());
    
    out.Close();outy.Close();outb.Close();outc.Close();outa.Close();
    
    DoEvents();

  }

  JieMian=-1;
  jiemian(25);
  m_dfile=datafile;
  UpdateData(FALSE);

  setbutton(TRUE);return;




  
}


void CMy115backDlg::preparefirst_b(CString datafile,int tqs,int dirsu,CString qihao[],CString datas[],int ubound) 
{

   clock_t begin=clock();
   int shijian,hour,min,sec;   
   int i,n;
   CString timestr="";


   for (i=1;i<6;i++){


     m_num=i;
     m_dfile=datafile;

     if (i==2){m_ql=tqs;}
     m_qmas=dirsu;
     UpdateData(FALSE);   
     DoEvents();

     f27(qihao,datas,ubound);



     DoEvents(); 

     shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
     hour=shijian/3600;
     n=shijian-hour*3600;
     min=n/60;
     sec=n-60*min;
     timestr+=Cstr(i)+"["+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec)+"]-";


  }
  GetDlgItem(idc_jingdu)->SetWindowText(timestr);

}




void CMy115backDlg::f28(CString qihao[],CString datas[],int ubound) 
{
   if (JieMian!=26){jiemian(26);return;}  
   setbutton(FALSE);
   UpdateData(TRUE);
   DWORD dwAttr;
//////////////////////////////////////////////////
   if (m_dfile.GetLength()==0){setbutton(TRUE);return;} 
   int bl,pos,i;
   CString s,t,dirpath,datafile,ba[8];
   CStdioFile out,fin;



   pos=m_dfile.ReverseFind('\\');
   dirpath=m_dfile.Left(pos+1);
   datafile=dirpath+"45.txt";
   pos=dirpath.Find("\\abuy");
   if (pos>=0){
     datafile=dirpath.Left(pos+1)+"45.txt";
   }
   


   if (m_mo=="3"){
     deletenouseyiloufile(dirpath);
     setbutton(TRUE);	return;
   }

   if (m_mo=="4"){
     adeletefileofdir(dirpath+"abuy\\");
     setbutton(TRUE);	return;
   }



   if (m_mo=="5"){
     fin.Open(datafile,CFile::modeRead);
     fin.ReadString(s);s=delern(s);fin.Close();
     Split(s,ba,bl,"\t");
     if (ba[1].Right(2)=="78"){dlccopybuyfile(dirpath,0);}
     else {dlccopybuyfile(dirpath,1);} 

     setbutton(TRUE);	return;
   }



/////////////////////////////////////////////////////
   if (m_mo=="2"){

     getdlcbuyfile(dirpath,qihao[0],datas,ubound);
 
   }

   if (m_mo=="1" && dirpath.Find("\\tonew")>0){
     CString szDir = dirpath,mpath,tmp;
     int ma[3],mb[3],my[3],yi,n;
     CString mahao[3],mbhao[3],myhao[3],type,hao,yfile,wei,s,ihao,qi,wr;
     qi=qihao[0];
     CStdioFile in,out,outa,outb,outy;
     for (i=0;i<3;i++){
       ma[i]=mb[i]=my[i]=0;
       mahao[i]=mbhao[i]=myhao[i]="x.xx.xxx";
     }     
     szDir += "*.*"; 
     CFileFind ff;
     bool res = ff.FindFile(szDir);  
     while( res )
     { 
       res = ff.FindNextFile(); 
       tmp=ff.GetFilePath();
       mpath = tmp+"\\"; 
       if (ff.IsDots()){continue;}      
       if(ff.IsDirectory()){  
         pos=tmp.ReverseFind('\\');
         tmp=tmp.Mid(pos+1);
         pos=tmp.Find("_");
         type=tmp.Left(pos);hao=tmp.Mid(pos+1);     
         wei=type.Mid(1); n=atoi(wei)-3; 
         dlcrefresh(mpath,qihao,datas,ubound);

         yfile=mpath+"yilou"+wei+".txt";
         dwAttr = ::GetFileAttributes(yfile); 
         if (dwAttr == 0xffffffff){continue;}
         fin.Open(yfile,CFile::modeRead);
         fin.ReadString(s);s=delern(s);fin.Close();
         s.TrimRight();
         pos=s.Find('\t');
         yi=atoi(s.Left(pos));ihao=s.Mid(pos+1);
         ihao=Cstr(atoi(ihao));
         pos=hao.ReverseFind('.');
         if (hao.Mid(pos+1)!=ihao){continue;}
         if (type.Left(1)=="a"){
           if (yi>ma[n]){ma[n]=yi;mahao[n]=hao;}
         }
         else if (type.Left(1)=="b"){
           if (yi>mb[n]){mb[n]=yi;mbhao[n]=hao;}
         }
         else if (type.Left(1)=="y"){
           if (yi>my[n]){my[n]=yi;myhao[n]=hao;}
         }

       }
     }
     ff.Close();
       
     out.Open(dirpath+"mdir.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
     out.SeekToEnd();
     outa.Open(dirpath+"mdira.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
     outa.SeekToEnd();
     outb.Open(dirpath+"mdirb.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
     outb.SeekToEnd();    
     outy.Open(dirpath+"mdiry.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
     outy.SeekToEnd();
     wr=qi+":";
     for (i=0;i<3;i++){
       wr+="a"+Cstr(i+3)+"-"+padstrcisu(Cstr(ma[i]),4,"0",0)+"-"+padstrcisu(mahao[i],10," ",1);
     }
     wr+="\r\n";
     out.Write(wr,wr.GetLength());outa.Write(wr,wr.GetLength());
     wr=qi+":";
     for (i=0;i<3;i++){
       wr+="b"+Cstr(i+3)+"-"+padstrcisu(Cstr(mb[i]),4,"0",0)+"-"+padstrcisu(mbhao[i],10," ",1);
     }
     wr+="\r\n";
     out.Write(wr,wr.GetLength());outb.Write(wr,wr.GetLength());
     wr=qi+":";
     for (i=0;i<3;i++){
       wr+="y"+Cstr(i+3)+"-"+padstrcisu(Cstr(my[i]),4,"0",0)+"-"+padstrcisu(myhao[i],10," ",1);
     }
     wr+="\r\n";
     out.Write(wr,wr.GetLength());outy.Write(wr,wr.GetLength());
     out.Close();outa.Close();outb.Close();outy.Close();
   }

   if (m_mo=="1" && dirpath.Find("\\tonew")<0){  
     pos=dirpath.Find("\\abuy");  
     i=0; 
     if (pos>=0){
       i++;
       s=dirpath.Mid(pos+5);
       if (s.Find("\\abuy")>=0){i++;}
     }  

     if (i==0 || i==2){

       int r=dlcrefresh(dirpath,qihao,datas,ubound);

       if (i==0 && r==0){dlczeroall(dirpath);}
     }
     else {
       pos=dirpath.Find("\\abuy");
       CString p=dirpath.Left(pos+1),mpath; 

       s=dirpath.Mid(pos+1);


       p=p+s;

       for (i=3;i<6;i++){
         mpath=p+"abuy"+Cstr(i)+"\\";
         if(_access(mpath, 0) != -1){dlcrefresh(mpath,qihao,datas,ubound);}

         mpath=p+"abuyyilou"+Cstr(i)+"\\";
         if(_access(mpath, 0) != -1){dlcrefresh(mpath,qihao,datas,ubound);}

         mpath=p+"abuybyilou"+Cstr(i)+"\\";
         if(_access(mpath, 0) != -1){dlcrefresh(mpath,qihao,datas,ubound);}

       }
     }    
 
   }





   
///////////////////////////////////////////////////////

   
  
 



//////////////////////////////////////////////////
   setbutton(TRUE);	
 
}




void CMy115backDlg::copydirectory(CString srcpath,CString targetpath)
{
   if(_access(targetpath, 0) == -1){_mkdir(targetpath);} 
   else {return;}
   int pos;
   CString szDir = srcpath,tmp,tail;
   szDir += "*.*"; 
   CFileFind ff;
   bool res = ff.FindFile(szDir);  
   while( res )
   {
     res = ff.FindNextFile(); 
     tmp=ff.GetFilePath();
     if (ff.IsDots()){continue;} 
     pos=tmp.Find(srcpath);
     tail=tmp.Mid(pos+srcpath.GetLength());
     if(ff.IsDirectory()){
       copydirectory(tmp+"\\",targetpath+tail+"\\");
       continue;
     }
     CopyFile(tmp,targetpath+tail,0);
   }//while( res )
   ff.Close();
}


void CMy115backDlg::copydirectory_tonew(CString srcpath,CString targetpath,int new_z)
{
   if(_access(targetpath, 0) == -1){_mkdir(targetpath);} 
   else {return;}
   int pos;
   CString szDir = srcpath,tmp,tail,youbian,bfile=padstrcisu(Cstr(new_z),4,"0",0)+".txt",yfile="y"+bfile;
   szDir += "*.*"; 
   CFileFind ff;
   bool res = ff.FindFile(szDir);  
   while( res )
   {
     res = ff.FindNextFile(); 
     tmp=ff.GetFilePath();
     if (ff.IsDots()){continue;} 
     pos=tmp.Find(srcpath);
     tail=tmp.Mid(pos+srcpath.GetLength());
     if(ff.IsDirectory()){
       copydirectory_tonew(tmp+"\\",targetpath+tail+"\\",new_z);
       continue;
     }
     youbian=tmp.Right(13);
     if (youbian.Left(5)=="\\buy\\" && youbian.Right(8)!=bfile){continue;}
     youbian=tmp.Right(16);
     if (youbian.Left(7)=="\\yilou\\" && youbian.Right(9)!=yfile){continue;}

     CopyFile(tmp,targetpath+tail,0);
   }//while( res )
   ff.Close();
}


void CMy115backDlg::OnButton28() 
{
   if (JieMian!=26){jiemian(26);return;}  
   setbutton(FALSE);
   UpdateData(TRUE);
//////////////////////////////////////////////////
   if (m_dfile.GetLength()==0){setbutton(TRUE);return;} 
   int bl,pos,i,ubound;
   CString s,t,dirpath,datafile,ba[8];
   CStdioFile out,fin;



   pos=m_dfile.ReverseFind('\\');
   dirpath=m_dfile.Left(pos+1);
   datafile=dirpath+"45.txt";
   pos=dirpath.Find("\\abuy");
   if (pos>=0){
     datafile=dirpath.Left(pos+1)+"45.txt";
   }
   


   if (m_mo=="3"){
     deletenouseyiloufile(dirpath);
     setbutton(TRUE);	return;
   }

   if (m_mo=="4"){
     adeletefileofdir(dirpath+"abuy\\");
     setbutton(TRUE);	return;
   }



   if (m_mo=="5"){
     fin.Open(datafile,CFile::modeRead);
     fin.ReadString(s);s=delern(s);fin.Close();
     Split(s,ba,bl,"\t");
     if (ba[1].Right(2)=="78"){dlccopybuyfile(dirpath,0);}
     else {dlccopybuyfile(dirpath,1);} 

     setbutton(TRUE);	return;
   }



   DWORD dwAttr = ::GetFileAttributes(datafile); 
   if (dwAttr == 0xffffffff){MessageBox("没有数据文件");setbutton(TRUE);return;}

   out.Open(datafile, CFile::modeRead);

  
   i=0;   
   do{
     out.ReadString(s);
     i=i+1;    
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
   ubound=i;


   CString *datas=new CString[ubound];
   CString *qihao=new CString[ubound];
   
  
   out.Open(datafile, CFile::modeRead);
   
   i=0;   
   do{
     out.ReadString(s);s=delern(s);    
     pos=s.Find('\t');
     s=s.Mid(pos+1);
     pos=s.Find('\t');
     qihao[i]=s.Left(pos);
     datas[i]=s.Mid(pos+1);
     s=datas[i];     
     

     i=i+1;
     
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
/////////////////////////////////////////////////////
   if (m_mo=="2"){

     getdlcbuyfile(dirpath,qihao[0],datas,ubound);
 
   }

   if (m_mo=="1" && dirpath.Find("\\tonew")<0){  
     pos=dirpath.Find("\\abuy");  
     i=0; 
     if (pos>=0){
       i++;
       s=dirpath.Mid(pos+5);
       if (s.Find("\\abuy")>=0){i++;}
     }  

     if (i==0 || i==2){

       int r=dlcrefresh(dirpath,qihao,datas,ubound);

       if (i==0 && r==0){dlczeroall(dirpath);}
     }
     else {
       pos=dirpath.Find("\\abuy");
       CString p=dirpath.Left(pos+1),mpath; 

       s=dirpath.Mid(pos+1);


       p=p+s;

       for (i=3;i<6;i++){
         mpath=p+"abuy"+Cstr(i)+"\\";
         if(_access(mpath, 0) != -1){dlcrefresh(mpath,qihao,datas,ubound);}

         mpath=p+"abuyyilou"+Cstr(i)+"\\";
         if(_access(mpath, 0) != -1){dlcrefresh(mpath,qihao,datas,ubound);}

         mpath=p+"abuybyilou"+Cstr(i)+"\\";
         if(_access(mpath, 0) != -1){dlcrefresh(mpath,qihao,datas,ubound);}

       }
     }    
 
   }//if (m_mo=="1" && dirpath.Find("\\tonew")<0){ 


   if (m_mo=="1" && dirpath.Find("\\tonew")>0){
     CString szDir = dirpath,mpath,tmp,xu,ystr="";
     int ma[3],mb[3],my[3],yi,n;
     CString mahao[3],mbhao[3],myhao[3],type,hao,yfile,wei,s,ihao,qi,wr,dis="",disy="",b[10];
     qi=qihao[0];
     CStdioFile in,out,outa,outb,outy,outystr;
     for (i=0;i<3;i++){
       ma[i]=mb[i]=my[i]=0;
       mahao[i]=mbhao[i]=myhao[i]="x.xx.xxx";
     }     
     szDir += "*.*"; 
     CFileFind ff;
     bool res = ff.FindFile(szDir);  
     while( res )
     { 
       res = ff.FindNextFile(); 
       tmp=ff.GetFilePath();
       mpath = tmp+"\\"; 
       if (ff.IsDots()){continue;}      
       if(ff.IsDirectory()){ 
         pos=tmp.ReverseFind('.');
         xu=tmp.Mid(pos+1);

         pos=tmp.ReverseFind('\\');
         tmp=tmp.Mid(pos+1);
         pos=tmp.Find("_");
         type=tmp.Left(pos);hao=tmp.Mid(pos+1);     
         wei=type.Mid(1); 
         dlcrefresh(mpath,qihao,datas,ubound);

         yfile=mpath+"yilou\\y"+padstrcisu(xu,4,"0",0)+".txt";
         n=atoi(wei)-3;
         fin.Open(yfile,CFile::modeRead);
         fin.ReadString(s);
         Split(s,b,bl,"\t");
         yi=atoi(b[n]);

         

         if (type.Left(1)=="a"){
           if (yi>ma[n]){ma[n]=yi;mahao[n]=hao;}
         }
         else if (type.Left(1)=="b"){
           if (yi>mb[n]){mb[n]=yi;mbhao[n]=hao;}
         }
         else if (type.Left(1)=="y"){
           if (yi>my[n]){my[n]=yi;myhao[n]=hao;}
         }
         /////////////////////////////////////////////
         n=atoi(wei)-2;
         for (i=0;i<n;i++){fin.ReadString(s);}
         s=delern(s);fin.Close();
         
         s=s.Right(100);
         pos=s.Find(":");
         if (pos>=0){
           s=s.Mid(pos+1);           
         }
         else {
           pos=s.Find(",");
           s=s.Mid(pos+1);
         }
         s="("+qihao[0]+")"+padstrcisu(tmp,11," ",1)+":"+s+"["+Cstr(yi)+"]";
         ystr+=s+"\r\n";
         
         /////////////////////////////////////////////

       }//if(ff.IsDirectory()){  
     }
     ff.Close();
       
     out.Open(dirpath+"mdir.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
     out.SeekToEnd();
     outa.Open(dirpath+"mdira.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
     outa.SeekToEnd();
     outb.Open(dirpath+"mdirb.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
     outb.SeekToEnd();    
     outy.Open(dirpath+"mdiry.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
     outy.SeekToEnd();
     wr=qi+":";
     dis+="a(";
     for (i=0;i<3;i++){
       wr+="a"+Cstr(i+3)+"-"+padstrcisu(Cstr(ma[i]),4,"0",0)+"-"+padstrcisu(mahao[i],10," ",1);
       dis+=Cstr(ma[i])+"["+mahao[i]+"],";
     }
     wr+="\r\n";
     out.Write(wr,wr.GetLength());outa.Write(wr,wr.GetLength());
     dis=dis.Left(dis.GetLength()-1)+") b(";
     wr=qi+":";
     for (i=0;i<3;i++){
       wr+="b"+Cstr(i+3)+"-"+padstrcisu(Cstr(mb[i]),4,"0",0)+"-"+padstrcisu(mbhao[i],10," ",1);
       dis+=Cstr(mb[i])+"["+mbhao[i]+"],";
     }
     wr+="\r\n";
     out.Write(wr,wr.GetLength());outb.Write(wr,wr.GetLength());
     dis=dis.Left(dis.GetLength()-1)+")";
     wr=qi+":";
     disy+="y(";
     for (i=0;i<3;i++){
       wr+="y"+Cstr(i+3)+"-"+padstrcisu(Cstr(my[i]),4,"0",0)+"-"+padstrcisu(myhao[i],10," ",1);
       disy+=Cstr(my[i])+"["+myhao[i]+"],";
     }
     wr+="\r\n";
     out.Write(wr,wr.GetLength());outy.Write(wr,wr.GetLength());

     outystr.Open(dirpath+"ystr"+qihao[0].Left(6)+".txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate); 
     outystr.SeekToEnd();  
     outystr.Write(ystr,ystr.GetLength());
     out.Close();outa.Close();outb.Close();outy.Close();outystr.Close();
     sortafileztoa(dirpath+"ystr"+qihao[0].Left(6)+".txt");
     disy=disy.Left(disy.GetLength()-1)+")";


     GetDlgItem(idc_jingdu)->SetWindowText(dis);GetDlgItem(idc_file1)->SetWindowText(disy+"  "+qihao[0]);
   }//if (m_mo=="1" && dirpath.Find("\\tonew")>0){



   
///////////////////////////////////////////////////////
   delete[] datas;delete[] qihao;
   
  
 



//////////////////////////////////////////////////
   setbutton(TRUE);	
 
}


void CMy115backDlg::deletenouseyiloufile(CString dirpath)
{

  if (dirpath.Find("\\abuy\\")>=0){return;}
  CString ydir,b[1000],tstr[10];
  CStdioFile fin;
  int i,j,n,pos,bl,k,jie,kjie,num,znum,fjie,mjie;
  bool flag1,delflag;

  CString strDir,szDir,buyfile,nake,s1,s2,s; 
  CFileFind ff; 
  szDir += "*.*";
  bool res;
  for (i=0;i<3;i++){
    ydir=dirpath+"yilou"+Cstr(i+3)+"\\";
    if(_access(ydir, 0) == -1){continue;}
//////////////////////////////////////////////////
    switch(i){
      case 0:
        mjie=50;
        jie=80;        
        kjie=136;
        break;
      case 1:
        mjie=200;
        jie=320;
        kjie=600;
        break;
      case 2:
        mjie=1620;
        jie=2000;
        kjie=5000;
        break;
    }
    fjie=jie/3;
    strDir=ydir;
    szDir = strDir;
    szDir += "*.*"; 
    res = ff.FindFile(szDir); 
    while( res ) 
    { 
      res = ff.FindNextFile(); 
      buyfile = ff.GetFilePath(); 
      if(!ff.IsDirectory() && !ff.IsDots()){
        pos=buyfile.ReverseFind('\\'); 
        nake=buyfile.Mid(pos+1);   
        fin.Open(buyfile, CFile::modeRead);
        j=0;
        do{
          fin.ReadString(s);s=delern(s);  
          tstr[j]=s;
          j++;  
        }
        while (fin.GetPosition()!=fin.GetLength());
        fin.Close();    
        s1=tstr[i+1];
        s1=s1.Mid(3);
        flag1=false;delflag=true;
        if (s1.GetLength()>0){
          Split(s1,b,bl,",");
          k=0;num=0;znum=0;
          for (j=bl;j>=0;j--){
            n=atoi(b[j]);
            k+=n;
            if (n>=fjie){num++;znum+=n;}  //test
            if (num>=2 && znum>=jie || n>=mjie){flag1=true;break;} //if (n>=jie){flag1=true;break;}   
            if (k>kjie){break;}        
          }//for (j=bl;j>=0;j--){
          if (flag1 && k<=kjie){delflag=false;}
          
        }

        if (delflag){DeleteFile(buyfile);}


       
      }     
    
    }
    ff.Close(); 


/////////////////////////////////////////////////
  }
  yiloufilegenxin(dirpath);

}

void CMy115backDlg::deletedir_tonew(CString dirpath) 
{
   if (dirpath.Right(6)!="tonew\\" && dirpath.Right(3)!="tz\\"){return;}
   CString szDir = dirpath,buyfile,npath;
   
   szDir += "*.*"; 
   CFileFind ff;
   bool res = ff.FindFile(szDir);  
   while( res )
   { 
     res = ff.FindNextFile(); 
     buyfile = ff.GetFilePath(); 
     if (ff.IsDots()){continue;}
     if(ff.IsDirectory()){
       npath=buyfile+"\\";
       deletedir(npath);
     }    
   }
   ff.Close();
}





void CMy115backDlg::backtohistry(CString dirpath,int days) 
{

   clock_t begin=clock();
   int shijian,hour,min,sec;   
   int i,n,pos;
   CString timestr;


   CString dpath=dirpath+"data\\";

   if(_access(dpath, 0) == -1){
    
     _mkdir(dpath);

     GetDlgItem(idc_jingdu)->SetWindowText("No data directory!");
     return;
   } 
   CString datafile=dpath+"45.txt";


   DWORD dwAttr = ::GetFileAttributes(datafile); 
   if (dwAttr == 0xffffffff){
     GetDlgItem(idc_jingdu)->SetWindowText("No data file!");
     return;
   } 
   if (days<=0){days=1;}
   if (days>50){days=50;}
   int j,k,qisu=(days+1)*78,bl;
   CString wr,s,b[10];
   CString *data=new CString [qisu];
   CStdioFile fin,out;
   fin.Open(datafile, CFile::modeRead);
   while(true){
     fin.ReadString(s);s=delern(s);
     Split(s,b,bl,"\t");
     if (b[1].Right(2)=="78"){data[0]=s;break;}
   }
   for (i=1;i<qisu;i++){
     fin.ReadString(s);s=delern(s);
     data[i]=s;  
   }
   fin.Close();
   CString usedatafile=dirpath+"45.txt";

   int nowqi=days*78;
   int mqmas=m_qmas;
   CString *datas=new CString[78];
   CString *qihao=new CString[78];

   ////更新///////////////
   for (i=0;i<days;i++){
     nowqi-=78;
     //out.Open(usedatafile,CFile::modeCreate|CFile::modeWrite);   
     wr="";
     k=0;
     for (j=nowqi;j<nowqi+78;j++){
       s=data[j];
       pos=s.Find('\t');
       s=s.Mid(pos+1);
       pos=s.Find('\t');
       qihao[k]=s.Left(pos);
       datas[k]=s.Mid(pos+1);
       k++; 
     }     
     m_num=7;
     m_qmas=mqmas;
     UpdateData(FALSE);   
     DoEvents();

     f27(qihao,datas,78);

     DoEvents();
  }
  delete[] data;
  //CopyFile(datafile,usedatafile,0);
  delete[] datas;delete[] qihao;
  shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
  hour=shijian/3600;
  n=shijian-hour*3600;
  min=n/60;
  sec=n-60*min;
  timestr="Back days:"+Cstr(days)+",use time:"+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec);
  GetDlgItem(idc_jingdu)->SetWindowText(timestr);
//MessageBox("4");
}








void CMy115backDlg::dlctoubianrand(small **zu,int ubound,small **tzu,int a0[],int a1[],int a2[],int a3[]) 
{

   int i,j,ai,k,m,n,su=m_we*5,num,be,en;
   small c,tmp[5];
   bool you;





   for (i=0;i<ubound;i++){
     
     while (true){
       k=0;       
       

       for (ai=0;ai<8;ai++){

         num=rand()%su;
         m=num/5;
         n=num%5;
         c=zu[m][n];
         switch(i){
           case 0:
             if (c>=9){c=a0[rand()%8];}
             break;
           case 1:
             if (c<4){c=a1[rand()%8];}
             break;
           case 2:
             if (c==4 || c==5 || c==6 ){c=a2[rand()%8];}  
             break;           
           case 3:
             if (c==7 || c==8 || c==9){c=a3[rand()%8];}
                    
         }
         
         if (k==0){tmp[0]=c;k=1;}
         else {

           you=false;
           for (j=0;j<k;j++){
             if (c==tmp[j]){you=true;break;}
           }


           if (! you){
             tmp[k]=c;
             k++;
             if (k>=2){break;}
           }


         }         
       }
       switch(i){
         case 0:
           if (k==2){
             tmp[2]=9;tmp[3]=10;tmp[4]=11;k=5;
           }
           else {tmp[1]=9;tmp[2]=10;tmp[3]=11;k=4;}
           break;
         case 1:
           if (k==2){
             tmp[2]=1;tmp[3]=2;tmp[4]=3;k=5;
           }
           else {tmp[1]=1;tmp[2]=2;tmp[3]=3;k=4;}
           break;
         case 2:
           if (k==2){
             tmp[2]=4;tmp[3]=5;tmp[4]=6;k=5;
           }
           else {tmp[1]=4;tmp[2]=5;tmp[3]=6;k=4;}
           break;
         case 3:
           if (k==2){
             tmp[2]=7;tmp[3]=8;tmp[4]=9;k=5;
           }
           else {tmp[1]=7;tmp[2]=8;tmp[3]=9;k=4;}
       }

       while (k<5){
         be=rand()%11+1;         
         en=be+11;
         for (j=be;j<en;j++){
           if (j>11){j=j-11;}
           you=false;
           for (ai=0;ai<k;ai++){
             if (j==tmp[ai]){you=true;break;}
           }
           if (! you){
             tmp[k]=j;
             k++;
             break;
           }
         }
         if (k>=5){break;}       
       }    

       n=rand()%6;
       switch(n){
         case 0://123
           tzu[i][0]=tmp[2];
           tzu[i][1]=tmp[3];  
           tzu[i][3]=tmp[4];         
           tmp[0]=tmp[0];
           tmp[1]=tmp[1];
           
           break;
         case 1://132
           tzu[i][0]=tmp[2];
           tzu[i][1]=tmp[4];
           tzu[i][3]=tmp[3];         
           tmp[0]=tmp[0];
           tmp[1]=tmp[1];
           
           break;

         case 2://213
           tzu[i][0]=tmp[3];
           tzu[i][1]=tmp[2];
           tzu[i][3]=tmp[4];         
           tmp[0]=tmp[0];
           tmp[1]=tmp[1];
           
           break;

         case 3://231
           tzu[i][0]=tmp[3];
           tzu[i][1]=tmp[4];
           tzu[i][3]=tmp[2];         
           tmp[0]=tmp[0];
           tmp[1]=tmp[1];
           
           break;

         case 4://312
           tzu[i][0]=tmp[4];
           tzu[i][1]=tmp[2];
           tzu[i][3]=tmp[3];         
           tmp[0]=tmp[0];
           tmp[1]=tmp[1];
           
           break;

         case 5://321
           tzu[i][0]=tmp[4];
           tzu[i][1]=tmp[3];
           tzu[i][3]=tmp[2];         
           tmp[0]=tmp[0];
           tmp[1]=tmp[1];
           
           break;      
       }

       for (j=0;j<3;j=j+2){  
                  
          n=rand()%2;  
  
          for (k=n;k<n+2;k++){
            m=k;

            if (m>1){m=m-2;}
   
            c=tmp[m];
  
            if (c>0){tzu[i][j+2]=c;tmp[m]=-1;break;}
          }    
       }
     
       

 
       if (i==0){break;}  
       you=false;
       for (j=0;j<i;j++){
         n=0;
         for (ai=0;ai<5;ai++){
           c=tzu[i][ai];
           if (c==tzu[j][0]){n++;}
           else if(c==tzu[j][1]){n++;}
           else if(c==tzu[j][2]){n++;}
           else if(c==tzu[j][3]){n++;}
           else if(c==tzu[j][4]){n++;}           
         }
         if (n>=5){you=true;break;}
       }

       if (! you){break;}
     }
 
    
   }   


}



void CMy115backDlg::OnButton9() //////////////333333333333
{



   if (JieMian!=3){jiemian(3);return;}  
   setbutton(FALSE);UpdateData(TRUE);
   CString qi,mmo=m_mo,tmpstr,atail;
   bool qiflag=false;
////////////////////////////////////////////
   CString new_type,new_a_type;
   int new_x,new_y,new_z,new_num,new_yilou,ubound;
////////////////////////////////////////////

///////////////////////////////////////////
   clock_t begin=clock();
   int shijian,hour,min,sec;   
   int i,j,k,pos,n,bl;
   CString timestr;
   const int SU=10000;
   
   int ma[3],mb[3],my[3];//mc[3],
   CString mahao[3],mbhao[3],myhao[3],mah[3],mbh[3],myh[3];
   for (i=0;i<3;i++){
     ma[i]=mb[i]=my[i]=0;
     mahao[i]="0000.00.0000000";
     mbhao[i]="0000.00.00000  ";
     myhao[i]="0000.00.00000  ";
     mah[i]="0";mbh[i]="0";myh[i]="0";
   }
   CString b[10],bb[10];
/////////////////////////////////////////////
  int mnum=m_num,mmas=m_mas,mqmas=m_qmas,mwe=m_btui,metui=m_etui;

  pos=m_dfile.ReverseFind('\\');
  CString dirpath=m_dfile.Left(pos+1),s,wr,head;
//////////////////////////////////////////////////////////
  if(_access(dirpath+"tonew\\", 0) == -1){_mkdir(dirpath+"tonew\\");} 
  if(_access(dirpath+"tz\\", 0) == -1){_mkdir(dirpath+"tz\\");} 

/////////////////////////////////////////////////////////
  CString datafile=dirpath+"45.txt";

  DWORD dwAttr = ::GetFileAttributes(datafile); 
  if (dwAttr == 0xffffffff){setbutton(TRUE);GetDlgItem(idc_jingdu)->SetWindowText("No data file!");return;}
  CStdioFile fin,out,outa,outb,outy,outtj;



  CString mpath,mdatafile,tjfile,tjfilea,tjfileb,tjfiley,mtjfile; 

  CString dir4[3],dir;
/////////////////////////////////////////////////
   out.Open(datafile, CFile::modeRead);

  
   i=0;   
   do{
     out.ReadString(s);
     i=i+1;    
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
   ubound=i;


   CString *datas=new CString[ubound];
   CString *qihao=new CString[ubound];
   
  
   out.Open(datafile, CFile::modeRead);
   
   i=0;   
   do{
     out.ReadString(s);s=delern(s);    
     pos=s.Find('\t');
     s=s.Mid(pos+1);
     pos=s.Find('\t');
     qihao[i]=s.Left(pos);
     datas[i]=s.Mid(pos+1);
     s=datas[i];     
     

     i=i+1;
     
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
   CString realqi=qihao[0];
  
////////////////////////////////////////////////
  int yimax[3];
  CString yimaxqi[3],maxdir,maxfile,yimaxhao[3];
  for (i=0;i<3;i++){yimax[i]=0;yimaxhao[i]="00.0000.0000";yimaxqi[i]="00000000";}
  if (m_num==7){
    deletedir_tonew(dirpath+"tonew\\");
    deletedir_tonew(dirpath+"tz\\"); 
  }
///////////////////////////////////////////////
  for (i=1;i<=SU;i++){

    mpath=dirpath+Cstr(i)+"\\";
    if(_access(mpath, 0) == -1 && mnum!=9  || mnum==9 && (i>metui || _access(mpath, 0) != -1)){continue;}
    mdatafile=mpath+"45.txt";
    if (mnum!=9){      
      CopyFile(datafile,mdatafile,0);
    }
    else {
      _mkdir(mpath);
      _mkdir(mpath+"data\\");
      CopyFile(datafile,mdatafile,0);
      CopyFile(datafile,mpath+"data\\45.txt",0);
    }
    
//MessageBox("i="+Cstr(i));
    
    jiemian(25);
    m_num=mnum;
    m_mas=mmas;
    m_qmas=mqmas;
    m_we=mwe;
    m_mo=mmo;
    m_dfile=mdatafile;
    UpdateData(FALSE);
    DoEvents();
 

    f27(qihao,datas,ubound);
    DoEvents();

    if (mnum==9){continue;}
    j=0;


    mtjfile=mpath+"mdir.txt";
    fin.Open(mtjfile,CFile::modeRead);

    if (mnum==6){
      for (j=0;j<3;j++){dir4[j]="";}   
      tmpstr="";
      j=0;
      while(fin.ReadString(s)){
        s=delern(s);
        dir4[j]=s;
        for (k=0;k<8;k++){
          dir4[j].Replace("  "," ");
        }
        j++;
        if (j==3){j=0;}
      }
      pos=dir4[0].Find(":");
      if (!qiflag){
        qi=dir4[0].Left(pos);
        qiflag=true;
      }      
/////////////////////////////////////
      if (qi==realqi){//////////
        for (j=0;j<3;j++){
          s=dir4[j];
          pos=s.Find(":");
          s=s.Mid(pos+1);
          head=s.Left(1);
          Split(s,b,bl," ");
          for (k=0;k<3;k++){
            Split(b[k],bb,bl,"-");
            n=atoi(bb[1]);
            if (head=="y"){
              ////////////////////////////////////////////////
              if (k==0 && n>=50 || k==1 && n>=180 || k==2 && n>=1200){//200
                  new_type="y";new_num=k+3;new_yilou=n;new_x=i;
                  pos=bb[2].Find(".");
                  new_y=atoi(bb[2].Left(pos));new_z=atoi(bb[2].Mid(pos+1));
                  getdlcbuydir(dirpath,new_type,"",new_num,new_yilou,new_x,new_y,new_z);
              }
              //////////////////////////////////////////////////
              if (n>=my[k]){
                my[k]=n;myh[k]=Cstr(i);
                myhao[k]=padstrcisu(Cstr(i),4,"0",0)+"."+bb[2]+"  ";

              }
            }
            if (head=="b"){
              ////////////////////////////////////////////////
              if (k==0 && n>=3 || k==1 && n>=10 || k==2 && n>=250){
                  new_type="b";new_num=k+3;new_yilou=n;new_x=i;
                  pos=bb[2].Find(".");
                  new_y=atoi(bb[2].Left(pos));new_z=atoi(bb[2].Mid(pos+1));
                  getdlcbuydir(dirpath,new_type,"",new_num,new_yilou,new_x,new_y,new_z);
              }
              //////////////////////////////////////////////////
              if (n>=mb[k]){
                mb[k]=n;mbh[k]=Cstr(i);
                mbhao[k]=padstrcisu(Cstr(i),4,"0",0)+"."+bb[2]+"  ";

              }
            }
            if (head=="a"){
              ////////////////////////////////////////////////
              if (k==0 && n>=5 || k==1 && n>=30 || k==2 && n>=600){
                  new_a_type=bb[2].Right(2);
                  atail=bb[2].Left(bb[2].GetLength()-2);                  
                  new_type="a";new_num=k+3;new_yilou=n;new_x=i;
                  pos=atail.Find(".");
                  new_y=atoi(atail.Left(pos));new_z=atoi(atail.Mid(pos+1));
                  getdlcbuydir(dirpath,new_type,new_a_type,new_num,new_yilou,new_x,new_y,new_z);
              }
              //////////////////////////////////////////////////
              if (n>=ma[k]){
                ma[k]=n;mah[k]=Cstr(i);
                mahao[k]=padstrcisu(Cstr(i),4,"0",0)+"."+bb[2];

              }
            }




          }        

        }
      }//if (qi==realqi){//////////
      tmpstr="a(";
      for (j=0;j<3;j++){
         tmpstr+=Cstr(ma[j])+"["+mah[j]+"],";
      }
      tmpstr=tmpstr.Left(tmpstr.GetLength()-1)+") b(";
      for (j=0;j<3;j++){
         tmpstr+=Cstr(mb[j])+"["+mbh[j]+"],";
      }
      tmpstr=tmpstr.Left(tmpstr.GetLength()-1)+") y(";
      for (j=0;j<3;j++){
         tmpstr+=Cstr(my[j])+"["+myh[j]+"],";
      }
      tmpstr=tmpstr.Left(tmpstr.GetLength()-1)+")";

      GetDlgItem(idc_file1)->SetWindowText(tmpstr);



    }
    else if (mnum==7){
      dir="";
      while(fin.ReadString(s)){
        s=delern(s);
        dir=s;
      }
      dir.Replace("  "," ");dir.Replace("  "," ");
      pos=dir.Find(":");
      if (!qiflag){
        qi=dir.Left(pos);
        qiflag=true;
      }
      dir=dir.Mid(pos+1);
      Split(dir,b,bl," ");
      for (j=0;j<3;j++){
        Split(b[j],bb,bl,"-");
        n=atoi(bb[1]);
        ////////////////////////////////////////////////
        if (j==0 && n>=50 || j==1 && n>=180 || j==2 && n>=1200){//200
            new_type="y";new_num=j+3;new_yilou=n;new_x=i;
            pos=bb[2].Find(".");
            new_y=atoi(bb[2].Left(pos));new_z=atoi(bb[2].Mid(pos+1));
            getdlcbuydir(dirpath,new_type,"",new_num,new_yilou,new_x,new_y,new_z);
        }
        //////////////////////////////////////////////////
        if (n>=my[j]){
          my[j]=n;
          myhao[j]=padstrcisu(Cstr(i),4,"0",0)+"."+bb[2];

        }
      }
    }
    
    fin.Close();  
//////////////////////////////////////////////////////////////
    if (mnum==7){
       maxdir=mpath+"tj\\";
       for (j=0;j<3;j++){
         maxfile=maxdir+"maxyilouqi"+Cstr(j+3)+".txt";
         fin.Open(maxfile,CFile::modeRead);
         fin.ReadString(s);delern(s);
         Split(s,b,bl,"\t");
         n=atoi(b[1]);
         if (n>=yimax[j]){yimax[j]=n;yimaxqi[j]=b[0];yimaxhao[j]=padstrcisu(Cstr(i),2,"0",0)+"."+b[2];}
         fin.Close();
       }

    }



///////////////////////////////////////////////////////////////


  } 
  qi=realqi;
  tjfile=dirpath+"mdir.txt";
  tjfilea=dirpath+"mdira.txt";
  tjfileb=dirpath+"mdirb.txt";  
  tjfiley=dirpath+"mdiry.txt";

  if (mnum!=9){
    out.Open(tjfile,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    out.SeekToEnd();
    outa.Open(tjfilea,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    outa.SeekToEnd();
    outb.Open(tjfileb,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    outb.SeekToEnd();
    outy.Open(tjfiley,CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);    
    outy.SeekToEnd();

  }
  if (mnum==7){
    wr=qi+":";
    for (i=0;i<3;i++){
      wr+="y"+Cstr(i+3)+"-"+padstrcisu(Cstr(my[i]),4,"0",0)+"-"+myhao[i]+" ";
    }
    wr=wr.Left(wr.GetLength()-1)+"\r\n";
    out.Write(wr,wr.GetLength());
    outy.Write(wr,wr.GetLength()); 
////////////////////////////////////////////////////////////
    CString tjpath=dirpath+"tj\\";
    if(_access(tjpath, 0) == -1){_mkdir(tjpath);} 
    
    for (i=0;i<3;i++){
      outtj.Open(tjpath+"maxyilouqi"+Cstr(i+3)+".txt",CFile::modeCreate|CFile::modeWrite|CFile::modeNoTruncate);  
      outtj.SeekToEnd(); 
      wr=yimaxqi[i]+"\t"+padstrcisu(Cstr(yimax[i]),4,"0",0)+"\t"+yimaxhao[i]+"\r\n";
      outtj.Write(wr,wr.GetLength());
      outtj.Close();
      sortafileztoa(tjpath+"maxyilouqi"+Cstr(i+3)+".txt");
   }

   for (i=0;i<3;i++){
      CString mfile=tjpath+"maxyilouqi"+Cstr(i+3)+".txt";
      outtj.Open(mfile,CFile::modeRead);  
      n=0;
      while(outtj.ReadString(s)){
        n++;
      }       
      outtj.Close();
      if (n==0){continue;}
      CString *zu=new CString [n];

      outtj.Open(mfile,CFile::modeRead);  
      j=0;
      while(outtj.ReadString(s)){
        s=delern(s); 
        Split(s,b,bl,"\t");
        zu[j]=b[1]+"#"+s;
        j++;
      }       
      outtj.Close();
      paixuztoa(zu,n);
      outtj.Open(tjpath+"maxyilounum"+Cstr(i+3)+".txt",CFile::modeCreate|CFile::modeWrite);   
      for (j=0;j<n;j++){ 
        s=zu[j];
        pos=s.Find("#");
        s=s.Mid(pos+1)+"\r\n";
        outtj.Write(s,s.GetLength());
      }
      outtj.Close();
      delete[] zu;      

   }


/////////////////////////////////////////////////////////////////////////

  }
  else if (mnum==6){
//////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////


    wr=qi+":";
    for (i=0;i<3;i++){
      wr+="y"+Cstr(i+3)+"-"+padstrcisu(Cstr(my[i]),4,"0",0)+"-"+myhao[i]+" ";
    }
    wr=wr.Left(wr.GetLength()-1)+"\r\n";
    out.Write(wr,wr.GetLength());outy.Write(wr,wr.GetLength());

    wr=qi+":";
    for (i=0;i<3;i++){
      wr+="b"+Cstr(i+3)+"-"+padstrcisu(Cstr(mb[i]),4,"0",0)+"-"+mbhao[i]+" ";
    }
    wr=wr.Left(wr.GetLength()-1)+"\r\n";
    out.Write(wr,wr.GetLength());outb.Write(wr,wr.GetLength());

    wr=qi+":";
    for (i=0;i<3;i++){
      wr+="a"+Cstr(i+3)+"-"+padstrcisu(Cstr(ma[i]),4,"0",0)+"-"+mahao[i]+" ";
    }
    wr=wr.Left(wr.GetLength()-1)+"\r\n";
    out.Write(wr,wr.GetLength());outa.Write(wr,wr.GetLength());


  }

  if (mnum!=9){out.Close();outa.Close();outb.Close();outy.Close();}   //outc.Close();

  
  
  jiemian(3);
  m_dfile=datafile;
  UpdateData(FALSE);
   

  shijian=(int)(clock()-begin) / CLOCKS_PER_SEC;
  hour=shijian/3600;
  n=shijian-hour*3600;
  min=n/60;
  sec=n-60*min;
  timestr="程序结束,共耗时"+Cstr(hour)+":"+Cstr(min)+":"+Cstr(sec)+"  "+qihao[0];
  GetDlgItem(idc_jingdu)->SetWindowText(timestr);
  delete[] datas;delete[] qihao;

  setbutton(TRUE);
}

















int CMy115backDlg::samenumber34(int ma1[],int ma2[],int ubound) 
{
   int r=0,i,j,tnum;
   for (i=0;i<ubound;i++){
     for (j=0;j<ubound;j++){
        if (ma1[i]==ma2[j]){r++;tnum=ma1[i];break;}
     }
   }  
   if (r==0){return r;}
   if (r>1){return -1;}
   return tnum;
}






void CMy115backDlg::getzu4(CString srcfile) 
{
   CStdioFile fin,out;
   CString b[4],s,wr,c;
   int i,j,j1,k,ubound,bl,pos,r,tnum;
   bool you;

   fin.Open(srcfile, CFile::modeRead);  
   i=0;   
   do{
     fin.ReadString(s);
     i=i+1;    
   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   ubound=i;   
   int **data=new int *[ubound];
   for (i=0;i<ubound;i++){
     *(data+i)=new int [5];
     data[i][4]=0;
   }

   
   fin.Open(srcfile, CFile::modeRead);  
   i=0;   
   do{
     fin.ReadString(s);s=delern(s);
     pos=s.Find(":");
     if (pos>=0){s=s.Mid(pos+1);}
     Split(s,b,bl,",");
     for (j=0;j<4;j++){data[i][j]=atoi(b[j]);}

     i++; 
   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();   

   pos=srcfile.ReverseFind('\\');
   CString dirpath=srcfile.Left(pos+1);
   CString ymin=srcfile.Mid(pos+1);
   ymin=ymin.Left(ymin.GetLength()-4);
   CString zufile=dirpath+"zu_from_"+ymin+".txt";
   out.Open(zufile,CFile::modeCreate|CFile::modeWrite);
   int zu[3][4],gai[3];
   for (i=0;i<ubound;i++){
      //if (data[i][4]==1){continue;}
      k=0;

      for (j=0;j<4;j++){zu[0][j]=data[i][j];}
      gai[k]=i;tnum=-1;
      for (j=i+1;j<ubound;j++){
        //if (data[j][4]==1){continue;}
        you=false;

        for (j1=0;j1<=k;j1++){

          r=samenumber34(zu[j1],data[j],4);
          if (r==-1){you=true;break;}
          if (r>0){
            if (tnum==-1){tnum=r;}
            else {you=true;break;}
          }

        }

        if (! you){
          k++;
          for (j1=0;j1<4;j1++){zu[k][j1]=data[j][j1];}          
          gai[k]=j;
          if (k==2){
             data[gai[0]][4]=1;data[gai[1]][4]=1;data[gai[2]][4]=1;
             break;
          }
        }
      }
      if (k==2){
        wr="";
        for (j=0;j<3;j++){
          for (j1=0;j1<4;j1++){
            c=Cstr(zu[j][j1]);
            if (zu[j][j1]<10){c="0"+c;}
            wr=wr+c+",";
          }
          wr=wr.Left(wr.GetLength()-1)+";";
        }
        wr=wr.Left(wr.GetLength()-1)+"\r\n";
        out.Write(wr,wr.GetLength());
      }
   }
   out.Close();
   for (i=0;i<ubound;i++){delete[] data[i];}
   delete[] data;

}




void CMy115backDlg::countzu(CString qihao,CString datas[],int ubound,CString dirpath) 
{
   CString s,wr,c1,c2,c3,c4,c5;
   int i,i1,i2,i3,i4,i5,n,yi,maxyi;
   CStdioFile out,outy;
   
   out.Open(dirpath+"zu3hitnum"+qihao+".txt",CFile::modeCreate|CFile::modeWrite);
   outy.Open(dirpath+"zu3yilou"+qihao+".txt",CFile::modeCreate|CFile::modeWrite);
   for (i1=0;i1<11;i1++){
   for (i2=i1+1;i2<11;i2++){
   for (i3=i2+1;i3<11;i3++){
     n=0;yi=0;maxyi=0;
     for (i=0;i<ubound;i++){
       s=datas[i];
       c1=Cstr(i1+1);
       if (i1<9){c1="0"+c1;}
       c2=Cstr(i2+1);
       if (i2<9){c2="0"+c2;}
       c3=Cstr(i3+1);
       if (i3<9){c3="0"+c3;}
       if (s.Find(c1)>=0 && s.Find(c2)>=0 && s.Find(c3)>=0){
         n++;
         if (maxyi<yi){maxyi=yi;}
         yi=0;
       }
       else {yi++;}
     }
     wr=padstrcisu(Cstr(n),4," ",0)+":"+c1+","+c2+","+c3+"\r\n";
     out.Write(wr,wr.GetLength());
     wr=padstrcisu(Cstr(maxyi),4," ",0)+":"+c1+","+c2+","+c3+"\r\n";
     outy.Write(wr,wr.GetLength());

   }}}
   out.Close();outy.Close();
   sortafileatoz(dirpath+"zu3yilou"+qihao+".txt");
   sortafileztoa(dirpath+"zu3hitnum"+qihao+".txt");

   out.Open(dirpath+"zu4hitnum"+qihao+".txt",CFile::modeCreate|CFile::modeWrite);
   outy.Open(dirpath+"zu4yilou"+qihao+".txt",CFile::modeCreate|CFile::modeWrite);

   for (i1=0;i1<11;i1++){
   for (i2=i1+1;i2<11;i2++){
   for (i3=i2+1;i3<11;i3++){
   for (i4=i3+1;i4<11;i4++){
     n=0;yi=0;maxyi=0;
     for (i=0;i<ubound;i++){
       s=datas[i];
       c1=Cstr(i1+1);
       if (i1<9){c1="0"+c1;}
       c2=Cstr(i2+1);
       if (i2<9){c2="0"+c2;}
       c3=Cstr(i3+1);
       if (i3<9){c3="0"+c3;}
       c4=Cstr(i4+1);
       if (i4<9){c4="0"+c4;}
       if (s.Find(c1)>=0 && s.Find(c2)>=0 && s.Find(c3)>=0 && s.Find(c4)>=0){
         n++;
         if (maxyi<yi){maxyi=yi;}
         yi=0;
       }
       else {yi++;}
     }
     wr=padstrcisu(Cstr(n),4," ",0)+":"+c1+","+c2+","+c3+","+c4+"\r\n";
     out.Write(wr,wr.GetLength());
     wr=padstrcisu(Cstr(maxyi),4," ",0)+":"+c1+","+c2+","+c3+","+c4+"\r\n";
     outy.Write(wr,wr.GetLength());

   }}}}
   out.Close();outy.Close();
   sortafileztoa(dirpath+"zu4hitnum"+qihao+".txt");
   sortafileatoz(dirpath+"zu4yilou"+qihao+".txt");

   out.Open(dirpath+"zu5hitnum"+qihao+".txt",CFile::modeCreate|CFile::modeWrite);
   outy.Open(dirpath+"zu5yilou"+qihao+".txt",CFile::modeCreate|CFile::modeWrite);

   for (i1=0;i1<11;i1++){
   for (i2=i1+1;i2<11;i2++){
   for (i3=i2+1;i3<11;i3++){
   for (i4=i3+1;i4<11;i4++){
   for (i5=i4+1;i5<11;i5++){
     n=0;yi=0;maxyi=0;
     for (i=0;i<ubound;i++){
       s=datas[i];
       c1=Cstr(i1+1);
       if (i1<9){c1="0"+c1;}
       c2=Cstr(i2+1);
       if (i2<9){c2="0"+c2;}
       c3=Cstr(i3+1);
       if (i3<9){c3="0"+c3;}
       c4=Cstr(i4+1);
       if (i4<9){c4="0"+c4;}
       c5=Cstr(i5+1);
       if (i5<9){c5="0"+c5;}
       if (s.Find(c1)>=0 && s.Find(c2)>=0 && s.Find(c3)>=0 && s.Find(c4)>=0 && s.Find(c5)>=0){
         n++;
         if (maxyi<yi){maxyi=yi;}
         yi=0;
       }
       else {yi++;}
     }
     wr=padstrcisu(Cstr(n),4," ",0)+":"+c1+","+c2+","+c3+","+c4+","+c5+"\r\n";
     out.Write(wr,wr.GetLength());
     wr=padstrcisu(Cstr(maxyi),4," ",0)+":"+c1+","+c2+","+c3+","+c4+","+c5+"\r\n";
     outy.Write(wr,wr.GetLength());

   }}}}}
   out.Close();outy.Close();
   sortafileztoa(dirpath+"zu5hitnum"+qihao+".txt");
   sortafileatoz(dirpath+"zu5yilou"+qihao+".txt");

}




void CMy115backDlg::getbuyzu(CString srcfile) 
{
   CStdioFile fin,out;
   int i,j,k,pos,bl;
   CString files[3],b[10],zufile,s,wr;
   pos=srcfile.ReverseFind('\\');
   CString dirpath=srcfile.Left(pos+1);
   fin.Open(srcfile, CFile::modeRead);    
   i=0;
   do{
     fin.ReadString(s);s=delern(s);
     files[i]=dirpath+s;
     i++; 
   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   CString buyzudir=dirpath+"dlcbuyzu\\";
   if(_access(buyzudir, 0) == -1){_mkdir(buyzudir);} 
   for (i=0;i<3;i++){     
     fin.Open(files[i], CFile::modeRead);   
     j=0; 
     do{
       fin.ReadString(s);s=delern(s);
       Split(s,b,bl,";");
       j++;
       zufile=buyzudir+"zu"+Cstr(i+3)+"-"+padstrcisu(Cstr(j),3,"0",0)+".txt";
       out.Open(zufile,CFile::modeCreate|CFile::modeWrite);  
       for (k=0;k<=bl;k++){
          wr=b[k]+";\r\n";
          wr.Replace(","," ");
          out.Write(wr,wr.GetLength());
       }
       out.Close();
     }
     while (fin.GetPosition()!=fin.GetLength());
     fin.Close();
   }
}





void CMy115backDlg::getstate(CString qihao,CString datas[],int ubound,CString srcfile) 
{


   CStdioFile fin,out;
   int pos;
   int hitd3[4][3],hitd4[3][4],hitd5[3][5];


   pos=srcfile.ReverseFind('\\');
   CString dirpath=srcfile.Left(pos+1),s;
   CString ystrfile=dirpath+"ystr"+qihao+".txt";
   out.Open(ystrfile,CFile::modeCreate|CFile::modeWrite);  

   fin.Open(srcfile, CFile::modeRead);    

   fin.ReadString(s);s=delern(s);

   CString yi3=getstate_3(qihao,datas,ubound,dirpath+s,hitd3,out);

   fin.ReadString(s);s=delern(s);
   CString yi4=getstate_4(qihao,datas,ubound,dirpath+s,hitd4,out);


   fin.ReadString(s);s=delern(s);
   CString yi5=getstate_5(qihao,datas,ubound,dirpath+s,hitd5,out);

   fin.Close();
   out.Close();
   sortafileztoa(ystrfile);
   GetDlgItem(idc_jingdu)->SetWindowText(qihao+"  三位遗漏="+yi3+"  四位遗漏="+yi4+"  五位遗漏="+yi5);
}



CString CMy115backDlg::getstate_3(CString qihao,CString datas[],int ubound,CString zufile,int hitd3[][3],CStdioFile &out) 
{
   int i,j,k,maxyi,yi,changdu=m_mas,chang=m_mas,hitnum,yisum,bl,allyi=0,nowyi=0;
   if (changdu<8){changdu=8;}
   CString s,wr,c,ystr,b[4],head;
   bool first,hit[11],goflag=false;
   
 
   CStdioFile fin;
   int xu=1;
   fin.Open(zufile, CFile::modeRead);  

   do{
     fin.ReadString(s);s=delern(s);
     Split(s,b,bl,";");

     for (j=0;j<4;j++){

        for (k=0;k<3;k++){

          hitd3[j][k]=atoi(b[j].Mid(3*k,2))-1;

        }
     }

///////////////////////////////////////////////////////
     first=true;chang=0;ystr="";
     yi=0;maxyi=0;hitnum=0;yisum=0;
     for (i=0;i<ubound;i++){
       s=datas[i];
       for(j=0;j<11;j++){
         c=Cstr(j+1);
         if (j<9){c="0"+c;}
         hit[j]=(s.Find(c)>=0);
       } 


       
       if (hit[hitd3[0][0]] && hit[hitd3[0][1]] && hit[hitd3[0][2]] || 
           hit[hitd3[1][0]] && hit[hitd3[1][1]] && hit[hitd3[1][2]] || 
           hit[hitd3[2][0]] && hit[hitd3[2][1]] && hit[hitd3[2][2]] ||
           hit[hitd3[3][0]] && hit[hitd3[3][1]] && hit[hitd3[3][2]]){

          if (!first){ystr=Cstr(yi)+","+ystr;}
          else {
            ystr="["+Cstr(yi)+"]";first=false;head="z"+padstrcisu(Cstr(yi),2,"0",0)+"zu3-"+padstrcisu(Cstr(xu),3,"0",0);
            if (nowyi<yi){nowyi=yi;}
          }

          if (yi>maxyi){maxyi=yi;}
          if (maxyi>allyi){allyi=maxyi;}
          chang+=Cstr(yi).GetLength()+1;
          hitnum++;yisum+=yi;
          if (chang>=changdu){break;}
          yi=0;
       } 
       else {yi++;}    

  
     }//for (i=0;i<ubound;i++){ 
     ystr="("+qihao+")"+head+"{"+Cstr(maxyi)+","+Cstr(hitnum*10000/yisum)+"}"+ystr+"\r\n";
     out.Write(ystr,ystr.GetLength());



//////////////////////////////////////////////////////////
     xu++;


   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   return "["+Cstr(nowyi)+","+Cstr(allyi)+"]";

}


CString CMy115backDlg::getstate_4(CString qihao,CString datas[],int ubound,CString zufile,int hitd4[][4],CStdioFile &out) 
{
   int i,j,k,maxyi,yi,changdu=m_mas,chang,hitnum,yisum,bl,allyi=0,nowyi=0;
   if (changdu<8){changdu=8;}

   CString s,wr,c,ystr,b[3],head;
   bool first,hit[11],goflag=false;
   
 
   CStdioFile fin;
   int xu=1;
   fin.Open(zufile, CFile::modeRead);  

   do{
     fin.ReadString(s);s=delern(s);
     Split(s,b,bl,";");

     for (j=0;j<3;j++){

        for (k=0;k<4;k++){

          hitd4[j][k]=atoi(b[j].Mid(3*k,2))-1;

        }
     }

///////////////////////////////////////////////////////
     first=true;chang=0;ystr="";
     yi=0;maxyi=0;hitnum=0;yisum=0;
     for (i=0;i<ubound;i++){
       s=datas[i];
       for(j=0;j<11;j++){
         c=Cstr(j+1);
         if (j<9){c="0"+c;}
         hit[j]=(s.Find(c)>=0);
       } 


       
       if (hit[hitd4[0][0]] && hit[hitd4[0][1]] && hit[hitd4[0][2]] && hit[hitd4[0][3]] || 
           hit[hitd4[1][0]] && hit[hitd4[1][1]] && hit[hitd4[1][2]] && hit[hitd4[1][3]] || 
           hit[hitd4[2][0]] && hit[hitd4[2][1]] && hit[hitd4[2][2]] && hit[hitd4[2][3]]){

          if (!first){ystr=Cstr(yi)+","+ystr;}
          else {
            ystr="["+Cstr(yi)+"]";first=false;head="y"+padstrcisu(Cstr(yi),3,"0",0)+"zu4-"+padstrcisu(Cstr(xu),3,"0",0);
            if (nowyi<yi){nowyi=yi;}
          }

          if (yi>maxyi){maxyi=yi;}
          if (maxyi>allyi){allyi=maxyi;}
          chang+=Cstr(yi).GetLength()+1;
          hitnum++;yisum+=yi;
          if (chang>=changdu){break;}
          yi=0;
       } 
       else {yi++;}    

  
     }//for (i=0;i<ubound;i++){ 
     ystr="("+qihao+")"+head+"{"+Cstr(maxyi)+","+Cstr(hitnum*10000/yisum)+"}"+ystr+"\r\n";
     out.Write(ystr,ystr.GetLength());



//////////////////////////////////////////////////////////
     xu++;


   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   return "["+Cstr(nowyi)+","+Cstr(allyi)+"]";

}


CString CMy115backDlg::getstate_5(CString qihao,CString datas[],int ubound,CString zufile,int hitd5[][5],CStdioFile &out) 
{
   int i,j,k,maxyi,yi,changdu=m_mas,chang,hitnum,yisum,bl,allyi=0,nowyi=0;
   if (changdu<8){changdu=8;}
   CString s,wr,c,ystr,b[3],head;
   bool first,hit[11],goflag=false;
   
 
   CStdioFile fin;
   int xu=1;
   fin.Open(zufile, CFile::modeRead);  

   do{
     fin.ReadString(s);s=delern(s);
     Split(s,b,bl,";");

     for (j=0;j<3;j++){

        for (k=0;k<5;k++){

          hitd5[j][k]=atoi(b[j].Mid(3*k,2))-1;

        }
     }

///////////////////////////////////////////////////////
     first=true;chang=0;ystr="";
     yi=0;maxyi=0;hitnum=0;yisum=0;
     for (i=0;i<ubound;i++){
       s=datas[i];
       for(j=0;j<11;j++){
         c=Cstr(j+1);
         if (j<9){c="0"+c;}
         hit[j]=(s.Find(c)>=0);
       } 


       
       if (hit[hitd5[0][0]] && hit[hitd5[0][1]] && hit[hitd5[0][2]] && hit[hitd5[0][3]]  && hit[hitd5[0][4]] || 
           hit[hitd5[1][0]] && hit[hitd5[1][1]] && hit[hitd5[1][2]] && hit[hitd5[1][3]]  && hit[hitd5[1][4]] || 
           hit[hitd5[2][0]] && hit[hitd5[2][1]] && hit[hitd5[2][2]] && hit[hitd5[2][3]]  && hit[hitd5[2][4]] ){

          if (!first){ystr=Cstr(yi)+","+ystr;}
          else {
            ystr="["+Cstr(yi)+"]";first=false;head="x"+padstrcisu(Cstr(yi),4,"0",0)+"zu5-"+padstrcisu(Cstr(xu),3,"0",0);
            if (nowyi<yi){nowyi=yi;}
          }

          if (yi>maxyi){maxyi=yi;}
          if (maxyi>allyi){allyi=maxyi;}
          chang+=Cstr(yi).GetLength()+1;
          hitnum++;yisum+=yi;
          if (chang>=changdu){break;}
          yi=0;
       } 
       else {yi++;}    

  
     }//for (i=0;i<ubound;i++){ 
     ystr="("+qihao+")"+head+"{"+Cstr(maxyi)+","+Cstr(hitnum*10000/yisum)+"}"+ystr+"\r\n";
     out.Write(ystr,ystr.GetLength());



//////////////////////////////////////////////////////////
     xu++;


   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   return "["+Cstr(nowyi)+","+Cstr(allyi)+"]";
}


void CMy115backDlg::getzu3(CString srcfile) 
{
   CStdioFile fin,out;
   CString b[3],s,wr,c;
   int i,j,j1,k,ubound,bl,pos,r,tnum;
   bool you;

   fin.Open(srcfile, CFile::modeRead);  
   i=0;   
   do{
     fin.ReadString(s);
     i=i+1;    
   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   ubound=i;   
   int **data=new int *[ubound];
   for (i=0;i<ubound;i++){
     *(data+i)=new int [4];
     data[i][3]=0;
   }

   
   fin.Open(srcfile, CFile::modeRead);  
   i=0;   
   do{
     fin.ReadString(s);s=delern(s);
     pos=s.Find(":");
     if (pos>=0){s=s.Mid(pos+1);}
     Split(s,b,bl,",");
     for (j=0;j<3;j++){data[i][j]=atoi(b[j]);}
     i++; 
   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();   

   pos=srcfile.ReverseFind('\\');
   CString dirpath=srcfile.Left(pos+1);
   CString ymin=srcfile.Mid(pos+1);
   ymin=ymin.Left(ymin.GetLength()-4);
   CString zufile=dirpath+"zu_from_"+ymin+".txt";
   out.Open(zufile,CFile::modeCreate|CFile::modeWrite);
   int zu[4][3],gai[4];
   for (i=0;i<ubound;i++){
      //if (data[i][3]==1){continue;}
      k=0;
      for (j=0;j<3;j++){zu[0][j]=data[i][j];}
      gai[k]=i;tnum=-1;
      for (j=i+1;j<ubound;j++){
        //if (data[j][3]==1){continue;}
        you=false;

        for (j1=0;j1<=k;j1++){

          r=samenumber34(zu[j1],data[j],3);
          if (r==-1){you=true;break;}
          if (r>0){
            if (tnum==-1){tnum=r;}
            else {you=true;break;}
          }

        }

        if (! you){
          k++;
          for (j1=0;j1<3;j1++){zu[k][j1]=data[j][j1];}          
          gai[k]=j;
          if (k==3){
             data[gai[0]][3]=1;data[gai[1]][3]=1;data[gai[2]][3]=1;data[gai[3]][3]=1;
             break;
          }
        }
      }
      if (k==3){
        wr="";
        for (j=0;j<4;j++){
          for (j1=0;j1<3;j1++){
            c=Cstr(zu[j][j1]);
            if (zu[j][j1]<10){c="0"+c;}
            wr=wr+c+",";
          }
          wr=wr.Left(wr.GetLength()-1)+";";
        }
        wr=wr.Left(wr.GetLength()-1)+"\r\n";
        out.Write(wr,wr.GetLength());
      }
   }
   out.Close();
   for (i=0;i<ubound;i++){delete[] data[i];}
   delete[] data;

}


void CMy115backDlg::getzu5(CString srcfile) 
{

   CStdioFile fin,out;
   CString b[5],s,wr,c;
   int i,j,j1,j2,k,ubound,bl,pos,r;
   bool you;

   fin.Open(srcfile, CFile::modeRead);  
   i=0;   
   do{
     fin.ReadString(s);
     i=i+1;    
   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();
   ubound=i;   
   int **data=new int *[ubound];
   for (i=0;i<ubound;i++){
     *(data+i)=new int [6];
     data[i][5]=0;
   }


   
   fin.Open(srcfile, CFile::modeRead);  
   i=0;   
   do{
     fin.ReadString(s);s=delern(s);
     pos=s.Find(":");
     if (pos>=0){s=s.Mid(pos+1);}
     Split(s,b,bl,",");
     for (j=0;j<5;j++){data[i][j]=atoi(b[j]);}

     i++; 
   }
   while (fin.GetPosition()!=fin.GetLength());
   fin.Close();   


   pos=srcfile.ReverseFind('\\');
   CString dirpath=srcfile.Left(pos+1);
   CString ymin=srcfile.Mid(pos+1);
   ymin=ymin.Left(ymin.GetLength()-4);
   CString zufile=dirpath+"zu_from_"+ymin+".txt";
   out.Open(zufile,CFile::modeCreate|CFile::modeWrite);
   int zu[3][5],gai[3],tong[4],tongyuan[4];


   for (i=0;i<ubound;i++){
      //if (data[i][5]==1){continue;}
      k=0;

      for (j=0;j<5;j++){zu[0][j]=data[i][j];}
      gai[k]=i;
      for (j=0;j<4;j++){tong[j]=-1;}
      for (j=i+1;j<ubound;j++){
        //if (data[j][5]==1){continue;}
        you=false;
        for (j2=0;j2<4;j2++){tongyuan[j2]=tong[j2];}
        for (j1=0;j1<=k;j1++){          
          r=samenumber5(zu[j1],data[j],tong);
          if (r==-1){
            for (j2=0;j2<4;j2++){tong[j2]=tongyuan[j2];} 
            you=true;     
            break;      
          }
        }
        if (! you) {
          k++;
          for (j1=0;j1<5;j1++){zu[k][j1]=data[j][j1];}          
          gai[k]=j;
          if (k==2){
            data[gai[0]][5]=1;data[gai[1]][5]=1;data[gai[2]][5]=1;
            break;
          }
        }

      }
//MessageBox(Cstr(zu[0][0])+"  "+Cstr(zu[0][1])+"  "+Cstr(zu[0][2])+"  "+Cstr(zu[0][3])+"  "+Cstr(zu[0][4])+"\r\nk="+Cstr(k));

      if (k==2){
        wr="";
        for (j=0;j<3;j++){
          for (j1=0;j1<5;j1++){
            c=Cstr(zu[j][j1]);
            if (zu[j][j1]<10){c="0"+c;}
            wr=wr+c+",";
          }
          wr=wr.Left(wr.GetLength()-1)+";";
        }
        wr=wr.Left(wr.GetLength()-1)+"\r\n";
        out.Write(wr,wr.GetLength());
      }
   }
   out.Close();
   for (i=0;i<ubound;i++){delete[] data[i];}
   delete[] data;

}

int CMy115backDlg::samenumber5(int ma1[],int ma2[],int tong[]) 
{
   int r=0,i,j,k,r1=0;
   for (i=0;i<4;i++){     
     if (tong[i]>0){r++;}
   }
   for (i=0;i<5;i++){
     for (j=0;j<5;j++){
        if (ma1[i]==ma2[j]){
           r++;r1++;
           if (r>4 || r1>2){return -1;}
           for (k=0;k<4;k++){
             if (ma1[i]==tong[k]){return -1;}
             if (tong[k]==-1){tong[k]=ma1[i];break;}
           }          
        }
     }
   }  
      
   return r;
}

void CMy115backDlg::OnButton46() 
{
   
   if (JieMian!=101){jiemian(101);return;}  
   setbutton(FALSE);
   UpdateData(TRUE);
   int pos=m_dfile.ReverseFind('\\'),i,ubound;
   CString dirpath=m_dfile.Left(pos+1);

   CString datafile=dirpath+"45.txt",s,wr;
   DWORD dwAttr = ::GetFileAttributes(datafile); 
   if (dwAttr == 0xffffffff){MessageBox("没有数据文件");setbutton(TRUE);return;}
   CStdioFile out;
   out.Open(datafile, CFile::modeRead);

  
   i=0;   
   do{
     out.ReadString(s);
     i=i+1;    
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
   ubound=i;   
   CString *datas=new CString[ubound];
   CString *qihao=new CString[ubound];
   
  
   out.Open(datafile, CFile::modeRead);
   
   i=0;   
   do{
     out.ReadString(s);s=delern(s);    
     pos=s.Find('\t');
     s=s.Mid(pos+1);
     pos=s.Find('\t');
     qihao[i]=s.Left(pos);
     datas[i]=s.Mid(pos+1);
     s=datas[i];     
     

     i=i+1;
     
   }
   while (out.GetPosition()!=out.GetLength());
   out.Close();
   CString srcfile=dirpath+"zusrc.txt";
   switch(m_num){
     case 1:           
       dwAttr = ::GetFileAttributes(srcfile); 
       if (dwAttr == 0xffffffff){MessageBox("没有源组文件");}
       else {getstate(qihao[0],datas,ubound,srcfile);}
       break;
     case 2:
       countzu(qihao[0],datas,ubound,dirpath);
       break;
     case 3:
       getzu3(m_dfile);
       break;
     case 4:
       getzu4(m_dfile);
       break;
     case 5:

       getzu5(m_dfile);
       break;
     case 6:
       getbuyzu(m_dfile);
       break;
     case 7:
       preparedlcsta(qihao[0],datas,ubound,dirpath);
       break;

   }
   

   MessageBox("程序结束!");setbutton(TRUE);
}


void CMy115backDlg::preparedlcsta(CString qihao,CString datas[],int ubound,CString dirpath) 
{
   CString s,wr,c,c1,c2,c3,c4,c5,b[5];
   int i,i1,i2,i3,i4,i5,n,yi,j,k,j1,j2,maxyi,bl,pos,tnum,r;
   CStdioFile out,outsrc;
   bool you;

   CString zusrc=dirpath+"zusrc.txt";
   outsrc.Open(zusrc,CFile::modeCreate|CFile::modeWrite);
   CString buyzudir=dirpath+"dlcbuyzu\\";
   if(_access(buyzudir, 0) == -1){_mkdir(buyzudir);} 

/////////////3 begin////////////////////////////////
   CString zu3hit[165],zu3yi[165];
   k=0;
   for (i1=0;i1<11;i1++){
   for (i2=i1+1;i2<11;i2++){
   for (i3=i2+1;i3<11;i3++){
     n=0;yi=0;maxyi=0;
     for (i=0;i<ubound;i++){
       s=datas[i];
       c1=Cstr(i1+1);
       if (i1<9){c1="0"+c1;}
       c2=Cstr(i2+1);
       if (i2<9){c2="0"+c2;}
       c3=Cstr(i3+1);
       if (i3<9){c3="0"+c3;}
       if (s.Find(c1)>=0 && s.Find(c2)>=0 && s.Find(c3)>=0){
         n++;
         if (maxyi<yi){maxyi=yi;}
         yi=0;
       }
       else {yi++;}
     }
     wr=padstrcisu(Cstr(n),4," ",0)+":"+c1+","+c2+","+c3;
     zu3hit[k]=wr;
     wr=padstrcisu(Cstr(maxyi),4," ",0)+":"+c1+","+c2+","+c3;
     zu3yi[k]=wr;
     k++;

   }}}

   paixuztoa(zu3hit,165);paixuatoz(zu3yi,165);

   CString zusrcfile=dirpath+"zu3src.txt";
   out.Open(zusrcfile,CFile::modeCreate|CFile::modeWrite);
   wr=zusrcfile+"\r\n";
   pos=wr.ReverseFind('\\');
   wr=wr.Mid(pos+1);

   outsrc.Write(wr,wr.GetLength());

   wr="01,02,03;04,05,06;07,08,09;09,10,11\r\n";
   out.Write(wr,wr.GetLength());
   int data3[165][3];
   int zu[4][5];
/////////hit//////////////////////////////////////////////
   for (i=0;i<165;i++){
     s=zu3hit[i];
     pos=s.Find(":");
     s=s.Mid(pos+1);
     Split(s,b,bl,",");
     for (j=0;j<3;j++){data3[i][j]=atoi(b[j]);}
   }
   
   for (i=0;i<165;i++){      
      k=0;
      for (j=0;j<3;j++){zu[0][j]=data3[i][j];}
      tnum=-1;
      for (j=i+1;j<165;j++){        
        you=false;

        for (j1=0;j1<=k;j1++){

          r=samenumber34(zu[j1],data3[j],3);
          if (r==-1){you=true;break;}
          if (r>0){
            if (tnum==-1){tnum=r;}
            else {you=true;break;}
          }

        }

        if (! you){
          k++;
          for (j1=0;j1<3;j1++){zu[k][j1]=data3[j][j1];}
          if (k==3){             
             break;
          }
        }
      }


      if (k==3){
        wr="";
        for (j=0;j<4;j++){
          for (j1=0;j1<3;j1++){
            c=Cstr(zu[j][j1]);
            if (zu[j][j1]<10){c="0"+c;}
            wr=wr+c+",";
          }
          wr=wr.Left(wr.GetLength()-1)+";";
        }
        wr=wr.Left(wr.GetLength()-1)+"\r\n";
        out.Write(wr,wr.GetLength());
      }


   }
   
/////////yi//////////////////////////////////////////////

   for (i=0;i<165;i++){
     s=zu3yi[i];
     pos=s.Find(":");
     s=s.Mid(pos+1);
     Split(s,b,bl,",");
     for (j=0;j<4;j++){data3[i][j]=atoi(b[j]);}
   }

   
   for (i=0;i<165;i++){      
      k=0;
      for (j=0;j<3;j++){zu[0][j]=data3[i][j];}
      tnum=-1;
      for (j=i+1;j<165;j++){        
        you=false;

        for (j1=0;j1<=k;j1++){

          r=samenumber34(zu[j1],data3[j],3);
          if (r==-1){you=true;break;}
          if (r>0){
            if (tnum==-1){tnum=r;}
            else {you=true;break;}
          }

        }

        if (! you){
          k++;
          for (j1=0;j1<3;j1++){zu[k][j1]=data3[j][j1];}
          if (k==3){             
             break;
          }
        }
      }
      if (k==3){
        wr="";
        for (j=0;j<4;j++){
          for (j1=0;j1<3;j1++){
            c=Cstr(zu[j][j1]);
            if (zu[j][j1]<10){c="0"+c;}
            wr=wr+c+",";
          }
          wr=wr.Left(wr.GetLength()-1)+";";
        }
        wr=wr.Left(wr.GetLength()-1)+"\r\n";
        out.Write(wr,wr.GetLength());
      }
   }
   out.Close();

/////////////3 end////////////////////////////////   

/////////////4 begin////////////////////////////////
   CString zu4hit[330],zu4yi[330];
   k=0;
   for (i1=0;i1<11;i1++){
   for (i2=i1+1;i2<11;i2++){
   for (i3=i2+1;i3<11;i3++){
   for (i4=i3+1;i4<11;i4++){
     n=0;yi=0;maxyi=0;
     for (i=0;i<ubound;i++){
       s=datas[i];
       c1=Cstr(i1+1);
       if (i1<9){c1="0"+c1;}
       c2=Cstr(i2+1);
       if (i2<9){c2="0"+c2;}
       c3=Cstr(i3+1);
       if (i3<9){c3="0"+c3;}
       c4=Cstr(i4+1);
       if (i4<9){c4="0"+c4;}
       if (s.Find(c1)>=0 && s.Find(c2)>=0 && s.Find(c3)>=0 && s.Find(c4)>=0){
         n++;
         if (maxyi<yi){maxyi=yi;}
         yi=0;
       }
       else {yi++;}
     }
     wr=padstrcisu(Cstr(n),4," ",0)+":"+c1+","+c2+","+c3+","+c4;
     zu4hit[k]=wr;
     wr=padstrcisu(Cstr(maxyi),4," ",0)+":"+c1+","+c2+","+c3+","+c4;
     zu4yi[k]=wr;
     k++;

   }}}}

   paixuztoa(zu4hit,330);paixuatoz(zu4yi,330);
   zusrcfile=dirpath+"zu4src.txt";
   out.Open(zusrcfile,CFile::modeCreate|CFile::modeWrite);
   wr=zusrcfile+"\r\n";
   pos=wr.ReverseFind('\\');
   wr=wr.Mid(pos+1);
   outsrc.Write(wr,wr.GetLength());
   wr="01,02,03,04;05,06,07,08;09,10,11,01\r\n";
   out.Write(wr,wr.GetLength());
   int data4[330][4];
   
/////////hit//////////////////////////////////////////////
   for (i=0;i<330;i++){
     s=zu4hit[i];
     pos=s.Find(":");
     s=s.Mid(pos+1);
     Split(s,b,bl,",");
     for (j=0;j<4;j++){data4[i][j]=atoi(b[j]);}
   }

   
   for (i=0;i<330;i++){      
      k=0;
      for (j=0;j<4;j++){zu[0][j]=data4[i][j];}
      tnum=-1;
      for (j=i+1;j<330;j++){        
        you=false;

        for (j1=0;j1<=k;j1++){

          r=samenumber34(zu[j1],data4[j],4);
          if (r==-1){you=true;break;}
          if (r>0){
            if (tnum==-1){tnum=r;}
            else {you=true;break;}
          }

        }

        if (! you){
          k++;
          for (j1=0;j1<4;j1++){zu[k][j1]=data4[j][j1];}
          if (k==2){             
             break;
          }
        }
      }
      if (k==2){
        wr="";
        for (j=0;j<3;j++){
          for (j1=0;j1<4;j1++){
            c=Cstr(zu[j][j1]);
            if (zu[j][j1]<10){c="0"+c;}
            wr=wr+c+",";
          }
          wr=wr.Left(wr.GetLength()-1)+";";
        }
        wr=wr.Left(wr.GetLength()-1)+"\r\n";
        out.Write(wr,wr.GetLength());
      }
   }

/////////yi//////////////////////////////////////////////
   for (i=0;i<330;i++){
     s=zu4yi[i];
     pos=s.Find(":");
     s=s.Mid(pos+1);
     Split(s,b,bl,",");
     for (j=0;j<4;j++){data4[i][j]=atoi(b[j]);}
   }

   
   for (i=0;i<330;i++){      
      k=0;
      for (j=0;j<4;j++){zu[0][j]=data4[i][j];}
      tnum=-1;
      for (j=i+1;j<330;j++){        
        you=false;

        for (j1=0;j1<=k;j1++){

          r=samenumber34(zu[j1],data4[j],4);
          if (r==-1){you=true;break;}
          if (r>0){
            if (tnum==-1){tnum=r;}
            else {you=true;break;}
          }

        }

        if (! you){
          k++;
          for (j1=0;j1<4;j1++){zu[k][j1]=data4[j][j1];}
          if (k==2){             
             break;
          }
        }
      }
      if (k==2){
        wr="";
        for (j=0;j<3;j++){
          for (j1=0;j1<4;j1++){
            c=Cstr(zu[j][j1]);
            if (zu[j][j1]<10){c="0"+c;}
            wr=wr+c+",";
          }
          wr=wr.Left(wr.GetLength()-1)+";";
        }
        wr=wr.Left(wr.GetLength()-1)+"\r\n";
        out.Write(wr,wr.GetLength());
      }
   }
   out.Close();

/////////////4 end////////////////////////////////   
/////////////5 begin////////////////////////////////
   CString zu5hit[462],zu5yi[462];
   k=0;
   for (i1=0;i1<11;i1++){
   for (i2=i1+1;i2<11;i2++){
   for (i3=i2+1;i3<11;i3++){
   for (i4=i3+1;i4<11;i4++){
   for (i5=i4+1;i5<11;i5++){
     n=0;yi=0;maxyi=0;
     for (i=0;i<ubound;i++){
       s=datas[i];
       c1=Cstr(i1+1);
       if (i1<9){c1="0"+c1;}
       c2=Cstr(i2+1);
       if (i2<9){c2="0"+c2;}
       c3=Cstr(i3+1);
       if (i3<9){c3="0"+c3;}
       c4=Cstr(i4+1);
       if (i4<9){c4="0"+c4;}
       c5=Cstr(i5+1);
       if (i5<9){c5="0"+c5;}
       if (s.Find(c1)>=0 && s.Find(c2)>=0 && s.Find(c3)>=0 && s.Find(c4)>=0 && s.Find(c5)>=0){
         n++;
         if (maxyi<yi){maxyi=yi;}
         yi=0;
       }
       else {yi++;}
     }
     wr=padstrcisu(Cstr(n),4," ",0)+":"+c1+","+c2+","+c3+","+c4+","+c5;
     zu5hit[k]=wr;
     wr=padstrcisu(Cstr(maxyi),4," ",0)+":"+c1+","+c2+","+c3+","+c4+","+c5;
     zu5yi[k]=wr;
     k++;

   }}}}}

   paixuztoa(zu5hit,462);paixuatoz(zu5yi,462);

   zusrcfile=dirpath+"zu5src.txt";
   out.Open(zusrcfile,CFile::modeCreate|CFile::modeWrite);
   wr=zusrcfile+"\r\n";
   pos=wr.ReverseFind('\\');
   wr=wr.Mid(pos+1);
   outsrc.Write(wr,wr.GetLength());
   wr="01,02,03,04,05;05,06,07,08,09;09,10,11,01,02\r\n";
   out.Write(wr,wr.GetLength());
   int data5[462][5],tong[4],tongyuan[4];
   
/////////hit//////////////////////////////////////////////
   for (i=0;i<462;i++){
     s=zu5hit[i];
     pos=s.Find(":");
     s=s.Mid(pos+1);
     Split(s,b,bl,",");
     for (j=0;j<5;j++){data5[i][j]=atoi(b[j]);}
   }

   
   for (i=0;i<462;i++){
      
      k=0;

      for (j=0;j<5;j++){zu[0][j]=data5[i][j];}
      
      for (j=0;j<4;j++){tong[j]=-1;}
      for (j=i+1;j<462;j++){
        
        you=false;
        for (j2=0;j2<4;j2++){tongyuan[j2]=tong[j2];}
        for (j1=0;j1<=k;j1++){          
          r=samenumber5(zu[j1],data5[j],tong);
          if (r==-1){
            for (j2=0;j2<4;j2++){tong[j2]=tongyuan[j2];} 
            you=true;     
            break;      
          }
        }
        if (! you) {
          k++;
          for (j1=0;j1<5;j1++){zu[k][j1]=data5[j][j1];}          
          
          if (k==2){
           
            break;
          }
        }

      }
      if (k==2){
        wr="";
        for (j=0;j<3;j++){
          for (j1=0;j1<5;j1++){
            c=Cstr(zu[j][j1]);
            if (zu[j][j1]<10){c="0"+c;}
            wr=wr+c+",";
          }
          wr=wr.Left(wr.GetLength()-1)+";";
        }
        wr=wr.Left(wr.GetLength()-1)+"\r\n";
        out.Write(wr,wr.GetLength());
      }
   }
/////////yi//////////////////////////////////////////////

   for (i=0;i<462;i++){
     s=zu5yi[i];
     pos=s.Find(":");
     s=s.Mid(pos+1);
     Split(s,b,bl,",");
     for (j=0;j<5;j++){data5[i][j]=atoi(b[j]);}
   }

   
   for (i=0;i<462;i++){
      
      k=0;

      for (j=0;j<5;j++){zu[0][j]=data5[i][j];}
      
      for (j=0;j<4;j++){tong[j]=-1;}
      for (j=i+1;j<462;j++){
        
        you=false;
        for (j2=0;j2<4;j2++){tongyuan[j2]=tong[j2];}
        for (j1=0;j1<=k;j1++){          
          r=samenumber5(zu[j1],data5[j],tong);
          if (r==-1){
            for (j2=0;j2<4;j2++){tong[j2]=tongyuan[j2];} 
            you=true;     
            break;      
          }
        }
        if (! you) {
          k++;
          for (j1=0;j1<5;j1++){zu[k][j1]=data5[j][j1];}          
          
          if (k==2){
           
            break;
          }
        }

      }
      if (k==2){
        wr="";
        for (j=0;j<3;j++){
          for (j1=0;j1<5;j1++){
            c=Cstr(zu[j][j1]);
            if (zu[j][j1]<10){c="0"+c;}
            wr=wr+c+",";
          }
          wr=wr.Left(wr.GetLength()-1)+";";
        }
        wr=wr.Left(wr.GetLength()-1)+"\r\n";
        out.Write(wr,wr.GetLength());
      }
   }

   out.Close();

/////////////5 end////////////////////////////////   


   outsrc.Close();
   getbuyzu(zusrc);
}


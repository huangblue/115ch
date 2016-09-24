// 115backDlg.h : header file
//

#if !defined(AFX_115BACKDLG_H__8C14DECB_31F4_4A18_BEE2_95DF30A3DA0E__INCLUDED_)
#define AFX_115BACKDLG_H__8C14DECB_31F4_4A18_BEE2_95DF30A3DA0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy115backDlg dialog

class CMy115backDlg : public CDialog
{
// Construction
public:
        void distantofpath(CString mpath);
        void distantoffile(CString sfile);
        void jiaminli(CString dirpath,CString mpath,CString qihao,bool mode);
        void buyjia(CString targetfile,CString sourcefile,CString *qihao,int malen,CString *datas);
        void jiaxu(CString sfile,int num);
        CString buycheck(CString dirpath,CString *qihao,CString *datas,int ubound,CString infile,CString goodmapath,CString wl);
        void wrazuifile(CString infile,CStdioFile &out,CString head);
        void sucnum(CString dirpath,int xian[]);
        CString tjyilianno(CString dirpath,CString infile,int begin,int buyqi,int yilow,int yihigh,int lianlow,int lianhigh); 
        void quanbuy(int maiqi,bool finish,int jiang,int &tou,int &getjiang);
        CString getlastone(CString file);
        void tongji(CString dirpath,CString infile,CString outfile,CString canstr,CString qi,bool quanflag);
        void tjyilianall(CString dirpath,CString canfile,CString qi,bool quanflag);
        CString tjyilian(CString lpath,CString infile,int begin,int buyqi,int yilow,int yihigh,int lianlow,int lianhigh);
        void checkyilian(CString dirpath,CString *qihao,CString *datas,int ubound,CString buypath);
        void lianrecord(CString dirpath,bool chengdu);
        void lianxu(CString dirpath);
        
        
        
        
        
       
        
        bool jxbaijie(CString jxfile,CString yuanfile);
        
        
        bool jxduijie(CString jxfile,CString yuanfile);
        void gxyz(CString dirpath,int yilou[4][10][50],int zilou[4][10][50],CString rma);        
        void dlc5s(CString srcstr,CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlcdowngenxins(CString sfile,CString *qihao,CString *datas,small **data,int ubound);
        void dlc6s(CString srcstr,CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlc4s(CString srcstr,CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void numbuy89a(CString dirpath,CString qihao,CString sfile);
        void dlcwritefsp(CString dirpath,CString qihao);
        void dlcwritebuy(CString dirpath,CString qihao);
        void dlcbuyzs(CString bfile,CString *qihao,CString *datas,int ubound,int num);
        void dlc6down(CString srcstr,CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void numbuy(CString dirpath,CString qihao,CString sfile);
        void dlctjstep1(CString dirpath,CString qihao,CString npath,CString tjpath,CString jigofile);        
        void writenum(CString dirpath,int wei);
        int daydiff(CString day1,CString day2);
        void genxinzu(CString dirpath,CString srcfile1,CString srcfile2,CString srcfileall,CString *qihao,CString *datas,small **data,int ubound);
        CString onezu(CString bqi,CString pqi,CString zu,CString *qihao,CString *datas,small **data,int ubound,int mode);
       
        void writesecond(CString dirpath,int wei);
        void back1hitsu(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void juhedateymod(CString dirpath,CString jiqi);
        void genxindlc_78(CString dirpath,CString *qihao,CString *datas,int ubound,CString zufile,int mal);
        void genxindlc6_78(CString dirpath,CString *qihao,CString *datas,int ubound);
        void genxindlc5_78(CString dirpath,CString *qihao,CString *datas,int ubound);
        void genxindlc4_78(CString dirpath,CString *qihao,CString *datas,int ubound);
        int dlc6(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        int dlc5(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        int dlc4(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        int dlc3(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        int dlc2(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        int dlc1(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlczero2(CString dirpath,CString *qihao,CString *datas,small **data,int ubound); 
        void dlctwo2(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlctwo3(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlctwo4(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlctwo5(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlctwo6(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlcdowngenxinfile(CString sfile,CString *qihao,CString *datas,small **data,int ubound);
        void dlc3down(CString srcstr,CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlc4down(CString srcstr,CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlc5down(CString srcstr,CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlcsuc6(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlcsuc5(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlcsuc4(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlcsuc2(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlcsuc1(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlcwritemobile(CString dirpath,CString jingdu);
        void dlcotherdata2(CString dirpath);
        bool dlcotherdata(CString dirpath);
        void getallduisu(CString dirpath);
        void getallworksu(CString dirpath);
        void juhedatework(CString dirpath,CString jiqi);
        void getallhousu(CString dirpath);
        void juhedatehou(CString dirpath,CString jiqi);
        void juhedateybig(CString dirpath,CString jiqi);
        void getallbigsu(CString dirpath); 
        void getworkallsu(CString dirpath);
        void getallsu(CString dirpath); 
        void getdlchighdui(CString dirpath);
        void gendlcalldui(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void getallcui(CString dirpath);
        void deleterepeatzu(CString zufile,CString dirpath);
        void getdlchighwork(CString dirpath);
        void getdlchigh(CString dirpath);
        bool onway(CString str,int num);
        void genxinwork5(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void juhedatey(CString dirpath,CString jiqi);
        void genxinwork1(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void genxinwork2(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void genxinwork3(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void genxinwork4(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void baidudlcdatamanage(CString srcfile);
        void dlcafterbig(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void genxinwork(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlc1zu(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlc2zu(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlc3zu(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlc4zu(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void juhew5(CString dirpath);
        void dlc5onedetail(CString dirpath,CString *qihao,CString *datas,small **data,int ubound,CString xma);
        void dlc5zu(CString dirpath,CString *qihao,CString *datas,small **data,int ubound);
        void dlcsuc3(CString dirpath,CString *qihao,CString *datas,small **data,int ubound); 
        void juhedate(CString dirpath,CString jiqi);
        void checkdlcbuy10(CString duipath,CString *qihao,CString *datas,int ubound);
        void getdlcduibuy10(CString duipath);
        void getxzu(CString *qihao,CString *datas,int ubound,CString zu2[],CString zu3[],CString xzu2[],CString xzu3[],CString beyuqi); 
        void getdlcduibuy(CString duipath,CString srcfile);
        void dlcdui(CString duipath,CString *qihao,CString *datas,int ubound); 
        void dlcduione(CString duipath,CString *qihao,CString *datas,int ubound,CString zu2[],CString zu3[]
                       ,CStdioFile &out,int &sum,int &maxyi,int &sumsp,int &maxyisp
                       ,int buyyi[][165],int maxbuyyi[][165]
                       ,int buyyicisu[][165]
                       ,int buyyisum[][165],CString buyyistr[][165]
                       ,CString xzu2[],CString xzu3[]); 
        void dlcduiwr(CString duipath,CString *qihao,CString *datas,int ubound,CString zu2[],CString zu3[]);
        void paixuatozi(int str[], int n);
        void runatozi(int pData[],int left,int right);
        void deletest(CString dirpath);
        void paixuztoai(int str[], int n);
        void runztoai(int pData[],int left,int right);
        void dlcsmallbian3(CString dirpath,CString tstr,CString qi);
        void dlcsmallbian4(CString dirpath,CString tstr,CString qi);
        void dlcsmallbian5(CString dirpath,CString tstr,CString qi);
        void dlcsmallbian2(CString dirpath,CString tstr,CString qi);
        void dlcsmgenxinall(CString dirpath,CString *qihao,CString *datas,small **data,int ubound); 
        void dlcsmgenxin(CString zufile,CString *qihao,CString *datas,small **data,int ubound);
        void dlcsmallbian(CString dirpath,CString tstr,CString qi,int dnow);
        int samenumber(CString str1,CString str2);
        CString get4111zu(small **data,int ubound);
        CString get3222zu(small **data,int ubound);
        void dlcji10(CString buyfile,int jiang,int chang);
        CString get2333zu(small **data,int ubound);
        void dlcji(CString buyfile,CString namehead,int jiang);
        void dlcmayilou(CString dirpath,CString *qihao,CString *datas,small **data,int ubound); 
        void dlcyilou(CString dirpath,CString *qihao,CString *datas,small **data,int ubound); 
        void getdlcdatayilou(CString dirpath,CString *qihao,CString *datas,small **data,int ubound); 

        void getstateone(CString *qihao,CString datas[],int ubound,CString dirpath); 
        void getstateall(CString *qihao,CString datas[],int ubound,CString dirpath); 
        int tongsu(CString str1,CString str2);
        void getzusrcfromzuhe(CString *qihao,CString datas[],int ubound,CString zuhesrcfile); 
        int getzusrcfromzuhe_3(CString dirpath,CString *qihao,int ubound,CString zufile,small **datan,int hitd3[][3]);
        int getzusrcfromzuhe_4(CString dirpath,CString *qihao,int ubound,CString zufile,small **datan,int hitd4[][4]);
        int getzusrcfromzuhe_5(CString dirpath,CString *qihao,int ubound,CString zufile,small **datan,int hitd5[][5]);

        void getzuhe4(CString dirpath); 
        void getzuhe5(CString dirpath); 
        void getzuhe3(CString dirpath); 
        int sortafile_norepeat(CString filename,int xu);
        int sortafileztoa_norepeat(CString filename);
        void deletezusrcbystate(CString statefile);
        void getzusrcfromstatefile(CString statefile);
        void zudetail_3(CString *qihao,int ubound,CString zufile,small **datan,CString detailpath,int hitd3[][3]);
        void zudetail_4(CString *qihao,int ubound,CString zufile,small **datan,CString detailpath,int hitd4[][4]);
        void zudetail_5(CString *qihao,int ubound,CString zufile,small **datan,CString detailpath,int hitd5[][5]);
        void zudetail(CString *qihao,CString datas[],int ubound,CString srcfile);
        void getfromanother(CString filesrc,CString fileget);
        void preparedlcsta(CString qihao,CString datas[],int ubound,CString dirpath);
        CString getstate_5(CString *qihao,int ubound,CString zufile,int hitd5[][5],CStdioFile &out,CStdioFile &outb,small **datan); 
        CString getstate_4(CString *qihao,int ubound,CString zufile,int hitd4[][4],CStdioFile &out,CStdioFile &outb,small **datan); 
        void getstate(CString *qihao,CString datas[],int ubound,CString srcfile);
        CString getstate_3(CString *qihao,int ubound,CString zufile,int hitd3[][3],CStdioFile &out,CStdioFile &outb,small **datan); 
        void getbuyzu(CString srcfile);
        void getzu5(CString srcfile);
        int samenumber5(int ma1[],int ma2[],int tong[]);
        void getzu4(CString srcfile);
        void getzu3(CString srcfile);
        int samenumber34(int ma1[],int ma2[],int ubound);
        void countzu(CString qihao,CString datas[],int ubound,CString dirpath);
        void deletedir_tonew(CString dirpath);
        void copydirectory_tonew(CString srcpath,CString targetpath,int new_z);
        void preparefirst_b(CString datafile,int tqs,int dirsu,CString qihao[],CString datas[],int ubound);
        void f27(CString qihao[],CString datas[],int ubound);
        void f28(CString qihao[],CString datas[],int ubound);
        void makebuyfilenew(CString dirpath,CString new_type,int new_num,int new_x,int new_y,int new_z);
        void getdlcbuydir(CString dirpath,CString new_type,CString new_a_type,int new_num,int new_yilou,int new_x,int new_y,int new_z);
        void copydirectory(CString srcpath,CString targetpath);
        void backtohistry(CString dirpath,int days);
        void adeletefileofdir_(CString path);
        void adeletefileofdir(CString apath);
        void makebuyfile(CString datafile);
        void deletefileofdir(CString dirpath);
        void dlctoubianrand(small **zu,int ubound,small **tzu,int a0[],int a1[],int a2[],int a3[]);
        void preparefirst(CString datafile,int tqs,int dirsu);
        void deletenouseyiloufile(CString dirpath);
        void getdlcbuyfile(CString dirpath,CString qihao,CString datas[],int ubound);
        void yiloufilegenxin(CString dirpath);
        void deletehe(CString dirpath);
        void dlczeroall(CString dirpath);
        
        int  dlcrefresh(CString dirpath,CString qihao[],CString datas[],int ubound);
        void dlcmanagetjsrc(CString dirpath);
        void deletedir(CString dirpath);
        void deletenullfile(CString file);
        void dlccopyabuyfile(CString dirpath,CString mode,int d78); 
        void dlcbuydata(CString dirpath);
        void dlczeromanage(CString zerofile,CString qihao);
        void ssqfufen(CString head,CString tail,CString wei,CString touzu[],int &k);
        void ssqfufen(CString head,CString tail,int qianall,int qianmasu,CString touzu[],int &k);
        void ssqfufen(CString head,CString tail,CString touzu[],int &k);
        void jointwolotterfiles(CString file1,CString file2,CString dirpath);
        int getcansu(CString dirpath,int type);
        void copybuyfile(CString dirpath,int wei);
        void dlccopybuyfile(CString dirpath,int d78);
        void ssqmegarecords(CString srcfile,CString **records,CStdioFile &outz);
        void dlcrecords(CString srcfile,CString ***records,CStdioFile &outz,CStdioFile &outz3,CStdioFile &outz4);
        void joindlcsrcdata(CString datafile);
        void checkssqbuyfile(CString dirpath,CString qihao[],CString datas[],int ubound,CString tjsrc);
        void checkmegabuyfile(CString dirpath,CString qihao[],CString datas[],int ubound,CString tjsrc);

        
        void ssqtoubianrand(CString zu[],CString *tzu,int ubound);
        void megatoubianrand(CString zu[],int &ubound);

        bool islotterdeng(CString ma1,CString ma2); 
        bool islotterdeng(CString ma1,CString ma2,int wei); 
        int sortafileztoa(CString filename); 
        CString checkdlcbuyfile(CString yumafile,CString qihao[],CString datas[],int ubound,CString tjsrc,CString zupath);
        
        void getmegabuyfile(CString dirpath);
        void getmegahe(CString dirpath);
        void checkmegahccode(CString dirpath,CString qihao[],CString datas[],int ubound,CString buyfile);
        void getmegabuycode(CString dirpath);
        int megagorefresh3(CString gofile,CString qihao[],CString datas[],int ubound,CStdioFile &outgosta,bool duo,int &zuida,int &zuidae);
        void megaallrefresh(CString dirpath,CString qihao[],CString datas[],int ubound); 
        void megaendbtzu(small btzu[],small btzu2[],int &back,int &fromwei);
        void megabtzu(small btzu[],small btzu2[],int &back,int &fromwei);
        void megafindtong(CString qihao[],CString datas[],small **data,CString dirpath,int ubound);
        void getmmdata(CString jigo,CString urlmode);
        
        
        
        
        
        
        
        
        
        void getonessczu(CString zu[],CString dirpath);
        
        void getqxcbuycode(CString buypath);
        void getsscbuycode(CString dirpath);
        void getqxcbuyfile(CString dirpath);
        void getssqbuyfile(CString dirpath,CString qihao,CString datas[]);
        
        void getqxche(CString dirpath);
        void getssche(CString dirpath);
        
        
        int qxcgorefresh3(CString gofile,CString qihao[],CString datas[],int ubound,CStdioFile &outgosta,bool duo,int &zuida);
        
        void checkqxchccode(CString dirpath,CString qihao[],CString datas[],int ubound,CString buyfile);
        void qxcallrefresh(CString dirpath,CString qihao[],CString datas[],int ubound);
        void qxcfindtong(CString qihao[],CString datas[],small **data,CString dirpath,int ubound);
        void checksschccode(CString dirpath,CString qihao[],CString datas[],int ubound,CString buyfile,int yimax[]);
        void ssc3allrefresh(CString dirpath,CString qihao[],CString datas[],int ubound);
        int sscgorefresh3(CString gofile,CString qihao[],CString datas[],int ubound,CStdioFile &outgosta,bool duo,int &zuida);
        
        void sscfindtong3(CString qihao[],CString datas[],small **data,CString dirpath,int ubound);
        void srnd(small sscrnd[]);
        CString gethtml(CString url);
        int getyeahspecial(CString *special);
        int getyeahhao(CString *haos,CString url,int ubound,int nowsu,CStdioFile &out);
        int getsinahao(CString *haos,CString url,int ubound,int nowsu,CStdioFile &out);
        void visiturl(CString url);
        void taobao_dianfile(CString dirpath,CString dianfile);
        void taobaoalllinks(CString dirpath);
        int sortafileatoz_2(CString filename);
        void taobaolinks(CString datafile,CString dirpath,CStdioFile &out2);
        void taobaolinks_chang(CString *data,int ubound,CString dirpath,CString shun);
        void qxcgosta(CString stafile,CString stafileall,int filenum);
        void sscgosta(CString stafile,CString stafileall,int filenum);
        void ssqgosta(CString stafile,CString stafileall,int filenum);
        

        int qxcgorefresh(CString gofile,CString qihao[],CString datas[],int ubound,bool duo,CStdioFile &staout,CStdioFile &staoutall);
        

       
        int sortafileatoz(CString filename);

       
        

        void init_genrand(unsigned long s);

        unsigned long myrnd(void);

        
                                 
        

        

        

        


        

        

        

        void qxcbtzu(small btzu1[],small btzu2[],small btzu3[],small btzu4[],int &back,int &fromwei);


 
        

        void sscbtzu(small btzu1[],small btzu2[],small btzu3[],small btzu4[],int &back,int &fromwei);
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
        CString binaryatoz(unsigned int x);
        
        void paimasubiao(int **pData,int left,int right,int biao,int bound);
        
        void paimasu3_hot(int **pData,int left,int right);
        void mactowindow(CString filename);
             
        int sortafile_2(CString filename);
        void paimasu2(int **pData,int left,int right);
        void tcompany_check();
        void tcompany();
        void skydrive();
        void paimasu1(int **pData,int left,int right);
        void checkdasu(int qianqi,int houqi,int hit);
        void filenamejiam(CString &fname,bool flag); 
        void sarrayrandom(CString a[],int alen);
        
        void paimasu3(int **pData,int left,int right);
        
        
        void paimasu3_5(int **pData,int left,int right);
        int sortafile_1(CString filename);
        int myrand();
        
        void paimasu(int **pData,int left,int right);
        
        void addfilename(CString jigo);
        
          
        void BrowseDir(CString strDir);
	
	
	void DoEvents();
	void jiemian(int xuhao);
	CString delern(CString s);
	
	
	CString Cstr(int n);
        CString padstrcisu(CString tstr,int n,CString tr,int direc);	
	void Split(CString a,CString *b,int &c,CString d);
	void paixuztoa(CString str[],int n);	
	void paixuatoz(CString str[],int n);	
	
	void OpenFile();
        
	void OnCancel();
	void tui(CStdioFile &file);
	void tui(CStdioFile &file1,CStdioFile &file2);
	
	void setbutton(bool x);
	
	
	
	
	
        void sortafile(CString filename);
        
	
        void runztoa_1(int **pData,CString *chuan,int left,int right);
        void runztoa_2(int **pData,CString *chuan,int left,int right);
        void runztoa_1(int **pData,int left,int right);
        void runztoa(CString pData[],int left,int right);
        void runatoz(CString pData[],int left,int right);
        void yiloupaixu_zu(CString fname,int mnum);
        void yiloupaixu(CString fname,int mnum);
        
        CString Cstr(unsigned int n);
        CString Cstr(unsigned __int64 n); 
        void getcjsscdata(int pages,CString jigo,CString urlmode);
        void getklcdata(CString jigo,CString url);
        void paixu_status(CString statusfile);
        CString qijia1(CString qistr);
        void multpaixu_recur(int **pData,int col,int *gesu,CString *ming,int left,int right);
        bool multicompareGreater(int **pData,int col,int n,int m );
        bool multicompareSmaller(int **pData,int col,int n,int m );


///////////////////////////////////////////////////
	void getjiangstate(CString fang, CString data[], long ubound,int djiang,CStdioFile &out);
//////////////////////////////////////////////////////////////////////////////////////////////////////
        

       



        
        
        


       

	
	



////////////////////////////////////////////////////////////////////////////////////////
	int m_nMax,m_nStep;
	CMy115backDlg(CWnd* pParent = NULL);	// standard constructor
        int ssc3paiming,ssc3num;
// Dialog Data
	//{{AFX_DATA(CMy115backDlg)
	enum { IDD = IDD_MY115BACK_DIALOG };
	CString	m_mo;
	int		m_num;
	int		m_mas;
	int		m_qmas;
	long	m_btui;
	long	m_etui;
	long	m_b;
	long	m_e;
	int		m_su;	
	CString	m_dfile;
        CString MMO;
	CString	m_bfile;
	long	m_ql;
	CString	m_ssc5;
	int		m_wb;
	int		m_we;
	int		m_tuib;
	int		m_tuie;
	long	m_step;
        
        //int *eachPosNum;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy115backDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	int JieMian;
	int tuichu,sharpnum;
        CString buypath; 
        bool sharpflag;
        int targetnum;
        //int dlc3h1_25,dlc3h1_b25;
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy115backDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit2();
	afx_msg void OnChangeEdit3();
	afx_msg void OnChangeEdit4();
	afx_msg void OnChangeEdit5();
	afx_msg void OnChangeEdit6();
	afx_msg void OnChangeEdit7();
	afx_msg void OnChangeEdit8();
	afx_msg void OnChangeEdit9();
	afx_msg void OnChangeEdit10();
	afx_msg void OnChangeEdit11();
	afx_msg void OnChangeEdit12();
	afx_msg void OnChangeEdit13();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton8();
	afx_msg void OnButton10();
	afx_msg void OnButton13();
	afx_msg void OnButton14();
	afx_msg void OnButton15();
	afx_msg void OnButton16();
	afx_msg void OnButton26();
	afx_msg void OnButton27();
	afx_msg void OnButton28();
	afx_msg void OnButton29();
	afx_msg void OnButton30();
	afx_msg void OnButton40();
	afx_msg void OnButton41();
	afx_msg void OnButton42();
	afx_msg void OnButton34();
	afx_msg void OnButton36();
	afx_msg void OnButton37();
	afx_msg void OnButton43();
	afx_msg void OnButton25();
	afx_msg void OnButton44();
	afx_msg void OnButton45();
	afx_msg void OnButton31();
	afx_msg void OnButton32();
	afx_msg void OnButton33();
	afx_msg void OnButton9();	
	afx_msg void OnChangeEdit14();
	afx_msg void OnButton46();
	afx_msg void OnButton47();
	afx_msg void OnButton48();
	afx_msg void OnButton49();
	afx_msg void OnButton50();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_115BACKDLG_H__8C14DECB_31F4_4A18_BEE2_95DF30A3DA0E__INCLUDED_)

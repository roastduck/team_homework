import java.util.*;import java.io.*;public strictfp class Input{static class llllllll{int l1llllll;int
ll1lllll;llllllll l11lllll;long lll1llll;public llllllll(int l1l1llll,int ll11llll){l1llllll=l1l1llll
;ll1lllll=ll11llll;}public llllllll(double l1l1llll,double ll11llll){l1llllll=(int)StrictMath.round(l1l1llll
);ll1lllll=(int)StrictMath.round(ll11llll);}@Override public boolean equals(Object l111llll){llllllll
llll1lll=(llllllll)l111llll;if(l1llllll!=llll1lll.l1llllll)return false;if(ll1lllll!=llll1lll.ll1lllll
)return false;return true;}@Override public int hashCode(){int l1ll1lll=l1llllll;l1ll1lll=31*l1ll1lll
+ll1lllll;return l1ll1lll;}}static llllllll ll1l1lll(l11l1lll lll11lll,int l1l11lll){return new llllllll
(lll11lll.ll111lll(l1l11lll+1),lll11lll.ll111lll(l1l11lll+1));}static llllllll l1111lll(llllllll lllll1ll
,double l1lll1ll,double ll1ll1ll){return new llllllll(lllll1ll.l1llllll+StrictMath.cos(l1lll1ll)*ll1ll1ll
,lllll1ll.ll1lllll+StrictMath.sin(l1lll1ll)*ll1ll1ll);}static double l11ll1ll(int lll1l1ll,int l1l1l1ll
){long l11lllll=(long)lll1l1ll*lll1l1ll+(long)l1l1l1ll*l1l1l1ll;return StrictMath.sqrt(l11lllll);}static
double ll11l1ll(llllllll p1,llllllll p2,llllllll p3){return l11ll1ll(p1.l1llllll-p2.l1llllll,p1.ll1lllll
-p2.ll1lllll)+l11ll1ll(p1.l1llllll-p3.l1llllll,p1.ll1lllll-p3.ll1lllll)+l11ll1ll(p2.l1llllll-p3.l1llllll
,p2.ll1lllll-p3.ll1lllll);}static class l111l1ll{Set<llllllll>llll11ll=new HashSet<llllllll>();}static
class l11l1lll{static final long l1ll11ll=4294967291L;static final long ll1l11ll=279470273L;private long
l11l11ll;l11l1lll(long l11l11ll){l11l11ll%=l1ll11ll;if(l11l11ll<0)l11l11ll+=l1ll11ll;if(l11l11ll==0)l11l11ll
=57;this.l11l11ll=l11l11ll;}int ll111lll(int lll111ll){return(int)l1l111ll(lll111ll);}long l1l111ll(long
lll111ll){long ll1111ll=l1ll11ll/lll111ll*lll111ll;do{l11l11ll=(l11l11ll*ll1l11ll)%l1ll11ll;}while(l11l11ll
>ll1111ll);return((l11l11ll-1)%lll111ll);}double l11111ll(){return l1l111ll(l1ll11ll-1)/(double)(l1ll11ll
-1);}}public static void main(String[]llllll1l)throws Exception{PrintWriter l1llll1l=new PrintWriter(
new BufferedOutputStream(System.out));l1llll1l.println(15);{l111l1ll lll1llll=new l111l1ll();l11l1lll
lll11lll=new l11l1lll(1882311623L);for(int ll1lll1l=0;ll1lll1l<3;++ll1lll1l)lll1llll.llll11ll.add(ll1l1lll
(lll11lll,1000000000));List<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int ll1lll1l
=0;ll1lll1l<l11lll1l.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l
);llllllll l11lllll=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l.set
(lll1ll1l,l11lllll);}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println
(l1l1ll1l.l1llllll+" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll
(3973778614L);lll1llll.llll11ll.add(new llllllll(0,0));lll1llll.llll11ll.add(new llllllll(0,1000000000
));lll1llll.llll11ll.add(new llllllll(1000000000,1000000000));lll1llll.llll11ll.add(new llllllll(1000000000
,0));List<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l<l11lll1l
.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l);llllllll l11lllll
=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll);
}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll+
" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll(3973778614L);
lll11lll.ll111lll(333);lll11lll.ll111lll(324);lll11lll.ll111lll(333);lll11lll.ll111lll(293);while(lll1llll
.llll11ll.size()<1000000){int l11lllll=lll11lll.ll111lll(12987012+1);lll1llll.llll11ll.add(new llllllll
(l11lllll*77,l11lllll*23));}List<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int
ll1lll1l=0;ll1lll1l<l11lll1l.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size
()-ll1lll1l);llllllll l11lllll=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l
.set(lll1ll1l,l11lllll);}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println
(l1l1ll1l.l1llllll+" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll
(190420022L);for(int ll1lll1l=0;ll1lll1l<1000000;++ll1lll1l)lll1llll.llll11ll.add(ll1l1lll(lll11lll,1000000000
));List<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l<l11lll1l
.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l);llllllll l11lllll
=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll);
}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll+
" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll(2659757759L);
for(int ll1lll1l=0;ll1lll1l<1000000;++ll1lll1l)lll1llll.llll11ll.add(ll1l1lll(lll11lll,1000000000));List
<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l<l11lll1l.size
();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l);llllllll l11lllll=l11lll1l
.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll);}l1llll1l
.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll+" "+l1l1ll1l
.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll(3704413326L);double ll11ll1l
=lll11lll.l11111ll()*2*StrictMath.PI;lll11lll.ll111lll(111111);for(int l111ll1l=0;l111ll1l<111111;++l111ll1l
){int llll1l1l=l111ll1l/334;int l1ll1l1l=l111ll1l%334;int ll1l1l1l=(int)(1000000000/2+StrictMath.cos(
ll11ll1l)*(llll1l1l-(334-1)/2.0)*1497005+StrictMath.cos(ll11ll1l+StrictMath.PI/2)*(l1ll1l1l-(334-1)/2.0
)*1497005);int l11l1l1l=(int)(1000000000/2+StrictMath.sin(ll11ll1l)*(llll1l1l-(334-1)/2.0)*1497005+StrictMath
.sin(ll11ll1l+StrictMath.PI/2)*(l1ll1l1l-(334-1)/2.0)*1497005);llllllll lll11l1l=new llllllll(ll1l1l1l
,l11l1l1l);double l1l11l1l=lll11lll.l11111ll()*2*StrictMath.PI;double ll111l1l=1497005/5;llllllll p1=
l1111lll(lll11l1l,l1l11l1l,ll111l1l/StrictMath.sqrt(3)-(l111ll1l==74691?5.0:0.0));llllllll p2=l1111lll
(lll11l1l,l1l11l1l+2*StrictMath.PI/3,ll111l1l/StrictMath.sqrt(3));llllllll p3=l1111lll(lll11l1l,l1l11l1l
+4*StrictMath.PI/3,ll111l1l/StrictMath.sqrt(3));lll1llll.llll11ll.add(p1);lll1llll.llll11ll.add(p2);lll1llll
.llll11ll.add(p3);lll1llll.llll11ll.add(l1111lll(p1,l1l11l1l+5*StrictMath.PI/24,ll111l1l-15));lll1llll
.llll11ll.add(l1111lll(p1,l1l11l1l-5*StrictMath.PI/24,ll111l1l-15));lll1llll.llll11ll.add(l1111lll(p2
,l1l11l1l+2*StrictMath.PI/3+5*StrictMath.PI/24,ll111l1l-15));lll1llll.llll11ll.add(l1111lll(p2,l1l11l1l
+2*StrictMath.PI/3-5*StrictMath.PI/24,ll111l1l-15));lll1llll.llll11ll.add(l1111lll(p3,l1l11l1l+4*StrictMath
.PI/3+5*StrictMath.PI/24,ll111l1l-15));lll1llll.llll11ll.add(l1111lll(p3,l1l11l1l+4*StrictMath.PI/3-5
*StrictMath.PI/24,ll111l1l-15));}List<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for
(int ll1lll1l=0;ll1lll1l<l11lll1l.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l
.size()-ll1lll1l);llllllll l11lllll=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l
));l11lll1l.set(lll1ll1l,l11lllll);}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)
l1llll1l.println(l1l1ll1l.l1llllll+" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll
lll11lll=new l11l1lll(2796900709L);double ll11ll1l=lll11lll.l11111ll()*2*StrictMath.PI;lll11lll.ll111lll
(1000000);double l1111l1l=StrictMath.cos(ll11ll1l);double lllll11l=StrictMath.sin(ll11ll1l);for(int l1lll11l
=0;l1lll11l<1000000;++l1lll11l){int ll1ll11l=l1lll11l/1000;int l11ll11l=l1lll11l%1000;int ll1l1l1l=(int
)(1000000000/2+l1111l1l*((ll1ll11l-(1000-1)/2.0)*499999+(l1lll11l==700587?10:0))-lllll11l*(l11ll11l-(
1000-1)/2.0)*499999);int l11l1l1l=(int)(1000000000/2+lllll11l*((ll1ll11l-(1000-1)/2.0)*499999+(l1lll11l
==700587?10:0))+l1111l1l*(l11ll11l-(1000-1)/2.0)*499999);lll1llll.llll11ll.add(new llllllll(ll1l1l1l,
l11l1l1l));}List<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l
<l11lll1l.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l);llllllll
l11lllll=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll
);}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll
+" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll(3922700588L
);double ll11ll1l=lll11lll.l11111ll()*2*StrictMath.PI;lll11lll.ll111lll(1000000);double l1111l1l=StrictMath
.cos(ll11ll1l);double lllll11l=StrictMath.sin(ll11ll1l);for(int l1lll11l=0;l1lll11l<1000000;++l1lll11l
){int ll1ll11l=l1lll11l/1000;int l11ll11l=l1lll11l%1000;int ll1l1l1l=(int)(1000000/2+l1111l1l*((ll1ll11l
-(1000-1)/2.0)*499+(l1lll11l==394865?10:0))-lllll11l*(l11ll11l-(1000-1)/2.0)*499);int l11l1l1l=(int)(
1000000/2+lllll11l*((ll1ll11l-(1000-1)/2.0)*499+(l1lll11l==394865?10:0))+l1111l1l*(l11ll11l-(1000-1)/
2.0)*499);lll1llll.llll11ll.add(new llllllll(ll1l1l1l,l11l1l1l));}List<llllllll>l11lll1l=new ArrayList
<llllllll>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l<l11lll1l.size();++ll1lll1l){int lll1ll1l=ll1lll1l
+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l);llllllll l11lllll=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l
,l11lll1l.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll);}l1llll1l.println(l11lll1l.size());for(llllllll
l1l1ll1l:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll+" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll
();l11l1lll lll11lll=new l11l1lll(2325394866L);lll1llll.llll11ll.add(new llllllll(0,0));lll1llll.llll11ll
.add(new llllllll(0,1000000000));lll1llll.llll11ll.add(new llllllll(1000000000,1000000000));lll1llll.
llll11ll.add(new llllllll(1000000000,0));double ll11ll1l=lll11lll.l11111ll()*2*StrictMath.PI;lll11lll
.ll111lll(999996);double l1111l1l=StrictMath.cos(ll11ll1l);double lllll11l=StrictMath.sin(ll11ll1l);for
(int l1lll11l=0;l1lll11l<999996;++l1lll11l){int ll1ll11l=l1lll11l/1000;int l11ll11l=l1lll11l%1000;int
ll1l1l1l=(int)(1000000/2+l1111l1l*((ll1ll11l-(1000-1)/2.0)*499+(l1lll11l==560140?10:0))-lllll11l*(l11ll11l
-(1000-1)/2.0)*499);int l11l1l1l=(int)(1000000/2+lllll11l*((ll1ll11l-(1000-1)/2.0)*499+(l1lll11l==560140
?10:0))+l1111l1l*(l11ll11l-(1000-1)/2.0)*499);lll1llll.llll11ll.add(new llllllll(ll1l1l1l,l11l1l1l));
}List<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l<l11lll1l
.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l);llllllll l11lllll
=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll);
}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll+
" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll(478558229L);
double ll11ll1l=lll11lll.l11111ll()*2*StrictMath.PI;lll11lll.ll111lll(1000000);lll11lll.ll111lll(1000000
);lll11lll.ll111lll(1000000);lll11lll.ll111lll(1000000);lll11lll.ll111lll(1000000);double l1111l1l=StrictMath
.cos(ll11ll1l);double lllll11l=StrictMath.sin(ll11ll1l);for(int l1lll11l=0;l1lll11l<1000000;++l1lll11l
){int ll1ll11l=l1lll11l/250000;int l11ll11l=l1lll11l%250000;int ll1l1l1l=(int)(1000000000/2+l1111l1l*
((ll1ll11l-(250000-1)/2.0)*1999+(l1lll11l==328093?10:0))-lllll11l*(l11ll11l-(250000-1)/2.0)*1999);int
l11l1l1l=(int)(1000000000/2+lllll11l*((ll1ll11l-(250000-1)/2.0)*1999+(l1lll11l==328093?10:0))+l1111l1l
*(l11ll11l-(250000-1)/2.0)*1999);lll1llll.llll11ll.add(new llllllll(ll1l1l1l,l11l1l1l));}List<llllllll
>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l<l11lll1l.size();++ll1lll1l
){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l);llllllll l11lllll=l11lll1l.get(ll1lll1l
);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll);}l1llll1l.println(l11lll1l
.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll+" "+l1l1ll1l.ll1lllll);}{l111l1ll
lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll(2767328094L);double ll11ll1l=lll11lll.l11111ll
()*2*StrictMath.PI;lll11lll.ll111lll(800000);double l1111l1l=StrictMath.cos(ll11ll1l);double lllll11l
=StrictMath.sin(ll11ll1l);for(int l1lll11l=0;l1lll11l<800000;++l1lll11l){int ll1ll11l=l1lll11l/895;int
l11ll11l=l1lll11l%895;int ll1l1l1l=(int)(1000000000/2+l1111l1l*((ll1ll11l-(895-1)/2.0)*558659+(l1lll11l
==346905?10:0))-lllll11l*(l11ll11l-(895-1)/2.0)*558659);int l11l1l1l=(int)(1000000000/2+lllll11l*((ll1ll11l
-(895-1)/2.0)*558659+(l1lll11l==346905?10:0))+l1111l1l*(l11ll11l-(895-1)/2.0)*558659);lll1llll.llll11ll
.add(new llllllll(ll1l1l1l,l11l1l1l));}List<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll
);for(int ll1lll1l=0;ll1lll1l<l11lll1l.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l
.size()-ll1lll1l);llllllll l11lllll=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l
));l11lll1l.set(lll1ll1l,l11lllll);}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)
l1llll1l.println(l1l1ll1l.l1llllll+" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll
lll11lll=new l11l1lll(3181946906L);double ll11ll1l=lll11lll.l11111ll()*2*StrictMath.PI;lll11lll.ll111lll
(900000);double l1111l1l=StrictMath.cos(ll11ll1l);double lllll11l=StrictMath.sin(ll11ll1l);for(int l1lll11l
=0;l1lll11l<900000;++l1lll11l){int ll1ll11l=l1lll11l/949;int l11ll11l=l1lll11l%949;int ll1l1l1l=(int)
(1000000000/2+l1111l1l*((ll1ll11l-(949-1)/2.0)*526870+(l1lll11l==155678?10:0))-lllll11l*(l11ll11l-(949
-1)/2.0)*526870);int l11l1l1l=(int)(1000000000/2+lllll11l*((ll1ll11l-(949-1)/2.0)*526870+(l1lll11l==155678
?10:0))+l1111l1l*(l11ll11l-(949-1)/2.0)*526870);lll1llll.llll11ll.add(new llllllll(ll1l1l1l,l11l1l1l));
}List<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l<l11lll1l
.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l);llllllll l11lllll
=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll);
}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll+
" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll(278255679L);
llllllll[]lll1l11l=new llllllll[10000000];while(lll1llll.llll11ll.size()<1000000){llllllll l1l1ll1l=ll1l1lll
(lll11lll,1000000000);long l1l1l11l=l1l1ll1l.l1llllll/1000000;if(l1l1l11l<0&&l1l1l11l%1000000!=0)--l1l1l11l
;long ll11l11l=l1l1ll1l.ll1lllll/1000000;if(ll11l11l<0&&ll11l11l%1000000!=0)--ll11l11l;long l111l11l=
l1l1l11l*2147483647+ll11l11l;List<llllllll>l11ll11l=new ArrayList<llllllll>();for(int llll111l=-1;llll111l
<=1;++llll111l)for(int l1llllll=-1;l1llllll<=1;++l1llllll){long l1ll111l=l111l11l+llll111l*2147483647
+l1llllll;llllllll ll1l111l=lll1l11l[(int)(l1ll111l%10000000+10000000)%10000000];while(ll1l111l!=null
){if(ll1l111l.lll1llll==l1ll111l)l11ll11l.add(ll1l111l);ll1l111l=ll1l111l.l11lllll;}}boolean l111llll
=true;l11l111l:for(int ll1lll1l=0;ll1lll1l<l11ll11l.size();++ll1lll1l){if(l1l1ll1l.equals(l11ll11l.get
(ll1lll1l))){l111llll=false;break;}for(int lll1ll1l=ll1lll1l+1;lll1ll1l<l11ll11l.size();++lll1ll1l)if
(ll11l1ll(l1l1ll1l,l11ll11l.get(ll1lll1l),l11ll11l.get(lll1ll1l))<10000000/5){l111llll=false;break l11l111l
;}}if(l111llll){lll1llll.llll11ll.add(l1l1ll1l);l1l1ll1l.l11lllll=lll1l11l[(int)(l111l11l%10000000+10000000
)%10000000];l1l1ll1l.lll1llll=l111l11l;lll1l11l[(int)(l111l11l%10000000+10000000)%10000000]=l1l1ll1l;
}}List<llllllll>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l<l11lll1l
.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l);llllllll l11lllll
=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll);
}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll+
" "+l1l1ll1l.ll1lllll);}{l111l1ll lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll(1515112020L);
llllllll[]lll1l11l=new llllllll[10000000];while(lll1llll.llll11ll.size()<1000000){llllllll l1l1ll1l=ll1l1lll
(lll11lll,10000000);long l1l1l11l=l1l1ll1l.l1llllll/10000;if(l1l1l11l<0&&l1l1l11l%10000!=0)--l1l1l11l
;long ll11l11l=l1l1ll1l.ll1lllll/10000;if(ll11l11l<0&&ll11l11l%10000!=0)--ll11l11l;long l111l11l=l1l1l11l
*2147483647+ll11l11l;List<llllllll>l11ll11l=new ArrayList<llllllll>();for(int llll111l=-1;llll111l<=1
;++llll111l)for(int l1llllll=-1;l1llllll<=1;++l1llllll){long l1ll111l=l111l11l+llll111l*2147483647+l1llllll
;llllllll ll1l111l=lll1l11l[(int)(l1ll111l%10000000+10000000)%10000000];while(ll1l111l!=null){if(ll1l111l
.lll1llll==l1ll111l)l11ll11l.add(ll1l111l);ll1l111l=ll1l111l.l11lllll;}}boolean l111llll=true;l11l111l
:for(int ll1lll1l=0;ll1lll1l<l11ll11l.size();++ll1lll1l){if(l1l1ll1l.equals(l11ll11l.get(ll1lll1l))){
l111llll=false;break;}for(int lll1ll1l=ll1lll1l+1;lll1ll1l<l11ll11l.size();++lll1ll1l)if(ll11l1ll(l1l1ll1l
,l11ll11l.get(ll1lll1l),l11ll11l.get(lll1ll1l))<100000/5){l111llll=false;break l11l111l;}}if(l111llll
){lll1llll.llll11ll.add(l1l1ll1l);l1l1ll1l.l11lllll=lll1l11l[(int)(l111l11l%10000000+10000000)%10000000
];l1l1ll1l.lll1llll=l111l11l;lll1l11l[(int)(l111l11l%10000000+10000000)%10000000]=l1l1ll1l;}}List<llllllll
>l11lll1l=new ArrayList<llllllll>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l<l11lll1l.size();++ll1lll1l
){int lll1ll1l=ll1lll1l+lll11lll.ll111lll(l11lll1l.size()-ll1lll1l);llllllll l11lllll=l11lll1l.get(ll1lll1l
);l11lll1l.set(ll1lll1l,l11lll1l.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll);}l1llll1l.println(l11lll1l
.size());for(llllllll l1l1ll1l:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll+" "+l1l1ll1l.ll1lllll);}{l111l1ll
lll1llll=new l111l1ll();l11l1lll lll11lll=new l11l1lll(3674906121L);llllllll[]lll1l11l=new llllllll[10000000
];while(lll1llll.llll11ll.size()<999900){llllllll l1l1ll1l=ll1l1lll(lll11lll,1000000000);long l1l1l11l
=l1l1ll1l.l1llllll/1000050;if(l1l1l11l<0&&l1l1l11l%1000050!=0)--l1l1l11l;long ll11l11l=l1l1ll1l.ll1lllll
/1000050;if(ll11l11l<0&&ll11l11l%1000050!=0)--ll11l11l;long l111l11l=l1l1l11l*2147483647+ll11l11l;List
<llllllll>l11ll11l=new ArrayList<llllllll>();for(int llll111l=-1;llll111l<=1;++llll111l)for(int l1llllll
=-1;l1llllll<=1;++l1llllll){long l1ll111l=l111l11l+llll111l*2147483647+l1llllll;llllllll ll1l111l=lll1l11l
[(int)(l1ll111l%10000000+10000000)%10000000];while(ll1l111l!=null){if(ll1l111l.lll1llll==l1ll111l)l11ll11l
.add(ll1l111l);ll1l111l=ll1l111l.l11lllll;}}boolean l111llll=true;l11l111l:for(int ll1lll1l=0;ll1lll1l
<l11ll11l.size();++ll1lll1l){if(l1l1ll1l.equals(l11ll11l.get(ll1lll1l))){l111llll=false;break;}for(int
lll1ll1l=ll1lll1l+1;lll1ll1l<l11ll11l.size();++lll1ll1l)if(ll11l1ll(l1l1ll1l,l11ll11l.get(ll1lll1l),l11ll11l
.get(lll1ll1l))<10000500/5){l111llll=false;break l11l111l;}}if(l111llll){lll1llll.llll11ll.add(l1l1ll1l
);l1l1ll1l.l11lllll=lll1l11l[(int)(l111l11l%10000000+10000000)%10000000];l1l1ll1l.lll1llll=l111l11l;lll1l11l
[(int)(l111l11l%10000000+10000000)%10000000]=l1l1ll1l;}}List<llllllll>l11lll1l=new ArrayList<llllllll
>(lll1llll.llll11ll);for(int ll1lll1l=0;ll1lll1l<l11lll1l.size();++ll1lll1l){int lll1ll1l=ll1lll1l+lll11lll
.ll111lll(l11lll1l.size()-ll1lll1l);llllllll l11lllll=l11lll1l.get(ll1lll1l);l11lll1l.set(ll1lll1l,l11lll1l
.get(lll1ll1l));l11lll1l.set(lll1ll1l,l11lllll);}l1llll1l.println(l11lll1l.size());for(llllllll l1l1ll1l
:l11lll1l)l1llll1l.println(l1l1ll1l.l1llllll+" "+l1l1ll1l.ll1lllll);}l1llll1l.close();}}

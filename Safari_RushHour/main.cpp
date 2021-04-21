#include <iostream>
#include <string.h>
#include <cstdio>
#include "SAS.h"

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    if(argc!=1 && argc!=3)
    {
        cout<<"Wrong number of arguments!"<<endl;
        cout<<"command: ./safari [-t] [n]"<<endl;
        cout<<"n = number of seconds before TIMEOUT"<<endl;
        return 0;
    }
    if(argc==3 && strcmp("-t", argv[1])!=0)
    {
        cout<<"Invalid arguments!"<<endl;
        cout<<"command: ./safari [-t] [n]"<<endl;
        cout<<"n = number of seconds before TIMEOUT"<<endl;
        return 0;
    }
    string input;
    SAS sas;
    int tc = 0;
    int time_limit = atoi(argv[2]);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    while(cin>>input)
    {
        if(input[0]=='P')   cin>>input;
        cout<<input<<endl;
        if(!sas.init(input))
        {
            cout<<"Invalid Input!"<<endl;
            break;
        }
        tc++;
        sas.IDAstar(time_limit);
    }
    chrono::steady_clock::time_point endt = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = endt - start;
    cout<<"TOTAL TIME: "<<elapsed_seconds.count()<<endl;

    return 0;
}

/*
P J1
.......
.rrrf..
hh..fq.!
o.xx.q.!
o.xx.q.
ob..ee.
.bppp..

P J2
.......
....qqq
pppor..!
...orcc!
.eeor..
...xx..
...xx..

P J3
..ii...
.ffaa..
..kk...!
.eedd..!
cc..bb.
.hxxj..
.hxxj..

P J4
o....d.
o..aad.
o...hbb!
ii..h..!
.xx....
.xxc...
...cqqq

P J5
......o
xx....o
xx....o!
.dee...!
.dhpc..
..hpc..
.jjpqqq

P J6
xx.h...
xx.h...
..qqqaa!
jjrrr..!
..ppp..
..f....
..f....

P J7
....h..
..iiha.
.bbxxa.!
..dxxff!
..decc.
...e...
.......

P J8
.rrrpff
....p..
d...p..!
dxxqqq.!
.xxe..c
...ebbc
aa.ooo.

P J9
.......
...pr..
...pr..!
..oprq.!
..oxxq.
.boxxqc
.b.ee.c

P J10
.......
..ooor.
..xx.r.!
..xx.r.!
...peed
...p..d
...pqqq

P B1
...r.ii
.aar...
.h.r..c!
.hjjffc!
...kkee
..xx.vv
..xx.vv

P B2
.......
uu.pppo
uu.qxxo!
siiqxxo!
shbqrrr
shb.kk.
.......

P B3
...r...
...ruu.
c..ruu.!
c..a...!
xx.a.gg
xxeeff.
.hhjj..

P B4
.cqqqp.
.c.j.p.
vv.j.p.!
vveexx.!
r.h.xx.
r.h.b..
rooob..

P B5
.......
...f...
bb.f.jj!
.xxuuh.!
.xxuuh.
ii.a.gg
...a...

P B6
.......
.......
.peaao.!
.peffo.!
.prrro.
.xxqqq.
.xx....

P B7
.uu.jj.
iuuh..a
i..h..a!
.bb.ff.!
xx.e..c
xx.evvc
.dd.vv.

P B8
xx.ppp.
xx.uu..
.aauucc!
...qr..!
...qr..
...qr..
..hhjj.

P B9
...f...
..afp..
.ha.pe.!
.hxxpe.!
jjxxdcc
..i.d..
..ibb..

P B10
.......
...aff.
..ra.eq!
..rcceq!
..rgvvq
xx.gvv.
xx.....

P I11
vvc....
vvc....
qqquui.!
...uui.!
xxdooo.
xxd....
ppp....

P I12
...uu..
...uui.
..xx.i.!
vvxxooo!
vv.q.bb
.ccqe..
...qe..

P I13
ppp.ee.
.xx.r.c
.xx.r.c!
.qqqr.a!
...jvva
h..jvv.
h.ffooo

P I14
hh.dd..
.....i.
qooo.i.!
qxxp...!
qxxp.b.
rrrp.b.
.......

P I15
jjhh...
.uu...g
auu.r.g!
aiiprcq!
f..prcq
fxxpvvq
.xx.vv.

P I16
.hhjj..
..ff...
.aavv..!
iiovvq.!
xxoeeq.
xxodcq.
.bbdc..

P I17
.......
oooa...
pvva...!
pvvcc..!
peeqqq.
xxrrrkj
xx.ffkj

P I18
j..d.uu
jhhd.uu
.xx....!
.xxpppc!
...rrrc
vv.f..a
vv.f..a

P I19
i......
iooo...
pppee..!
.......!
.aarrr.
hxxcvvf
hxxcvvf

P I20
.....uu
.bdd.uu
.b.p...!
ooop..r!
...pxxr
...exxr
cc.eqqq

P A21
..uu...
..uu.cc
bihhvvq!
biajvvq!
ddajffq
..xx.ee
..xx...

P A22
.......
.pppc..
.euuc..!
qeuuff.!
qaahjjg
qxxhvvg
.xx.vv.

P A23
.cvveep
.cvv.qp
....rqp!
...srq.!
..osr..
.ios.xx
.iobbxx

P A24
....aii
roooa.c
rxxqddc!
rxxquu.!
pppquu.
vv..hb.
vv..hb.

P A25
.kf..a.
.kfcca.
uuxx.vv!
uuxx.vv!
.jgeeh.
.jg..h.
.......

P A26
xx...uu
xxooouu
.q..bii!
.q..b..!
.qee.ff
vvc.a..
vvc.a..

P A27
..orrr.
.ioaavv
.iouuvv!
.xxuuqc!
.xxddqc
..pppq.
.......

P A28
xxrrr..
xxuusss
p.uuvv.!
pdo.vv.!
pdoiq..
eeoiqc.
..bbqc.

P A29
uuddp..
uuiip..
bbxxp..!
aaxxee.!
rrrcvv.
...cvvj
kk....j

P A30
.......
..ddh..
xxi.hvv!
xxiaavv!
.oppps.
.oqqqs.
.orrrs.

P E31
ppp.c..
e.q.c..
e.q..ii!
vvq....!
vv.rrro
xxuu..o
xxuubbo
*/

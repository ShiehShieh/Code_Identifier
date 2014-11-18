type arr=record
     rsm:longint;
     lsm:longint;
     sm:longint;
     max:longint;
     end;
var n,m,h,t,p,x,s,i:longint;
sig:boolean;
a:array[0..2000010] of longint;
c:array[0..2000000] of arr;
ck:arr;
procedure fd(h1,t1,h,t,k:longint;var ck:arr);
var mid,x1,x2:longint;
ckk1,ckk2:arr;
begin
    if (h1=h) and (t1=t) then
    begin
        ck:=c[k];
        exit;
    end;
    mid:=(h+t) div 2;
    if mid>=t1 then
    begin
       fd(h1,t1,h,mid,k*2,ck);
       exit;
    end
    else if mid<h1 then
    begin
        fd(h1,t1,mid+1,t,k*2+1,ck);
        exit;
    end
    else
    begin
        fd(h1,mid,h,mid,k*2,ckk1);
        fd(mid+1,t1,mid+1,t,k*2+1,ckk2);
        ck.lsm:=ckk1.lsm;
        if ck.lsm<ckk1.sm+ckk2.lsm then
        ck.lsm:=ckk1.sm+ckk2.lsm;
        ck.rsm:=ckk2.rsm;
        if ck.rsm<ckk1.rsm+ckk2.sm then
        ck.rsm:=ckk1.rsm+ckk2.sm;
        ck.sm:=ckk1.sm+ckk2.sm;
        ck.max:=ckk1.max;
        if ck.max<ckk2.max then
        ck.max:=ckk2.max;
        if ck.max<ckk1.rsm+ckk2.lsm then
        ck.max:=ckk1.rsm+ckk2.lsm;
        exit;
    end;
end;
procedure cg(p,v,h,t,k:longint);
var mid:longint;
begin
    if (h=p) and (t=p) then
    begin
        c[k].max:=v;
        c[k].rsm:=v;
        c[k].lsm:=v;
        c[k].sm:=v;
        exit;
    end;
    mid:=(t+h) div 2;
    if p>mid then
    begin
        cg(p,v,mid+1,t,k*2+1);
    end else
    begin
        cg(p,v,h,mid,k*2);
    end;
    c[k].lsm:=c[k*2].lsm;
    if c[k].lsm<c[k*2].sm+c[k*2+1].lsm then
    c[k].lsm:=c[k*2].sm+c[k*2+1].lsm;
    c[k].rsm:=c[k*2+1].rsm;
    if c[k].rsm<c[k*2].rsm+c[k*2+1].sm then
    c[k].rsm:=c[k*2].rsm+c[k*2+1].sm;
    c[k].sm:=c[k*2].sm+c[k*2+1].sm;
    c[k].max:=c[k*2].max;
    if c[k].max<c[k*2+1].max then
    c[k].max:=c[k*2+1].max;
    if c[k].max<c[k*2].rsm+c[k*2+1].lsm then
    c[k].max:=c[k*2].rsm+c[k*2+1].lsm;
end;
procedure bdtr(h,t,k:longint);
var mid:longint;
begin
    if h=t then
    begin
        c[k].max:=a[h];
        c[k].rsm:=a[h];
        c[k].lsm:=a[h];
        c[k].sm:=a[h];
        exit;
    end;
    if h<t then
    begin
        mid:=(h+t) div 2;
        bdtr(h,mid,k*2);
        bdtr(mid+1,t,k*2+1);
    c[k].lsm:=c[k*2].lsm;
    if c[k].lsm<c[k*2].sm+c[k*2+1].lsm then
    c[k].lsm:=c[k*2].sm+c[k*2+1].lsm;
    c[k].rsm:=c[k*2+1].rsm;
    if c[k].rsm<c[k*2].rsm+c[k*2+1].sm then
    c[k].rsm:=c[k*2].rsm+c[k*2+1].sm;
    c[k].sm:=c[k*2].sm+c[k*2+1].sm;
    c[k].max:=c[k*2].max;
    if c[k].max<c[k*2+1].max then
    c[k].max:=c[k*2+1].max;
    if c[k].max<c[k*2].rsm+c[k*2+1].lsm then
    c[k].max:=c[k*2].rsm+c[k*2+1].lsm;
    exit;
    end;
end;
begin
    readln(n,m);
    for i:=1 to n do
    read(a[i]);
    bdtr(1,n,1);
    for i:=1 to m do
    begin
        read(x);
        if x=1 then
        begin
            read(h,t);
            if h>t then
            begin
                x:=t;
                t:=h;
                h:=x;
            end;
            fd(h,t,1,n,1,ck);
            if sig then write(' ') else sig:=true;
            write(ck.max);
        end else
        begin
            read(p,s);
            cg(p,s,1,n,1);
        end;
    end;
    writeln;
end.


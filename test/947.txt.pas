program profit;

const
 name='profit';

type
 toetype=^etype;
 etype=record
  t,c:longint;
  p,next:toetype;
 end;

var
 e:array[-55000..5500] of toetype;
 h:array[-55000..5500] of longint;
 vh:array[0..70000] of longint;
 n,m,i,rd,rd1,rd2:longint;
 per:longint=0;

procedure addedge(const sn,tn,cn:longint);
var
 newe:toetype;
begin
 new(newe);
 with newe^ do begin
  t:=tn;
  c:=cn;
  next:=e[sn];
  new(p);
  with p^ do begin
   t:=sn;
   c:=0;
   next:=e[tn];
   p:=newe;
  end;
  e[tn]:=p;
 end;
 e[sn]:=newe;
end;

function aug(const u,t:longint):longint;
var
 minh,l,d:longint;
 ie:toetype;
begin
 if u=0 then begin aug:=t;exit;end;
 l:=t;
 minh:=n+m+1;
 ie:=e[u];
 while ie<>nil do begin
  if ie^.c>0 then begin
   if h[ie^.t]+1=h[u] then begin
    if l<ie^.c then d:=l else d:=ie^.c;
    d:=aug(ie^.t,d);
    dec(ie^.c,d);
    inc(ie^.p^.c,d);
    dec(l,d);
    if h[n+1]>=n+m+2 then begin aug:=t-l;exit;end;
    if l=0 then break;
   end;
   if h[ie^.t]<minh then minh:=h[ie^.t];
  end;
  ie:=ie^.next;
 end;
 if l=t then begin
  dec(vh[h[u]]);
  if vh[h[u]]=0 then h[n+1]:=n+m+2;
  h[u]:=minh+1;
  inc(vh[h[u]]);
 end;
 aug:=t-l;
end;

begin
 readln(n,m);
 fillchar(e,sizeof(e),0);
 for i:=1 to n do begin
  read(rd);
  addedge(n+1,i,rd);
 end;
 readln;
 for i:=1 to m do begin
  readln(rd1,rd2,rd);
  inc(per,rd);
  addedge(rd1,-i,maxlongint);
  addedge(rd2,-i,maxlongint);
  addedge(-i,0,rd);
 end;
 fillchar(h,sizeof(h),0);
 fillchar(vh,sizeof(vh),0);
 vh[0]:=n+m+2;
 while h[n+1]<n+m+2 do
  dec(per,aug(n+1,maxlongint));
 writeln(per);
end.


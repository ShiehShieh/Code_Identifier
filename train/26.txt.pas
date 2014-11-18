program p1486;
const Maxv=200000;
type Node=record
            x,y:longint;
          end;
     Link=array[0..Maxv] of longint;
var n,m              : longint;
    Bl,Wh            : array[1..Maxv] of node;
    p                : Link;
    Ans_Min,Ans_Max  : int64;
    a,b,w,v          : array[1..Maxv*5] of longint;
    Tot              : longint;
    Tl,Tr            : array[1..Maxv] of longint;

procedure Init;
var i:longint;
begin
  Readln(n,m);
  for i:=1 to n do Readln(Bl[i].x,Bl[i].y);
  for i:=1 to n do Readln(Wh[i].x,Wh[i].y);
end;

Procedure Exchange;
var i:longint;
    T:node;
begin
  for i:=1 to n do
  begin
    T:=Bl[i]; Bl[i]:=Wh[i]; Wh[i]:=T;
  end;
end;

procedure insert_rec(x,y,p,q,k:int64);
begin
  inc(Tot);
  a[Tot]:=(y-x+k) div 2;
  b[Tot]:=(q-p+k) div 2;
  w[Tot]:=(x+y+k) div 2;
  v[Tot]:=-1;
  inc(Tot);
  a[Tot]:=(y-x+k) div 2;
  b[Tot]:=(q-p+k) div 2;
  w[Tot]:=(p+q+k) div 2;
  v[Tot]:=1;
end;

procedure insert_v(x,y,k:int64);
begin
  inc(Tot);
  a[Tot]:=(y-x+k) div 2;
  b[Tot]:=0;
  w[Tot]:=(x+y+k) div 2;
  v[Tot]:=0;
end;

procedure quicksort(l,r:longint);
var i,j:longint;
    mid,x,y,k:longint;
begin
  i:=l; j:=r; mid:=random(r-l+1)+l; x:=w[mid]; y:=v[mid];
  repeat
    while (w[i]<x) or ((w[i]=x) and (v[i]<y)) do inc(i);
    while (w[j]>x) or ((w[j]=x) and (v[j]>y)) do dec(j);
    if i<=j then begin
      k:=w[i]; w[i]:=w[j]; w[j]:=k;
      k:=a[i]; a[i]:=a[j]; a[j]:=k;
      k:=b[i]; b[i]:=b[j]; b[j]:=k;
      k:=v[i]; v[i]:=v[j]; v[j]:=k;
      inc(i);  dec(j);
    end;
  until i>j;
  if l<j then quicksort(l,j);
  if i<r then quicksort(i,r);
end;

function find_Min:longint;
var i,Min:longint;
begin
  Min:=0;
  for i:=1 to Tot do
    if a[i]<Min then Min:=a[i];
  if Min>0 then Exit(0) else Exit(Abs(Min)+1);
end;

function find_Max:longint;
var i,Max:longint;
begin
  Max:=0;
  for i:=1 to Tot do
  begin
    if a[i]>Max then Max:=A[i];
    if b[i]>Max then Max:=B[i];
  end;
  Exit(Max);
end;

procedure Work;
var i,Tp  : int64;
begin
  i:=0; Tp:=0;
  while i<=n do
  begin
    while P[i]>0 do begin
      dec(P[i]);
      inc(Tp);
      Ans_Min:=Ans_Min+(n-Tp)*i-i*(i-1) div 2;
      Ans_Max:=Ans_Max+(Tp-1)*i-i*(i-1) div 2;
    end;
    inc(i);
  end;
end;

procedure Add_L(x,k:longint);
begin
  while x<=maxv do
  begin
    inc(Tl[x],k);
    inc(x,x and -x);
  end;
end;

procedure Add_R(x,k:longint);
begin
  while x<=maxv do
  begin
    inc(TR[x],k);
    inc(x,x and -x);
  end;
end;

function Sum_l(x:longint):longint;
var tot:longint;
begin
  tot:=0;
  while x>0 do
  begin
    inc(tot,Tl[x]);
    dec(x,x and -x);
  end;
  Exit(Tot);
end;

function Sum_r(x:longint):longint;
var tot:longint;
begin
  tot:=0;
  while x>0 do
  begin
    inc(Tot,Tr[x]);
    dec(x,x and -x);
  end;
  exit(Tot);
end;

function Search(x:longint):longint;
var ans:longint;
begin
  Ans:=Sum_l(x)-Sum_r(x-1);
  exit(Ans);
end;

Procedure Solve;
var i,Num,Min,Max,total:longint;
begin
  Tot:=0; total:=0;
  Fillchar(P,sizeof(P),0);
  Fillchar(Tl,sizeof(Tl),0);
  Fillchar(Tr,sizeof(Tr),0);
  for i:=1 to n do
  begin
    if not odd(Bl[i].x+Bl[i].y-m) then
      insert_Rec(Bl[i].x,Bl[i].y-m,Bl[i].x,Bl[i].y+m,0)
    else
      insert_Rec(Bl[i].x,Bl[i].y-m+1,Bl[i].x,Bl[i].y+m-1,0);
    if not odd(Wh[i].x+Wh[i].y) then begin
      insert_v(Wh[i].x,Wh[i].y,0);
      inc(total);
    end;
  end;

  Min:=find_Min;
  Max:=find_Max+Min;
  Quicksort(1,Tot);

  for i:=1 to Tot do
    if v[i]=0 then
    begin
      Num:=Search(a[i]+Min);
      inc(P[Num]);
      dec(total);
      if total=0 then break;
    end
    else begin
      Add_l(a[i]+Min,v[i]*-1);
      Add_R(b[i]+Min,v[i]*-1);
    end;

  Tot:=0; total:=0;
  Fillchar(Tl,sizeof(Tl),0);
  Fillchar(Tr,sizeof(Tr),0);
  for i:=1 to n do
  begin
    if odd(Bl[i].x+Bl[i].y-m) then
      insert_Rec(Bl[i].x,Bl[i].y-m,Bl[i].x,Bl[i].y+m,1)
    else
      insert_Rec(Bl[i].x,Bl[i].y-m+1,Bl[i].x,Bl[i].y+m-1,1);
    if odd(Wh[i].x+Wh[i].y) then begin
      insert_v(Wh[i].x,Wh[i].y,1);
      inc(total);
    end;
  end;
  Min:=find_Min;
  Max:=find_Max+Min;
  Quicksort(1,Tot);

  for i:=1 to Tot do
    if v[i]=0 then
    begin
      Num:=Search(a[i]+Min);
      inc(P[Num]);
      dec(total);
      if total=0 then break;
    end
    else begin
      Add_l(a[i]+Min,v[i]*-1);
      Add_r(b[i]+Min,v[i]*-1);
    end;
  Work;
end;

procedure Main;
begin
  Ans_Min:=0; Ans_Max:=0;
  Solve;
  Exchange;
  Solve;
end;

procedure print;
begin
  Writeln(Ans_Min,' ',Ans_Max);
end;

begin
  Init;
  Main;
  Print;
end.

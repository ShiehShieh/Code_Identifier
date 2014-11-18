Type go=record l,r,d,u:longint; end;
Var i,j,k,n,r:longint;
    a:array[1..200] of go;
    q:array[1..10000] of go;
    use:array[1..100] of boolean;
    ans:int64;
Function mid(a,b,c:longint):boolean;
 begin
  if (a<b) and (b<c) then exit(true) else exit(false);
 end;
Function min(a,b:longint):longint;
 begin
  if a<b then min:=a else min:=b;
 end;
Function max(a,b:longint):longint;
 begin
  if a>b then max:=a else max:=b;
 end;
Procedure split(p,t:longint);
 begin
  if q[p].r<=a[t].l then exit;
  if q[p].l>=a[t].r then exit;
  if q[p].u<=a[t].d then exit;
  if q[p].d>=a[t].u then exit;
  use[p]:=true;
  if mid(q[p].l,a[t].l,q[p].r) then
   begin inc(r);q[r].l:=q[p].l;q[r].r:=a[t].l;q[r].d:=q[p].d;q[r].u:=q[p].u; end;
  if mid(q[p].l,a[t].r,q[p].r) then
   begin inc(r);q[r].l:=a[t].r;q[r].r:=q[p].r;q[r].d:=q[p].d;q[r].u:=q[p].u; end;
  if mid(q[p].d,a[t].u,q[p].u) then
   begin inc(r);q[r].l:=max(q[p].l,a[t].l);q[r].r:=min(q[p].r,a[t].r);q[r].d:=a[t].u;q[r].u:=q[p].u; end;
  if mid(q[p].d,a[t].d,q[p].u) then
   begin inc(r);q[r].l:=max(q[p].l,a[t].l);q[r].r:=min(q[p].r,a[t].r);q[r].d:=q[p].d;q[r].u:=a[t].d; end;
 end;
Begin

 read(n);
 for i:=1 to n do read(a[i].l,a[i].d,a[i].r,a[i].u);
 for i:=1 to n do
  if (a[i].u>a[i].d) and (a[i].r>a[i].l) then begin
   fillchar(use,sizeof(use),false);
   q[1]:=a[i];
   r:=1;
   for j:=i+1 to n do
   if (a[j].u>a[j].d) and (a[j].r>a[j].l) then
    for k:=1 to r do
     if not use[k] then
      begin
       split(k,j);
      end;
   for j:=1 to r do
    if not use[j] then
    if (q[j].u>q[j].d) and (q[j].r>q[j].l) then
    ans:=ans+int64(q[j].u-q[j].d)*int64(q[j].r-q[j].l);
  end;
 writeln(ans);

End.


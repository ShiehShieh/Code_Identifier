Program p1121;
const
 a:array[1..8] of integer=(-2,-1,1,2,-2,-1,1,2);
 b:array[1..8] of integer=(-1,-2,2,1,1,2,-2,-1);
 var v:array[-1..20,-1..20] of boolean;
    i,n,m,p,q,j:longint;
 Procedure search(x,y:longint);
  begin
   if (x>n)or(y>m) then exit;
    if (x=n)and(y=m)
      then  inc(j)
      else begin
        if (x<n)and(v[x+1,y]=false) then search(x+1,y);
        if (y<m)and(v[x,y+1]=false) then search(x,y+1);
          end;
  end;
begin
 readln(n,m,p,q);
 for i:=1 to 8 do
  if (p+a[i]<=n)and(p+a[i]>=0)and(q+b[i]<=m)and(q+b[i]>=0) then
   v[p+a[i],q+b[i]]:=true;
  v[p,q]:=true;
 search(0,0);
 writeln(j);
end.                             

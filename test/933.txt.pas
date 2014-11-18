var
 s,du:string;
 p,kk,i,j,k,n,w,t,max,m,lj,h:longint;
 zc:array[0..201]of char;
 a:array[1..6]of string;
 f:array[0..201,0..41]of longint;
 js:array[1..200]of longint;
function can(s1:string):boolean;
var
 h1,ii,jj:longint;
 u:boolean;
begin
 can:=true;
 for ii:=t downto 1 do
  begin
   if length(a[ii])>length(s1) then
    h1:=length(s1) else
     h1:=length(a[ii]);
   u:=true;
   for jj:=1 to h1 do
     if a[ii][jj]<>s1[jj] then
      begin
       u:=false;
       break;
      end;
   if u=true then
    begin
     if h1=length(s1) then
       a[ii]:=s1;
     can:=false;
    end;
   if can=false then
    break;
  end;
end;
procedure ycl;
var
 x,y,z:longint;
 jie:boolean;
begin
 for x:=1 to n do
  for y:=1 to t do
   begin
    jie:=true;
    for z:=1 to length(a[y]) do
     if a[y][z]<>zc[x+z-1] then
      begin
       jie:=false;
       break;
      end;
    if jie=true then
     begin
      js[x]:=x+length(a[y])-1;
      break;
     end;
   end;
end;
begin
 fillchar(zc,sizeof(zc),0);
 fillchar(a,sizeof(a),0);
 fillchar(f,sizeof(f),0);
 readln(p,kk);
 n:=0;
 for i:=1 to p do
  begin
   readln(s);
   h:=length(s);
   for j:=1 to h do
    begin
     inc(n);
     zc[n]:=s[j];
    end;
  end;
 readln(w);
 t:=0;
 for i:=1 to w do
  begin
   readln(du);
   if can(du) then
    begin
     inc(t);
     a[t]:=du;
    end;
  end;
 ycl;
 for k:=1 to kk do
  for i:=k to n-kk+k do
   begin
    max:=0;
    lj:=0;
    for j:=i-1 downto k-1 do
     begin
      if (js[j+1]<=i)and(js[j+1]>0) then
       inc(lj);
      m:=f[j,k-1]+lj;
      if m>max then
       max:=m;
     end;
    f[i,k]:=max;
  end;
 writeln(f[n,kk]);
end.










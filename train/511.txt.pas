program zuiyongganderobit;
var fat:array[1..1000] of integer;
wa,pa:array[1..1000,1..1000] of integer;
wi,pi:array[1..1000] of integer;
biaoji:array[1..1000] of integer;
s:array[1..1000] of integer;
f:array[0..1000] of longint;
total,i,j,k,l,n,m,wmax:integer;

function getfat(k:integer):integer;
var i,j:integer;
begin
if (fat[k]=0) or (fat[k]=k) then getfat:=k
  else
  begin
   fat[k]:=getfat(fat[k]);
   getfat:=fat[k];
  end;
end;

procedure init(a,b:integer);
var i,j:integer;
begin
i:=getfat(a); j:=getfat(b);
fat[i]:=j;
end;

begin
readln(n,wmax,k);
for i:=1 to n do
fat[i]:=i;
for i:=1 to n do
 readln(pi[i],wi[i]);
for i:=1 to k do
 begin
 readln(j,m);
 init(j,m);
end;
total:=0;
fillchar(s,sizeof(s),0);
for i:=1 to n do
  begin
  fat[i]:=getfat(i);
  if biaoji[fat[i]]=0 then
                    begin
                    inc(total);
                    biaoji[fat[i]]:=total;
                    inc(s[total]);
                    wa[total,s[total]]:=wi[i];
                    pa[total,s[total]]:=pi[i];
                    end
    else begin
         m:=biaoji[fat[i]];
         inc(s[m]);
         wa[m,s[m]]:=wi[i] ;
         pa[m,s[m]]:=pi[i];
         end;
  end;
for j:=1 to total do
  for k:=wmax downto 0 do
    for i:=1 to s[j] do
    if k-wa[j,i]>=0 then
    if f[k]<f[k-wa[j,i]]+pa[j,i]
      then f[k]:=f[k-wa[j,i]]+pa[j,i];
writeln(f[wmax]);
end.




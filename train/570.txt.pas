program drawing(input,output); 
var 
a:array[1..1000,1..1000] of char; 
c:array[1..100,1..100] of longint; 
n,m,i,j,k,x,y,maxc,maxk:longint; 
begin 
read(n,m); 
for i:=1 to n do 
for j:=1 to m do 
read(c[n-i+1,j]); 
fillchar(a,sizeof(a),'.'); 
for k:=1 to 100 do 
for i:=n downto 1 do 
for j:=1 to m do 
if c[i,j]>=k then 
begin 
x:=(k-1)*3+(i-1)*2+1; 
y:=(j-1)*4+1+(i-1)*2; 
a[x,y]:='+'; 
a[x+1,y]:='|'; 
a[x+2,y]:='|'; 
a[x+3,y]:='+'; 
a[x,y+1]:='-'; 
a[x+1,y+1]:=' '; 
a[x+2,y+1]:=' '; 
a[x+3,y+1]:='-'; 
a[x+4,y+1]:='/'; 
a[x,y+2]:='-'; 
a[x+1,y+2]:=' '; 
a[x+2,y+2]:=' '; 
a[x+3,y+2]:='-'; 
a[x+4,y+2]:=' '; 
a[x+5,y+2]:='+'; 
a[x,y+3]:='-'; 
a[x+1,y+3]:=' '; 
a[x+2,y+3]:=' '; 
a[x+3,y+3]:='-'; 
a[x+4,y+3]:=' '; 
a[x+5,y+3]:='-'; 
a[x,y+4]:='+'; 
a[x+1,y+4]:='|'; 
a[x+2,y+4]:='|'; 
a[x+3,y+4]:='+'; 
a[x+4,y+4]:=' '; 
a[x+5,y+4]:='-'; 
a[x+1,y+5]:='/'; 
a[x+2,y+5]:=' '; 
a[x+3,y+5]:=' '; 
a[x+4,y+5]:='/'; 
a[x+5,y+5]:='-'; 
a[x+2,y+6]:='+'; 
a[x+3,y+6]:='|'; 
a[x+4,y+6]:='|'; 
a[x+5,y+6]:='+'; 
if x+5>maxc then maxc:=x+5; 
if y+6>maxk then maxk:=y+6; 
end; 
for i:=maxc downto 1 do 
begin 
for j:=1 to maxk do 
write(a[i,j]); 
writeln; 
end; 
end. 

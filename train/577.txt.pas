type arr=array[0..31,0..31] of longint;
var
  i,j,k,n,m,l,c:longint;
  d1,d2:array[0..1024] of longint;
  v:array[0..1024,0..1024] of longint;
  p:array[1..11]of integer=(1,2,4,8,16,32,64,128,256,512,1024);
  x,y:arr;
procedure cheng(var a,b:arr);
var i,j,k:longint; e:arr;
begin
  fillchar(e,sizeof(e),0);
  for i:=0 to c do
   for j:=0 to c do
    for k:=0 to c do
      e[i,j]:= e[i,j]+(a[i,k]mod l)*(b[k,j]mod l)mod l;
  a:=e;
end;
procedure dfs(i,k,o:longint);
begin
  if i>m then exit;
  if i=m then begin inc(v[o,0]); v[o,v[o,0]]:=k; exit;end;
  if (o and p[i+1]=0)and(o and p[i+2]=0) then dfs(i+2,k,o);
  if o and p[i+1]=0 then dfs(i+1,k xor p[i+1],o) else dfs(i+1,k,o);
end;
begin
  readln(n,m,l); c:=p[m+1]-1;
  fillchar(x,sizeof(x),0);
  for i:=0 to c do dfs(0,0,i);
  for i:=0 to c do
    for j:=1 to v[i,0]do begin x[v[i,j],i]:=1; end;
 { for i:=0 to c do                 begin
    for j:=1 to v[i,0] do write(v[i,j],' ');  writeln; end;

  for i:=0 to c do                   begin
    for j:=0 to c do write(x[i,j],' ');  writeln;end;}
  if n and 1=1 then begin y:=x;dec(n);end
               else for i:=0 to c do y[i,i]:=1;


  while n<>0 do
   begin
     if n and 1=1 then cheng(y,x);
      //if p<>1 then
     cheng(x,x);
     n:=n shr 1;
   end;
//  for i:=0 to c do   begin
//   for j:=0 to c do
 //   write(y[i,j],' ');  writeln;end;
 writeln(y[0,0] mod l);
  {
  //  for j:=0 to p[m+1]-1 do d[0,j]:=1;
 //d2[0]:=1;
  for i:=1 to v[0,0] do d1[v[0,i]]:=1;
  for i:=2 to n do
    if i mod 2=1 then
     begin
      fillchar(d1,sizeof(d1),0);
      for j:=0 to p[m+1]-1 do
       for k:=1 to v[j,0] do
         begin
           inc(d1[v[j,k]],d2[j]);
           d1[v[j,k]]:=d1[v[j,k]]mod l;
         end;
     end
    else
     begin
      fillchar(d2,sizeof(d2),0);
      for j:=0 to p[m+1]-1 do
        for k:=1 to v[j,0] do
          begin
           inc(d2[v[j,k]],d1[j]);
           d2[v[j,k]]:=d2[v[j,k]] mod l;
          end;
     end;

 if n mod 2=0 then writeln(d2[0]) else  writeln(d1[0]);

         }
 readln;
end.



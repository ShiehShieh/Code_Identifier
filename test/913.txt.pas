var
   v,w,sum:array[1..50]of longint;
   g:array[1..50,1..50]of boolean;
   u:array[1..50]of boolean;
   i,j,n,t,ans:longint; 

procedure dfs(last:longint;s:longint);
var
   i,j:longint;
   flag:boolean;
begin
   if s>ans then ans:=s;
   if s+sum[last+1]<ans then exit;
   for i:=last+1 to n do
   begin
       flag:=true;
       for j:=1 to last do
       if u[j] then
       if g[w[i],w[j]]then begin flag:=false;break;end;
       if not flag then continue;
       u[i]:=true;
       dfs(i,s+v[i]);
       u[i]:=false;
   end;
end;

begin
   readln(n);
   for i:=1 to n do begin w[i]:=i;read(v[i]);end;
   while not eof do
   begin
       readln(i,j);
       g[i,j]:=true;
       g[j,i]:=true;
   end;

   for i:=1 to n-1 do
   for j:=n downto i+1 do
   if v[j]>v[j-1] then
   begin
       t:=v[j];v[j]:=v[j-1];v[j-1]:=t;
       t:=w[j];w[j]:=w[j-1];w[j-1]:=t;
   end;
   sum[n]:=v[n];
   for i:=n-1 downto 1 do sum[i]:=sum[i+1]+v[i];

   dfs(0,0);
   writeln(ans);
end.

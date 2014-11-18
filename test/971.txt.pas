program vijos1139;
var cost:array[1..100,1..500]of longint;
    f,father:array[0..100,1..500]of int64;
    a,o,b:array[1..50000]of longint;
    m,n,i,j,best,num,k:longint;
    ans:int64;
function min(a,b:int64):int64;
begin
     if a<b then exit(a)
     else exit(b);
end;
procedure print(tot:longint);
begin
     if tot<best then
     begin
          a:=o;
          best:=tot;
     end;
end;
procedure search(x,deep,tot:longint);
begin
     inc(tot);
     o[tot]:=x;
     if deep<=1 then begin print(tot);exit;end;
     if deep<>1 then
       if f[deep-1,x]+cost[deep,x]=f[deep,x] then
       begin
            search(x,deep-1,tot);
            dec(tot);
       end;
     if x<>1 then
       if f[deep,x-1]+cost[deep,x]=f[deep,x] then
       begin
            search(x-1,deep,tot);
            dec(tot);
       end;
     if x<>n then
       if f[deep,x+1]+cost[deep,x]=f[deep,x] then
       begin
            search(x+1,deep,tot);
            dec(tot);
       end;
end;
begin
     readln(m,n);
     for i:=1 to m do
         for j:=1 to n do
         begin
              read(cost[i,j]);
         end;
     fillchar(f,sizeof(f),0);
     ans:=0; num:=1;
     for i:=1 to m do
     begin
          for j:=1 to n do
          begin
               f[i,j]:=f[i-1,j]+cost[i,j];
               father[i,j]:=j;
               if j<>1 then
               if f[i,j]>f[i,j-1]+cost[i,j] then
               begin
                    f[i,j]:=min(f[i,j],f[i,j-1]+cost[i,j]);
                    father[i,j]:=j-1;
               end;
          end;
          for j:=n-1 downto 1 do
          begin
               if f[i,j]>f[i,j+1]+cost[i,j] then
               begin
               f[i,j]:=min(f[i,j],f[i,j+1]+cost[i,j]);
               father[i,j]:=j+1;
               end;
          end;
     end;
     best:=1;
     for i:=1 to n do
     if f[m,i]<f[m,best]then best:=i;
     j:=m;
     i:=best;
     while j<>1 do
     begin
          inc(k);
          a[k]:=i;
          if i=father[j,i] then dec(j)
          else i:=father[j,i];
     end;
     inc(k);
     a[k]:=i;
     for i:=k downto 1 do writeln(a[i]);
end.


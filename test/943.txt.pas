var a:array[1..50000]of longint;
    i,n,m,p,x,y,fx,fy:longint;
////////////////////////////////////////////////////////////////////////////////
function getfather(x:longint):longint;
begin
     if a[x]=0 then exit(x)
               else
        begin
             a[x]:=getfather(a[x]);
             exit(a[x]);
        end;
end;
////////////////////////////////////////////////////////////////////////////////
begin
     readln (n,m,p);
     for i:=1 to m do
         begin
              readln (x,y);
              fx:=getfather(x);
              fy:=getfather(y);
              if fx<>fy then a[fx]:=fy;
         end;
     for i:=1 to p do
         begin
              readln (x,y);
              if getfather(x)=getfather(y) then writeln ('Yes')
                                           else writeln ('No');
         end;
end.

program vijos1034;
 var n,m,p,i,a,b,fx,fy:longint;
     father:array[0..5001]of integer;
function find(v:integer):integer;
begin
    if father[v]=v then find:=v
    else begin
    father[v]:=find(father[v]);
    find:=father[v];
    end;
end;
 begin
     readln(n,m,p);
     for i:=1 to n do father[i]:=i;
     for i:=1 to m do
     begin
         readln(a,b);
         fx:=find(a);
         fy:=find(b);
         father[fx]:=fy;
     end;
     for i:=1 to p do
     begin
         readln(a,b);
         fx:=find(a);
         fy:=find(b);
         if fx=fy then writeln('Yes') else writeln('No');
     end;
 end.                                      

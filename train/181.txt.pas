const w:array[1..12,1..2]of integer
      =((1,0),(-1,0),(0,-1),(0,1),(-1,-1),(1,1),(-1,1),(1,-1),(2,0),(0,2),(0,-2),(-2,0));
var t:array[1..100,1..100]of boolean;
    x,y:array[1..10000]of integer;
    n,m,head,tail,sum:integer;
////////////////////////////////////////////////////////////////////////////////
procedure init;
var s:string;
    i,j:integer;
begin
     readln (n,m);
     for i:=1 to n do
         begin
              readln (s);
              for j:=1 to m do t[i,j]:=s[j]='#';
         end;
end;
////////////////////////////////////////////////////////////////////////////////
procedure bfs(xx,yy:integer);
var i:integer;
begin
     x[1]:=xx; y[1]:=yy; tail:=1; head:=0; t[xx,yy]:=false; inc(sum);
     repeat
           inc(head);
           for i:=1 to 12 do
               begin
                    xx:=x[head]+w[i,1]; yy:=y[head]+w[i,2];
                    if (xx in [1..n])and(yy in [1..m])and(t[xx,yy]) then
                       begin
                            inc(tail);
                            x[tail]:=xx; y[tail]:=yy; t[xx,yy]:=false;
                       end;
               end;
     until head=tail;
end;
////////////////////////////////////////////////////////////////////////////////
procedure main;
var i,j:integer;
begin
     for i:=1 to n do
         for j:=1 to m do
             if t[i,j] then bfs(i,j);
end;
////////////////////////////////////////////////////////////////////////////////
begin
     init;
     main;
     writeln (sum);
end.                                                                            

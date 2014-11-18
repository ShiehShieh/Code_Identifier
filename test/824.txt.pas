program p1143;
const maxn=20;
      xxx:array[1..8] of integer=(0,0,0,0,-1,-1,-1,-1);
      yyy:array[1..8] of integer=(0,-1,0,-1,-1,0,-1,0);
      zzz:array[1..8] of integer=(0,-1,-1,0,-1,-1,0,0);
var a,b,c,d,e,f,n:longint;
    p:array[1..maxn,1..maxn] of integer;
    x:array[0..2*maxn,0..maxn,0..maxn,0..maxn] of longint;
function min(a,b:longint):longint;
begin
   if a>b then min:=b
   else min:=a;
end;
function max(a,b:longint):longint;
begin
   if a>b then max:=a
   else max:=b;
end;
procedure init;
begin

   readln(n);
   for a:=1 to n do
   begin
       for b:=1 to n do
           read(p[a,b]);
       readln;
   end;

end;
begin
   init;
   x[1,1,1,1]:=p[1,1];
   for a:=2 to 2*n-1 do
   begin
      for b:=max(1,a-n+1) to min(n,a) do
      begin
         for c:=max(1,a-n+1) to min(n,a) do
         begin
            for d:=max(1,a-n+1) to min(n,a) do
            begin
               e:=p[b,a-b+1]+p[c,a-c+1]+p[d,a-d+1];
               if (c=d) and (b=c) then e:=e div 3
               else if (c=b) or (c=d) then
                       e:=e-p[c,a-c+1]
                    else if b=d then
                         e:=e-p[b,a-b+1];
               for f:=1 to 8 do
               begin
                  x[a,b,c,d]:=max(x[a,b,c,d],x[a-1,b+xxx[f],c+yyy[f],d+zzz[f]]);
               end;
               x[a,b,c,d]:=x[a,b,c,d]+e;
            end;
         end;
      end;
   end;
   writeln(x[2*n-1,n,n,n]);
end.

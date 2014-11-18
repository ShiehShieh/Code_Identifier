const
 dx:array[1..8] of integer=(-1,-2,-2,-1,1,2,2,1);
 dy:array[1..8] of integer=(2,1,-1,-2,-2,-1,1,2);
var
 p:array[-30..30,-30..30] of boolean;
 m,n,x1,y1,b,c:integer;
 ans:int64;
procedure dfs(x,y:integer);
 var i:integer;
 begin
    if (x>n) or (y>m) then exit;
      if (x=n) and (y=m) then inc(ans)
     else
       begin
         if (x<n)and(p[x+1,y]=false) then dfs(x+1,y);
        if (y<m)and(p[x,y+1]=false) then dfs(x,y+1);
    end;
 end;
begin
 readln(n,m,x1,y1);
 p[x1,y1]:=true;
 for b:=1 to 8 do
     if (x1+dx[b]>=0)and(x1+dx[b]<=n)and(y1+dy[b]>=0)and(y1+dy[b]<=m)
      then p[x1+dx[b],y1+dy[b]]:=true;
 dfs(0,0);
 writeln(ans);
end.


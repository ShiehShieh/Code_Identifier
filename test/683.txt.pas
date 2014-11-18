const
  nn=100;
type
  int=longint;
var
  sky:array[1..nn,1..nn] of boolean;
  n,m:int; ans:int;
procedure init;
var i,j:int;
    t:char;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      read(t);
      sky[i,j]:=(t='#');
    end;
    readln;
  end;
end;

procedure floodfill;
var vis:array[-1..nn+2,-1..nn+2] of boolean;
    i,j:int;
  procedure bfs(xu,yu:int);
  var qx,qy:array[1..nn*nn] of int;
      dx,dy:int; h,t:int;
      xv,yv:int;
  begin
    vis[xu,yu]:=true;
    qx[1]:=xu; qy[1]:=yu;
    h:=1; t:=2;

    while h<t do begin
      xu:=qx[h]; yu:=qy[h];
      for dx:=-2 to 2 do
        for dy:=-(2-abs(dx)) to 2-abs(dx) do
        begin
          xv:=xu+dx; yv:=yu+dy;
          if not vis[xv,yv] and sky[xv,yv] then begin
            vis[xv,yv]:=true;
            qx[t]:=xv; qy[t]:=yv;
            inc(t);
          end;
        end;
      inc(h);
    end;
  end;
    
begin
  fillchar(vis,sizeof(vis),false);
  for i:=1 to n do
  begin
    vis[i,-1]:=true;vis[i,0]:=true;
    vis[i,m+1]:=true;vis[i,m+2]:=true;
  end;
  for i:=1 to m do
  begin
    vis[-1,i]:=true;vis[0,i]:=true;
    vis[n+1,i]:=true;vis[n+2,i]:=true;
  end;
  vis[0,0]:=true; vis[0,m+1]:=true;
  vis[n+1,0]:=true; vis[n+1,m+1]:=true;

  
  for i:=1 to n do
    for j:=1 to m do
      if not vis[i,j] and sky[i,j] then begin
        bfs(i,j);
        inc(ans);
      end;
end;

begin
  init;floodfill;
  writeln(ans);
  //readln(n);
end.     

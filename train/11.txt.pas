type
  rec=record
    no:integer;
    w:integer;
  end;
var
  i,j,k,w,n:integer;
  f:array[1..30] of rec;
  tmp:rec;
  tw,max:integer;
  b,s:array[1..30] of 0..1;

procedure find(a,c:integer);
var
  k:integer;
begin
  s[a]:=c;
  tw:=tw+f[a].w*c;
  if tw<=w then
    begin
      if a=n then {如果所有的货物已经搜索}
        begin
          if tw>max then
            begin
              for k:=1 to n do
                b[k]:=s[k];
              max:=tw;
            end
        end
      else {如果还没搜索完}
        begin
          find(a+1,1);
          find(a+1,0);
        end;
    end;
  tw:=tw-f[a].w*c;{a物品不能装车}
end;

procedure sort;
begin
  for i:=1 to n-1 do
    begin
      k:=i;
      for j:=i+1 to n do
        if f[k].w<f[j].w then k:=j;
      if k<>i then
        begin
          tmp:=f[i];
          f[i]:=f[k];
          f[k]:=tmp
        end;
    end;
end;

begin
  readln(w);
  readln(n);
  for i:=1 to n do
    begin
      f[i].no:=i;
      read(f[i].w);
    end;
  sort;
  max:=0;tw:=0;
  fillchar(b,sizeof(b),0);
  fillchar(s,sizeof(s),0);
  find(1,1);
  find(1,0);
  writeln(w-max);
  
end.


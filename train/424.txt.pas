program Vijos_P1126;
type
  re=record
    l,r,d,u,s:longint;
  end;
  arraytype=array[1..4] of re;
var
  x,y:array[1..50] of longint;
  rec:arraytype;
  n,k,i,ans:longint;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
  end;

function max(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;

function cal(var rec:arraytype):longint;
  var
    total,i:longint;
  begin
    total:=0;
    for i:=1 to k do
      total:=total+rec[i].s;
    cal:=total;
  end;

function check(var rec:arraytype;i:longint):boolean;
  var
    j,minx,maxx,miny,maxy:longint;
  begin
    check:=true;
    for j:=1 to k do
      if i<>j then
        begin
          minx:=max(rec[i].l,rec[j].l);
          maxx:=min(rec[i].r,rec[j].r);
          miny:=max(rec[i].d,rec[j].d);
          maxy:=min(rec[i].u,rec[j].u);
          if (minx<=maxx) and (miny<=maxy) then exit(false);
        end;
  end;

procedure search(i,total:longint);
  var
    j,ts:longint;
    backup:arraytype;
  begin
    if i>n then
      begin
        ans:=total;
        exit;
      end;
    for j:=1 to k do
      begin
        backup:=rec;
        if x[i]<rec[j].l then rec[j].l:=x[i];
        if x[i]>rec[j].r then rec[j].r:=x[i];
        if y[i]<rec[j].d then rec[j].d:=y[i];
        if y[i]>rec[j].u then rec[j].u:=y[i];
        rec[j].s:=(rec[j].r-rec[j].l)*(rec[j].u-rec[j].d);
        if check(rec,j) then
          begin
            ts:=cal(rec);
            if ts<ans then
              search(i+1,ts);
          end;
        rec:=backup;
      end;
  end;

begin
  readln(n,k);
  for i:=1 to n do
    readln(x[i],y[i]);
  for i:=1 to k do
    begin
      rec[i].l:=maxlongint;
      rec[i].r:=-maxlongint;
      rec[i].d:=maxlongint;
      rec[i].u:=-maxlongint;
      rec[i].s:=0;
    end;
  ans:=maxlongint;
  search(1,0);
  writeln(ans);
end.



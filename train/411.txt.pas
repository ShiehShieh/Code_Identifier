program Vijos_P1101;
type
  pointer=^node;
  node=record
    data:longint;
    flag:boolean;
    next:pointer;
  end;
  re=record
    data:longint;
    flag:boolean;
  end;
  arraytype=array[1..300] of re;
var
  ge:array[1..300] of pointer;
  v:array[1..300] of boolean;
  queue:arraytype;
  n,p,i,a,b,min:longint;

procedure insert(a,b:longint);
  var
    p:pointer;
  begin
    new(p);
    p^.data:=b;
    p^.next:=ge[a];
    p^.flag:=true;
    ge[a]:=p;
  end;

procedure make_tree(i:longint);
  var
    p:pointer;
  begin
    v[i]:=true;
    p:=ge[i];
    while p<>nil do
      begin
        if not v[p^.data] then
          make_tree(p^.data)
        else
          p^.flag:=false;
        p:=p^.next;
      end;
  end;

procedure search(len,total:longint);
  var
    tmp,backup:arraytype;
    count,i:longint;
    p:pointer;
  begin
    count:=0;
    for i:=1 to len do
      if queue[i].flag then
        begin
          p:=ge[queue[i].data];
          while p<>nil do
            begin
              if p^.flag then
                begin
                  inc(count);
                  tmp[count].data:=p^.data;
                  tmp[count].flag:=true;
                end;
              p:=p^.next;
            end;
        end;
    if count=0 then
      begin
        if total<min then min:=total;
        exit;
      end;
    backup:=queue;
    queue:=tmp;
    for i:=1 to count do
      begin
        queue[i].flag:=false;
        if total+count-1<min then
          search(count,total+count-1);
        queue[i].flag:=true;
      end;
    queue:=backup;
  end;

begin
  readln(n,p);
  for i:=1 to n do
    ge[i]:=nil;
  for i:=1 to p do
    begin
      readln(a,b);
      insert(a,b);
      insert(b,a);
    end;
  fillchar(v,sizeof(v),false);
  make_tree(1);
  min:=maxlongint;
  queue[1].data:=1;
  queue[1].flag:=true;
  search(1,1);
  writeln(min);
end.



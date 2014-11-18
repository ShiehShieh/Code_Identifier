{
PROB:Lions
LANG:PASCAL
ID:boyzkk
}
type
  link=^node;
  node=record
    v,dep,sum:longint;
    p,l,r:link;
  end;
var
  i,j,k,n,m:longint;
  x,y,rank,ans,order:array [1..50000] of longint;
  root:link;
  vl:array [1..100000] of longint;

function max(x,y:longint):longint;
  begin
    if x>y then max:=x else max:=y;
  end;

function min(x,y:longint):longint;
  begin
    if x>y then min:=y else min:=x;
  end;

function balance(x:link):boolean;
  var
    lc,rc:longint;
  begin
    if x^.l<>nil then lc:=x^.l^.dep else lc:=0;
    if x^.r<>nil then rc:=x^.r^.dep else rc:=0;
    if abs(lc-rc)<2 then exit(true) else exit(false);
  end;

function h(x:link):longint;
  begin
    if x=nil then exit(0) else exit(x^.dep);
  end;

function num(x:link):longint;
  begin
    if x=nil then exit(0) else exit(x^.sum);
  end;

function find(t:link; x:longint):longint;
  var
    k:longint;
  begin
    k:=num(t^.l)+1;
    if k=x then exit(t^.v);
    if k>x then exit(find(t^.l,x));
    exit(find(t^.r,x-k));
  end;

procedure exchange(var x,y:longint);
  var
    temp:longint;
  begin
    temp:=x; x:=y; y:=temp;
  end;

procedure total(x:link);
  begin
    x^.sum:=num(x^.l)+num(x^.r)+1;
    x^.dep:=max(h(x^.l),h(x^.r))+1;
  end;

procedure l_turn(x,y:link);
  begin
    y^.p:=x^.p;
    if x^.p^.l=x then x^.p^.l:=y else x^.p^.r:=y;
    x^.r:=y^.l;
    if y^.l<>nil then y^.l^.p:=x;
    y^.l:=x;
    x^.p:=y;
    total(x);
    total(y);
  end;

procedure r_turn(x,y:link);
  begin
    y^.p:=x^.p;
    if x^.p^.l=x then x^.p^.l:=y else x^.p^.r:=y;
    x^.l:=y^.r;
    if y^.r<>nil then y^.r^.p:=x;
    y^.r:=x;
    x^.p:=y;
    total(x);
    total(y);
  end;

procedure qsort(h,t:longint);
  var
    i,j,k:longint;
  begin
    if h>=t then exit;
    i:=h; j:=t; k:=x[(i+j) shr 1];
    repeat
      while x[i]<k do inc(i);
      while x[j]>k do dec(j);
      if i<=j then begin
        exchange(rank[i],rank[j]);
        exchange(x[i],x[j]);
        exchange(y[i],y[j]);
        exchange(order[i],order[j]);
        inc(i);
        dec(j);
      end;
    until i>j;
    qsort(i,t);
    qsort(h,j);
  end;

procedure qsortback(h,t:longint);
  var
    i,j,k:longint;
  begin
    if h>=t then exit;
    i:=h; j:=t; k:=order[(i+j) shr 1];
    repeat
      while order[i]<k do inc(i);
      while order[j]>k do dec(j);
      if i<=j then begin
        exchange(order[i],order[j]);
        exchange(ans[i],ans[j]);
        inc(i);
        dec(j);
      end;
    until i>j;
    qsortback(i,t);
    qsortback(h,j);
  end;

procedure insert(x:longint);
  var
    lv,lp:link;
  begin
    lv:=root;
    while lv<>nil do begin
      lp:=lv;
      inc(lp^.sum);
      if lv^.v>x then lv:=lv^.l else lv:=lv^.r;
    end;
    new(lv);
    with lv^ do begin v:=x; l:=nil; r:=nil; p:=lp; dep:=1; sum:=1; end;
    if lp^.v>x then lp^.l:=lv else lp^.r:=lv;
    while lv<>root^.r do begin
      lp:=lv^.p;
      lp^.dep:=max(h(lp^.l),h(lp^.r))+1;
      if balance(lp) then begin lv:=lp; continue; end;
      if lv=lp^.l then begin
        if h(lv^.r)>h(lv^.l) then l_turn(lv,lv^.r);
        lv:=lp^.l;
        r_turn(lp,lv);
      end
      else begin
        if h(lv^.l)>h(lv^.r) then r_turn(lv,lv^.l);
        lv:=lp^.r;
        l_turn(lp,lv);
      end;
    end;
  end;

procedure remove(x:longint);
  var
    lv,lp:link;
  begin
    lv:=root^.r;
    while lv^.v<>x do if lv^.v>x then lv:=lv^.l else lv:=lv^.r;
    if lv^.r<>nil then begin
      lp:=lv;
      lv:=lv^.r;
      while lv^.l<>nil do lv:=lv^.l;
      lp^.v:=lv^.v;
      lp:=lv^.p;
      if lv^.r<>nil then begin
        lv^.r^.p:=lp;
        if lp^.l=lv then lp^.l:=lv^.r else lp^.r:=lv^.r;
      end
      else if lp^.l=lv then lp^.l:=nil else lp^.r:=nil;
    end
    else if lv^.l<>nil then begin
      lp:=lv^.p;
      if lp^.l=lv then lp^.l:=lv^.l else lp^.r:=lv^.l;
      lv^.l^.p:=lp;
    end
    else begin
      lp:=lv^.p;
      if lp^.l=lv then lp^.l:=nil else lp^.r:=nil;
    end;
    lp:=lv^.p;
    dispose(lv);
    lv:=lp;
    while lp<>root do begin
      dec(lp^.sum);
      lp:=lp^.p;
    end;
    lp:=lv;
    if lp=root then exit;
    while lp<>root^.r do begin
      lp^.dep:=max(h(lp^.l),h(lp^.r))+1;
      if balance(lp) then begin lp:=lp^.p; continue; end;
      if h(lp^.r)>h(lp^.l) then begin
        lv:=lp^.r;
        if h(lv^.l)>h(lv^.r) then r_turn(lv,lv^.l);
        lv:=lp^.r;
        l_turn(lp,lv);
      end
      else begin
        lv:=lp^.l;
        if h(lv^.r)>h(lv^.l) then l_turn(lv,lv^.r);
        lv:=lp^.l;
        r_turn(lp,lv);
      end;
    end;
  end;

begin
  readln(n,m);
  for i:=1 to n do read(vl[i]);
  for i:=1 to m do begin
    order[i]:=i;
    readln(x[i],y[i],rank[i]);
    if x[i]>y[i] then exchange(x[i],y[i]);
  end;
  qsort(1,m);
  new(root);
  with root^ do begin v:=-maxlongint; p:=nil; l:=nil; r:=nil; end;
  for i:=x[1] to y[1] do insert(vl[i]);
  ans[1]:=find(root^.r,rank[1]);
  for i:=2 to m do begin
    for j:=x[i-1] to min(x[i]-1,y[i-1]) do remove(vl[j]);
    for j:=max(x[i],y[i-1]+1) to y[i] do insert(vl[j]);
    ans[i]:=find(root^.r,rank[i]);
  end;
  qsortback(1,m);
  for i:=1 to m do write(ans[i]);
end.


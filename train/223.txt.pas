{ DRZmm }
program vijos_LittleWhileAroundThePark;
const
  maxn=2000000;
type
  treenode=record
    mr,ml,m,s:longint;
  end;
var
  ans,sum,n,m,num,p,s,last,last2:longint;
  o:array[1..maxn]of integer;
  link:array[1..maxn]of longint;
  tree:array[1..2*maxn]of treenode;
function max(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;
procedure build(node,l,r:longint);
  var
    x,k1,k2,temp:longint;
  begin
    if l=r then
      begin
        read(temp);
        inc(num)  ;
//        o[num]:=temp;
        link[num]:=node;
        tree[node].ml:=temp;  tree[node].mr:=temp;
        tree[node].m:=temp;  tree[node].s:=temp;
        exit;
      end;
    k1:=node*2;
    k2:=node*2+1;
    build(k1,l,(l+r)shr 1);
    build(k2,(l+r)shr 1 + 1,r);
    tree[node].s:=tree[k1].s+tree[k2].s;
    tree[node].ml:=max(tree[k1].ml,tree[k1].s+tree[k2].ml);
    tree[node].mr:=max(tree[k2].mr,tree[k2].s+tree[k1].mr);
    tree[node].m:=max(max(tree[k1].m,tree[k2].m),tree[k1].mr+tree[k2].ml);
  end;
procedure update(node:longint);
  var
    k1,k2:longint;
  begin
    if node=0 then exit;
    k1:=node*2;
    k2:=node*2+1;
    tree[node].s:=tree[k1].s+tree[k2].s;
    tree[node].ml:=max(tree[k1].ml,tree[k1].s+tree[k2].ml);
    tree[node].mr:=max(tree[k2].mr,tree[k2].s+tree[k1].mr);
    tree[node].m:=max(max(tree[k1].m,tree[k2].m),tree[k1].mr+tree[k2].ml);
    update(node shr 1);
  end;
procedure ask(node,l,r:longint);
  begin
    if (l>=p) and (r<=s) then
      begin
        ans:=max (tree[node].m , sum+tree[node].ml) ;
        if ans>last then last:=ans;
        sum:=max (tree[node].mr, sum+tree[node].s ) ;
        exit;
      end;
    if  p<=(l+r)shr 1      then  ask(node*2,l,(l+r)shr 1);
    if  s>=(l+r)shr 1 + 1  then  ask(node*2+1,(l+r)shr 1+1,r);
  end;
{function dp:longint;
  var  i:longint;
  begin
    dp:=0;
    for i:=p to s do
      begin
        dp:=max(dp+o[i],o[i]);
        if dp>last2 then last2:=dp;
      end;
  end;}
procedure main;
  var
    i , k , temp : longint;
  begin
    num:=0;
    readln(n , m) ;
    build (1 , 1 , n) ;
    for i:=1 to m do
      begin
        readln(k,p,s);
        if k=2 then
          begin
//            o[p]:=s;
            temp:=link[p];
            tree[temp].s := s ;    tree[temp].mr:= s ;
            tree[temp].ml:= s ;    tree[temp].m := s ;
            update(temp shr 1);
          end
        else
          begin
            if p>s then begin temp:=p; p:=s; s:=temp; end;
            sum  := 0           ;
            ans  := 0           ;
            last := -maxlongint ;
            ask(1,1,n)          ;
            write(last,' ')     ;
          //  last2:=-maxlongint;
          //  dp;
          //  write(last2);
          end;
      end;
     writeln;
  end;
begin
  main;
end.

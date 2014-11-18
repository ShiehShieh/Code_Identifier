program Vijos_P1081;
type
  node=record
    data,weight,no,count:longint;
    left,right,pre:longint;
  end;
  re=record
    data,flag:longint;
  end;
var
  a,locate:array[1..100000] of longint;
  stack:array[1..100000] of re;
  tree:array[0..100000] of node;
  h,t,k,no,ans:array[1..100000] of longint;
  total,kth,n,m,root,tail:longint;
  finish:boolean;

procedure swap(var a,b:longint);
  var
    t:longint;
  begin
    t:=a;
    a:=b;
    b:=t;
  end;

procedure qsort(head,tail:longint);
  var
    i,j,mid,p:longint;
  begin
    i:=head;
    j:=tail;
    mid:=h[(i+j) div 2];
    repeat
      while h[i]<mid do inc(i);
      while h[j]>mid do dec(j);
      if i<=j then
        begin
          swap(h[i],h[j]);
          swap(t[i],t[j]);
          swap(k[i],k[j]);
          swap(no[i],no[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if head<j then qsort(head,j);
    if i<tail then qsort(i,tail);
  end;


procedure left_rotate(x,y,a,b,c:longint);
  begin
    if tree[y].pre>0 then
      if tree[tree[y].pre].left=y then
        tree[tree[y].pre].left:=x
      else
        tree[tree[y].pre].right:=x;
    tree[x].pre:=tree[y].pre;
    tree[x].right:=y;
    tree[y].pre:=x;
    tree[y].left:=b;
    if b>0 then
      tree[b].pre:=y;
    tree[y].count:=tree[b].count+tree[c].count+1;
    tree[x].count:=tree[y].count+tree[a].count+1;
  end;

procedure right_rotate(x,y,a,b,c:longint);
  begin
    if tree[y].pre>0 then
      if tree[tree[y].pre].left=y then
        tree[tree[y].pre].left:=x
      else
        tree[tree[y].pre].right:=x;
    tree[x].pre:=tree[y].pre;
    tree[x].left:=y;
    tree[y].pre:=x;
    tree[y].right:=b;
    if b>0 then
      tree[b].pre:=y;
    tree[y].count:=tree[b].count+tree[a].count+1;
    tree[x].count:=tree[y].count+tree[c].count+1;
  end;

procedure insert(head,t:longint);
  var
    p,q:longint;
  begin
    if root=0 then
      begin
        root:=t;
        tree[t].pre:=0;
        exit;
      end;
    p:=head;
    q:=0;
    while p<>0 do
      begin
        q:=p;
        if tree[p].data>tree[t].data then
          p:=tree[p].left
        else
          p:=tree[p].right;
      end;
    if tree[q].data>tree[t].data then
      tree[q].left:=t
    else
      tree[q].right:=t;
    p:=q;
    while p<>0 do
      begin
        tree[p].count:=tree[p].count+tree[t].count;
        p:=tree[p].pre;
      end;
    tree[t].pre:=q;
    p:=q;
    while (p<>0) and (tree[t].weight<tree[p].weight) do
      begin
        if t=tree[p].left then
          left_rotate(t,p,tree[t].left,tree[t].right,tree[p].right)
        else
          right_rotate(t,p,tree[p].left,tree[t].left,tree[t].right);
	if p=root then root:=t;
        p:=tree[t].pre;
      end;
  end;

procedure del(p:longint);
  var
    t:longint;
  begin
    begin
      if p<>root then
        begin
          if tree[tree[p].pre].left=p then
            tree[tree[p].pre].left:=0
          else
            tree[tree[p].pre].right:=0;
          t:=tree[p].pre;
          while t<>0 do
            begin
              dec(tree[t].count,tree[p].count);
              t:=tree[t].pre;
            end;
        end
      else
        root:=0;
      if tree[p].left<>0 then
        insert(root,tree[p].left);
      if tree[p].right<>0 then
        insert(root,tree[p].right);
    end;
  end;

function find(k:longint):longint;
  var
    l,r,i,tmp:longint;
  begin
    i:=root;
    tmp:=k;
    while true do
      begin
        l:=tree[i].left;
        r:=tree[i].right;
        if tmp<=tree[l].count then
          i:=l
        else
          if tree[l].count+1=tmp then
            exit(tree[i].data)
          else
            begin
              i:=r;
              tmp:=tmp-tree[l].count-1;
            end;
      end;
  end;

procedure init;
  var
    i:longint;
  begin
    read(n,m);
    for i:=1 to n do
      read(a[i]);
    for i:=1 to m do
      begin
        read(h[i],t[i],k[i]);
        no[i]:=i;
      end;
  end;

procedure work;
  var
    i,j,tmp:longint;
    p:node;
  begin
    randomize;
    qsort(1,m);
    root:=0;
    tail:=0;
    tree[0].count:=0;
    for i:=1 to m do
      begin
        if i>1 then
          begin
            if t[i-1]<h[i]-1 then
              tmp:=t[i-1]
            else
              tmp:=h[i]-1;
            for j:=h[i-1] to tmp do
              del(locate[j]);
          end;
        if i=1 then
          tmp:=h[i]
        else
          if t[i-1]+1>h[i] then
            tmp:=t[i-1]+1
          else
            tmp:=h[i];
        for j:=tmp to t[i] do
          begin
            p.data:=a[j];
            p.weight:=random(maxlongint);
            p.no:=j;
            p.left:=0;
            p.right:=0;
            p.count:=1;
            inc(tail);
            tree[tail]:=p;
            locate[j]:=tail;
            insert(root,tail);
          end;
        ans[no[i]]:=find(k[i]);
      end;
  end;

procedure print;
  var
    i:longint;
  begin
    for i:=1 to m do
      write(ans[i],' ');
  end;

begin
  init;
  work;
  print;
end.


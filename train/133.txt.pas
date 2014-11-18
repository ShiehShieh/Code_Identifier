program project1;
  var l,r,lch,rch,big:array[1..410000]of longint;
      data:array[1..200010]of longint;
      n,m,i,tot,a,b,ans:longint;
  function max(a,b:longint):longint;
    begin
      if a>b
        then exit(a)
        else exit(b);
    end;
  procedure buildtree(a,b:longint);
    var now:longint;
    begin
      inc(tot);
      now:=tot;
      l[now]:=a;
      r[now]:=b;
      if a<b
        then begin
          lch[now]:=tot+1;
          buildtree(a,(a+b)shr 1);
          rch[now]:=tot+1;
          buildtree((a+b)shr 1+1,b);
          big[now]:=max(big[lch[now]],big[rch[now]]);
        end;
      if a=b
        then big[now]:=data[a];
    end;
  function query(n,a,b:longint):longint;
    begin
      query:=-maxlongint;
      if(l[n]>=a)and(r[n]<=b)
        then exit(big[n]);
      if a<=r[lch[n]]
        then query:=max(query,query(lch[n],a,b));
      if b>=l[rch[n]]
        then query:=max(query,query(rch[n],a,b));
    end;
  begin
    fillchar(l,sizeof(l),0);
    fillchar(r,sizeof(r),0);
    fillchar(lch,sizeof(lch),0);
    fillchar(rch,sizeof(rch),0);
    fillchar(big,sizeof(big),0);
    fillchar(data,sizeof(data),0);
    readln(n);
    for i:=1 to n do
      read(data[i]);
    tot:=0;
    buildtree(1,n);
    readln(m);
    for i:=1 to m do
      begin
        readln(a,b);
        ans:=query(1,a,b);
        write(ans);
      end;
  end.

'use client'
import {ReactNode, useEffect, useState} from "react";

interface FeedLayoutProps {
  children: ReactNode;
}

export default function FeedLayout(props: FeedLayoutProps) {
  const { children } = props;

  const [status, setStatus] = useState('mounting...');

  // 클라이언트 컴포넌트 이더라도 리렌더링 되지 않는다.
  useEffect(() => {
    setTimeout(() => {
      setStatus('mounted.');
    }, 1000);
  }, []);

  return (
    <div className='box layout'>
      <h4>{`FeedLayout: ${status}`}</h4>
      <div style={{padding: 8}}>{children}</div>
    </div>
  )
}
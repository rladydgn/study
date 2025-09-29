// http://localhost:3000 로 접근 할 때와, http://localhost:3000 에서 Link 로 라우팅 하여 이동할 때만 노출된다.
// Link 로 이동한 뒤 새고로침 할 경우 http://localhost:3000 가 아니라면 default.tsx 가 노출된다.
export default function TrendsPage() {
  return <div className='box slot-1'>Trends Slot</div>
}
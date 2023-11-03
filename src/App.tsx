import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import { Routes, Route, Navigate } from 'react-router-dom';
import RedirectPage from './pages/redirectPage';
import ErrorPage from './pages/errorPage';

// import AListLib from '../public/source/AListLib.c';

const HelloWorld = () => {
  const [count, setCount] = useState(0)

  return (
    <>
      <div>
        <a href="https://vitejs.dev" target="_blank">
          <img src={viteLogo} className="logo" alt="Vite logo" />
        </a>
        <a href="https://react.dev" target="_blank">
          <img src={reactLogo} className="logo react" alt="React logo" />
        </a>
      </div>
      <h1>Trần Thái Toàn</h1>
      <div className="card">
        <button onClick={() => setCount((count) => count + 1)}>
          count is {count}
        </button>
      </div>
      <p className="read-the-docs">
        Click on the Vite and React logos to learn more
      </p>
    </>
  )
}

function App() {
  return (
    <Routes>
      <Route path='/' element={<HelloWorld />} />
      <Route path='/redirect'>
        <Route path=':redirectId' element={<RedirectPage />} />
      </Route>
      {/* <Route path="/404" element={<ErrorPage />} /> */}
      <Route path="*" element={<ErrorPage />} />
    </Routes>
  )
}

export default App

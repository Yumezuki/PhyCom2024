import React from 'react';
//Part CSS

const LoginPage: React.FC = () => {
  //กล่อง Container ตรงกลาง(กล่องนอก)
  const containerStyle = {
    display: 'flex',
    flexDirection: 'column',
    alignItems: 'center',
    justifyContent: 'center',
    height: '100vh',
    backgroundColor: '#1a73e8'
  };
  const formStyle = {
    display: 'flex',
    flexDirection: 'column',
    backgroundColor: 'white',
    padding: '40px',
    borderRadius: '8px',
    boxShadow: '0 4px 8px rgba(0,0,0,0.2)',
    width: '600px',
    textAlign: 'left',
    color: 'black',
    position: 'relative'
  };
  //text welcome
  const welcomeStyle = {
    margin: 0,
    fontSize: '32px', 
    fontWeight: 'bold' 
  };
  //text or ทำให้มันอยู่ตรงกลาง
  const or ={
    textAlign: 'center',
    color: 'gray',
    margin: '5px 0'
  };
  //text header ด้าน บน 2 คำ พวก welcome กับ sign in with kmitl
  const headerStyle = {
    marginBottom: '40px', 
    textAlign: 'left' 
  };
  //กล่องContainer ด้านใน
  const inputContainerStyle = {
    display: 'flex',
    flexDirection: 'column',
    backgroundColor: 'white', 
    padding: '20px',
    borderRadius: '8px',
    marginBottom: '20px',
    border: '1px solid rgba(0, 0, 0, 0.1)', // Add black border
    
  };
  //text ด้านในกล่องใน
  const inputLabelStyle = {
    marginBottom: '5px',
    fontSize: '14px',
    fontWeight: 'bold'
  };
  const inputStyle = {
    marginBottom: '15px',
    padding: '10px',
    fontSize: '16px',
    borderRadius: '4px',
    border: '1px solid #ccc',
    width: '100%'
  };
  //ปุ่ม
  const buttonStyle = {
    backgroundColor: '#1a73e8',
    color: 'white',
    padding: '10px',
    fontSize: '16px',
    border: 'none',
    borderRadius: '4px',
    cursor: 'pointer',
    marginBottom: '10px',
  };
  //google
  const googleButtonStyle = {
    ...buttonStyle,
    backgroundColor: 'white',
    color: 'black',
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'center',
    border: '1px solid #ccc',
  };

  return (
    //html part
    <div style={containerStyle}>
      <div style={formStyle}>
        <div style={headerStyle}>
        <h1 style={welcomeStyle}>Welcome</h1>
          <p>Sign in with KMITL account Or ITKMITL account.</p>
        </div>
        <div style={inputContainerStyle}>
          <label style={inputLabelStyle}>Username</label>
          <input style={inputStyle} type="text" placeholder="Username" />
          <label style={inputLabelStyle}>Password</label>
          <input style={inputStyle} type="password" placeholder="Password" />
          <button style={buttonStyle}>Sign In</button>
        </div>

        <button style={googleButtonStyle}>
          <img src="https://img.icons8.com/color/16/000000/google-logo.png" alt="Google logo" style={{ marginRight: '8px' }} />
          Login
        </button>
      </div>
    </div>
  );
};

export default LoginPage;

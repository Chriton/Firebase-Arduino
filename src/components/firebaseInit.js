// firestore version
// import firebase from 'firebase'
// import 'firebase/firestore'
// import firebaseConfig from './firebaseConfig'
//
// const firebaseApp = firebase.initializeApp(firebaseConfig)
// export default firebaseApp.firestore()


//realtime database version
import firebase from 'firebase'
import 'firebase/database'
import firebaseConfig from './firebaseConfig'

const firebaseApp = firebase.initializeApp(firebaseConfig);
export default firebaseApp.database()

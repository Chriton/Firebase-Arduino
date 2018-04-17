<template>
  <v-container>
    <v-layout row wrap v-if="loading">
      <v-flex xs12 sm10 md8 offset-sm1 offset-md2 class="text-xs-center">
        <v-progress-circular
          indeterminate
          color="primary"
          :width="7"
          :size="70">
        </v-progress-circular>
      </v-flex>
      </v-layout>
    <v-layout  v-if="!loading">
      <v-flex xs12 sm10 md8 offset-sm1 offset-md2>
          <!--If the object is empty-->
          <v-card v-if="sensorData === null || sensorData === undefined">
            <v-container fluid>
              <v-layout row>
                <v-flex xs7 sm8 md9>
                  <v-card-title primary-title>
                    <div>
                      <h4>There is no sensor data available.</h4>
                    </div>
                  </v-card-title>
                </v-flex>
              </v-layout>
            </v-container>
          </v-card>
          <!--If the object is NOT empty-->
          <v-card class="mb-2" v-if="sensorData !== null || sensorData !== undefined"  v-for="(value, propertyName, index) in sensorData" v-bind:key="sensorData.index">
          <v-container fluid>
            <v-layout row>
              <v-flex xs5 sm4 md3>
                <v-card-media
                  :src="'http://via.placeholder.com/300x150?text=Image for '+propertyName"
                  height="130px">
                </v-card-media>
              </v-flex>
              <v-flex xs7 sm8 md9>
                <v-card-title primary-title>
                  <div>
                    <h5 class="headline mb-0 info--text" >{{ value }} </h5>
                    <div>{{ propertyName }}</div>
                  </div>
                </v-card-title>
                <v-card-actions>
                  <v-spacer></v-spacer>
                  <v-btn flat class="info">
                    <v-icon left light>arrow_forward</v-icon>View Sensor
                  </v-btn>
                </v-card-actions>
              </v-flex>
            </v-layout>
          </v-container>
        </v-card>
      </v-flex>
    </v-layout>
  </v-container>
</template>

<script>
  export default {
    name: "sensor",
    computed: {
      sensorData() {
        return this.$store.getters.sensorData
      },
      loading () {
        return this.$store.getters.loading
      }
    }
  }
</script>

<style scoped>

</style>
